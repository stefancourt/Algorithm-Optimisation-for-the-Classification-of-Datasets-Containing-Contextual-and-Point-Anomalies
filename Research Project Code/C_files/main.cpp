#include "OCSVM.hpp"
#include <iostream>
#include <vector>

int main() {
    // Example data: 100 points in 2D
    std::vector<std::vector<double>> data;
    for (int i = 0; i < 90; ++i) {
        data.push_back({double(i) / 10.0, double(i) / 20.0}); // Inliers
    }
    for (int i = 0; i < 10; ++i) {
        data.push_back({double(i) * 10.0, double(i) * 10.0}); // Outliers
    }

    // Initialize OCSVM
    OCSVM model(0.1, "rbf", 0.5);

    // Train the model
    model.fit(data);

    // Find the most likely inliers and outliers
    std::vector<std::vector<double>> inliers, outliers;
    model.find_inliers_and_outliers(data, 10, inliers, outliers);

    // Print results
    std::cout << "Most likely inliers:\n";
    for (const auto& inlier : inliers) {
        std::cout << "(" << inlier[0] << ", " << inlier[1] << ")\n";
    }

    std::cout << "\nMost likely outliers:\n";
    for (const auto& outlier : outliers) {
        std::cout << "(" << outlier[0] << ", " << outlier[1] << ")\n";
    }

    return 0;
}

