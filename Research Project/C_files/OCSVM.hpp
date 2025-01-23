#ifndef OCSVM_HPP
#define OCSVM_HPP

#include <vector>
#include <numeric>
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <random>
#include <string>
#include <algorithm>

class OCSVM {
private:
    // Parameters
    double nu;
    std::string kernel_type;
    double gamma;
    std::vector<double> alphas;
    std::vector<std::vector<double>> support_vectors;
    double rho;

    // Kernel functions
    double linear_kernel(const std::vector<double>& x1, const std::vector<double>& x2);
    double polynomial_kernel(const std::vector<double>& x1, const std::vector<double>& x2, double c = 1.0, double d = 2.0);
    double rbf_kernel(const std::vector<double>& x1, const std::vector<double>& x2);

    double kernel(const std::vector<double>& x1, const std::vector<double>& x2);

public:
    OCSVM(double nu = 0.1, const std::string& kernel = "rbf", double gamma = 1.0);

    // Methods
    void fit(const std::vector<std::vector<double>>& X);
    double decision_function(const std::vector<double>& x);
    int predict(const std::vector<double>& x);

    // Find inliers and outliers
    void find_inliers_and_outliers(const std::vector<std::vector<double>>& X, size_t N,
                                   std::vector<std::vector<double>>& inliers,
                                   std::vector<std::vector<double>>& outliers);
};

#endif // OCSVM_HPP
