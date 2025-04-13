#include "OCSVM.hpp"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

// Constructor
OCSVM::OCSVM(double nu_, const std::string& kernel_, double gamma_)
    : nu(nu_), kernel_type(kernel_), gamma(gamma_), rho(0.0) {}

// Linear Kernel
double OCSVM::linear_kernel(const std::vector<double>& x1, const std::vector<double>& x2) {
    double result = 0.0;
    for (size_t i = 0; i < x1.size(); ++i) {
        result += x1[i] * x2[i];
    }
    return result;
}

// Polynomial Kernel
double OCSVM::polynomial_kernel(const std::vector<double>& x1, const std::vector<double>& x2, double c, double d) {
    double result = linear_kernel(x1, x2) + c;
    return std::pow(result, d);
}

// RBF Kernel
double OCSVM::rbf_kernel(const std::vector<double>& x1, const std::vector<double>& x2) {
    double result = 0.0;
    for (size_t i = 0; i < x1.size(); ++i) {
        result += (x1[i] - x2[i]) * (x1[i] - x2[i]);
    }
    return std::exp(-gamma * result);
}

// Kernel Selector
double OCSVM::kernel(const std::vector<double>& x1, const std::vector<double>& x2) {
    if (kernel_type == "linear") {
        return linear_kernel(x1, x2);
    } else if (kernel_type == "polynomial") {
        return polynomial_kernel(x1, x2);
    } else if (kernel_type == "rbf") {
        return rbf_kernel(x1, x2);
    } else {
        throw std::invalid_argument("Unsupported kernel type");
    }
}

// Fit the Model
void OCSVM::fit(const std::vector<std::vector<double>>& X) {
    size_t n_samples = X.size();
    double C = 1.0 / (n_samples * nu);
    
    // Initialize alphas
    alphas.assign(n_samples, 0.0);

    for (size_t i = 0; i < n_samples; ++i) {
        for (size_t j = 0; j < n_samples; ++j) {
            alphas[i] += kernel(X[i], X[j]);
        }
        alphas[i] /= n_samples;
    }

    // Enforce nu-related constraints
    size_t n_support_vectors = static_cast<size_t>(nu * n_samples);
    std::vector<size_t> sorted_indices(n_samples);
    std::iota(sorted_indices.begin(), sorted_indices.end(), 0);

    // Sort alphas to pick top support vectors
    std::sort(sorted_indices.begin(), sorted_indices.end(),
              [&](size_t a, size_t b) { return alphas[a] > alphas[b]; });

    // Retain top nu*n_samples alphas as support vectors
    support_vectors.clear();
    for (size_t i = 0; i < n_support_vectors; ++i) {
        support_vectors.push_back(X[sorted_indices[i]]);
    }

    // Calculate rho based on the median of the support vector scores
    rho = 0.0;
    for (const auto& sv : support_vectors) {
        rho += decision_function(sv);
    }
    rho /= support_vectors.size();
}


// Decision Function
double OCSVM::decision_function(const std::vector<double>& x) {
    double result = 0.0;
    for (size_t i = 0; i < support_vectors.size(); ++i) {
        result += alphas[i] * kernel(support_vectors[i], x);
    }
    return result - rho;
}

// Predict
int OCSVM::predict(const std::vector<double>& x) {
    return decision_function(x) >= 0 ? 1 : -1;
}

// Find Inliers and Outliers
void OCSVM::find_inliers_and_outliers(const std::vector<std::vector<double>>& X, size_t N,
                                      std::vector<std::vector<double>>& inliers,
                                      std::vector<std::vector<double>>& outliers) {
    // Compute decision scores for all points
    std::vector<std::pair<double, std::vector<double>>> scores;
    for (const auto& x : X) {
        scores.push_back({decision_function(x), x});
    }

    // Sort scores in ascending order
    std::sort(scores.begin(), scores.end(),
              [](const std::pair<double, std::vector<double>>& a, const std::pair<double, std::vector<double>>& b) {
                  return a.first < b.first;
              });

    // Extract most likely outliers (lowest scores) and inliers (highest scores)
    outliers.clear();
    inliers.clear();
    for (size_t i = 0; i < N && i < scores.size(); ++i) {
        outliers.push_back(scores[i].second);
        inliers.push_back(scores[scores.size() - 1 - i].second);
    }
}

PYBIND11_MODULE(ocsvm, m) {
    py::class_<OCSVM>(m, "OCSVM")
        .def(py::init<double, const std::string&, double>(),
             py::arg("nu") = 0.1, py::arg("kernel") = "rbf", py::arg("gamma") = 1.0)
        .def("fit", &OCSVM::fit, "Train the OC-SVM model", py::arg("X"))
        .def("decision_function", &OCSVM::decision_function, "Compute the decision score for a point", py::arg("x"))
        .def("predict", &OCSVM::predict, "Predict if a point is an inlier (1) or outlier (-1)", py::arg("x"))
        .def("find_inliers_and_outliers", [](OCSVM& self, const std::vector<std::vector<double>>& X, size_t N) {
             std::vector<std::vector<double>> inliers, outliers;
             self.find_inliers_and_outliers(X, N, inliers, outliers);
             return std::make_pair(inliers, outliers);
         }, "Find the most likely inliers and outliers",
             py::arg("X"), py::arg("N"));
}
