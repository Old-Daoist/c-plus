#include "Rootfinding.hpp"
#include <cmath>
#include <stdexcept>

// ================= BISECTION =================

BisectionMethod::BisectionMethod(double left, double right,
                                 double tol, int maxIter)
    : RootMethod(tol, maxIter), a(left), b(right) {}

double BisectionMethod::solve(std::function<double(double)> func) {
    if (func(a) * func(b) >= 0)
        throw std::runtime_error("Bisection: Invalid interval.");

    double c;

    for (int i = 0; i < maxIterations; ++i) {
        c = (a + b) / 2.0;

        if (std::abs(func(c)) < tolerance)
            return c;

        if (func(a) * func(c) < 0)
            b = c;
        else
            a = c;
    }

    throw std::runtime_error("Bisection: Max iterations reached.");
}

// ================= FIXED POINT =================

FixedPointMethod::FixedPointMethod(double guess,
                                   double tol, int maxIter)
    : RootMethod(tol, maxIter), initialGuess(guess) {}

double FixedPointMethod::solve(std::function<double(double)> g) {
    double x0 = initialGuess;
    double x1;

    for (int i = 0; i < maxIterations; ++i) {
        x1 = g(x0);

        if (std::abs(x1 - x0) < tolerance)
            return x1;

        x0 = x1;
    }

    throw std::runtime_error("Fixed Point: Max iterations reached.");
}

// ================= NEWTON RAPHSON =================

NewtonRaphsonMethod::NewtonRaphsonMethod(
    double guess,
    std::function<double(double)> deriv,
    double tol, int maxIter)
    : RootMethod(tol, maxIter),
      initialGuess(guess),
      derivative(deriv) {}

double NewtonRaphsonMethod::solve(std::function<double(double)> func) {
    double x = initialGuess;

    for (int i = 0; i < maxIterations; ++i) {
        double fVal = func(x);
        double dVal = derivative(x);

        if (dVal == 0)
            throw std::runtime_error("Newton: Derivative zero.");

        double xNew = x - fVal / dVal;

        if (std::abs(xNew - x) < tolerance)
            return xNew;

        x = xNew;
    }

    throw std::runtime_error("Newton: Max iterations reached.");
}
