//
// Created by Abhi Wangoo on 1/14/21.
//

#include "../include/gradient.h"

int main() {
    // Test to determine whether coefficients are calculated properly

    gradientDescent::gradient gradient;
    std::vector<double> x;
    std::vector<double> y;

    for (double i = 0; i < 5; i++)
    {
        x.push_back(i);
        y.push_back(i / 2 + 1);
    }

    gradient.determineMinimum(x, y);
    return 0;
}

void gradientDescent::gradient::determineMinimum(std::vector<double> x_values, std::vector<double> y_values) {
    double m = y_values.size();
    double max_iterations = 10000;
    double step_size = 1;
    size_t iterations = 0;

    while (iterations < max_iterations || step_size > percision_) {
        step_size = parameter_m;

        double temp_m = parameter_m - learning_rate_ * CostFunctionDerivative(x_values, y_values, m, false);
        double temp_b = parameter_b - learning_rate_ * CostFunctionDerivative(x_values, y_values, m, true);

        parameter_m = temp_m;
        parameter_b = temp_b;

        step_size = parameter_m - step_size;
        iterations++;
    }

    std::cout << "y = " << parameter_m << "x + " << parameter_b << std::endl;
}

double gradientDescent::gradient::CostFunctionDerivative(std::vector<double> &x_values, std::vector<double> &y_values,
                                                         double m, bool is_const) {
    double resultant = 0;

    for (size_t i = 0; i < m; i++) {
        if (!is_const) {
            resultant += ((Hypothesis(x_values[i]) - y_values[i]) * x_values[i]);
        } else {
            resultant += ((Hypothesis(x_values[i]) - y_values[i]));
        }
    }

    return resultant / m;
}

double gradientDescent::gradient::Hypothesis(double input) {
    return parameter_m * input + parameter_b;
}

