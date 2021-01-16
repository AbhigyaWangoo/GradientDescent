//
// Created by Abhi Wangoo on 1/14/21.
//

#include "../include/gradient.h"

int main() {
    // Test to determine whether coefficients are calculated properly
    gradientDescent::Gradient gradient;
    std::vector<double> x;
    std::vector<double> y;

    for (double i = 0; i < 5; i++)
    {
        x.push_back(i); // Change me to change x values
        y.push_back(i); // Change me to change y values
    }

    gradient.DetermineMinimum(x, y);
    return 0;
}

void gradientDescent::Gradient::DetermineMinimum(std::vector<double> x_values, std::vector<double> y_values) {
    double m = y_values.size();
    double max_iterations = 10000;
    double step_size = 1;
    size_t iterations = 0;

    while (iterations < max_iterations && step_size > kPrecision) {
        double temp_m = parameter_m_ - kLearningRate * CostFunctionDerivative(x_values, y_values, m, false);
        double temp_b = parameter_b_ - kLearningRate * CostFunctionDerivative(x_values, y_values, m, true);

        parameter_m_ = temp_m;
        parameter_b_ = temp_b;

        step_size = abs(parameter_m_ - step_size);
        iterations++;
    }

    std::cout << "y = " << parameter_m_ << "x + " << parameter_b_ << std::endl;
}

double gradientDescent::Gradient::CostFunctionDerivative(std::vector<double> &x_values, std::vector<double> &y_values,
                                                         double m, bool is_const) const {
    double resultant = 0;

    for (size_t i = 0; i < m; i++) {
        if (!is_const) {
            resultant += ((CalculateHypothesisOutput(x_values[i]) - y_values[i]) * x_values[i]);
        } else {
            resultant += ((CalculateHypothesisOutput(x_values[i]) - y_values[i]));
        }
    }

    return resultant / m;
}

double gradientDescent::Gradient::CalculateHypothesisOutput(double input) const {
    return parameter_m_ * input + parameter_b_;
}

