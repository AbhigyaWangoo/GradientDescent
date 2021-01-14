//
// Created by Abhi Wangoo on 1/14/21.
//

#include "../include/gradient.h"

int main() {
    gradientDescent::gradient gradient;
    std::vector<double> x;
    std::vector<double> y;

    for (double i = 1; i < 5; i++)
    {
        x.push_back(i);
        y.push_back(i / 2);
    }

    gradient.determineMinimum(x, y);
    return 0;
}

void gradientDescent::gradient::determineMinimum(std::vector<double> x_values, std::vector<double> y_values) {
    double parameter_m;
    double parameter_b;
    double m = y_values.size();
    double max_iterations = 10000;
    double step_size = 1;
    size_t iterations = 0;

    while (iterations < max_iterations && step_size > percision_) {
        step_size = parameter_m;
        parameter_m = parameter_m - learning_rate_ * CostFunctionDerivative(parameter_m, y_values, x_values, m);
        step_size = parameter_m - step_size;

        iterations++;
    }

    std::cout << parameter_m;
}

double gradientDescent::gradient::CostFunctionDerivative(double parameter_m, std::vector<double> &y_values, std::vector<double> &x_values, double m) {
    double resultant = 0;

    for (size_t i = 1; i < m; i++) {
        resultant += (1 / m) * (((parameter_m * x_values[i]) - y_values[i]) * x_values[i]);
    }

    return resultant;
}
