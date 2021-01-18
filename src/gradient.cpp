//
// Created by Abhi Wangoo on 1/14/21.
//

#include "../include/gradient.h"

int main() {
    // Test to determine whether coefficients are calculated properly
    gradientDescent::Gradient gradient;
    std::vector<double> x;
    std::vector<double> x2;
//    std::vector<double> x3;
    std::vector<double> y;
    std::vector<std::vector<double> > x_in;

    for (double i = 0; i < 5; i++)
    {
        x.push_back(i); // Change me to change x values
        x2.push_back(i / 2);
        y.push_back(i); // Change me to change y values
    }
    x_in.push_back(x);
    x_in.push_back(x2);

    gradient.DetermineMinimum(x_in, y);
    return 0;
}

void gradientDescent::Gradient::DetermineMinimum(std::vector<double> &x_values, std::vector<double> &y_values) {
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

void gradientDescent::Gradient::DetermineMinimum(std::vector<std::vector<double> > &x_values, std::vector<double> &y_values) {
    double m = y_values.size();
    double max_iterations = 10000;
    double step_size = 1;
    size_t iterations = 0;
    std::vector<double> temp_values;

    for (size_t i = 0; i < x_values.size(); i++) {
        parameters_.push_back(i);
    } // for parameters to be filled with baseline coefficients todo make this more efficient

    while (iterations < max_iterations && step_size > kPrecision) {
        for (size_t i = 0; i < x_values.size(); i++) {
            temp_values.push_back(parameters_[i] - kLearningRate * CostFunctionDerivative(x_values,y_values,m,i));
            step_size = abs(parameters_[i] - step_size);
        }

        parameters_.clear();

        for (size_t i = 0; i < x_values.size(); i++) {
            parameters_.push_back(temp_values[i]);
        }

        temp_values.clear();

        iterations++;
    }
}


double gradientDescent::Gradient::CostFunctionDerivative(std::vector<double> &x_values, std::vector<double> &y_values,
                                                         double m, bool is_const) const {
    double resultant = 0;

    for (size_t i = 0; i < m; i++) {
        if (!is_const) {
            resultant += ((CalculateHypothesisOutput(x_values[i], false) - y_values[i]) * x_values[i]);
        } else {
            resultant += ((CalculateHypothesisOutput(x_values[i], false) - y_values[i]));
        }
    }

    return resultant / m;
}

double gradientDescent::Gradient::CostFunctionDerivative(std::vector<std::vector<double> > &x_values,
                                                         std::vector<double> &y_values, double m, size_t parameter_count) const {
    double resultant = 0;

    for (size_t i = 0; i < m; i++) {
        if (parameter_count == 0) {
            resultant += (CalculateHypothesisOutput(x_values[parameter_count][i],true) - y_values[i]);
        } else {
            resultant += (CalculateHypothesisOutput(x_values[parameter_count][i],true) - y_values[i]) * x_values[parameter_count][i];
        }
    }

    return resultant / m;
}


double gradientDescent::Gradient::CalculateHypothesisOutput(double input, bool is_multivariate) const {
    if (!is_multivariate) {
        return parameter_m_ * input + parameter_b_;
    } else {
        double output = parameters_[0];

        for (size_t i = 1 ; i < parameters_.size(); i++) {
            output += parameters_[i] * input;
        }

        return output;
    }
}

const std::vector<double> &gradientDescent::Gradient::getParameters() const {
    return parameters_;
}
