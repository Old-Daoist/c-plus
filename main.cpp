#include <iostream>
#include <exception>

// Header files
#include "include/Utils.hpp"
#include "include/Matrix.hpp"
#include "include/Rootfinding.hpp"
#include "include/complex.hpp"


// =========================
// Equation for root finding
// f(x) = x^2 - 4
// =========================
double equation(double x) {
    return x * x - 4;
}

// Derivative for Newton-Raphson
double derivative(double x) {
    return 2 * x;
}

// Fixed Point transformation
// Example: x = 0.5 * (x + 4/x)
double g(double x) {
    return 0.5 * (x + 4 / x);
}


int main() {
    try {

        // ===============================================================================================
        Utils::print("========================= Complex Number ======================");

        myComplex c1(2, 3);   
        myComplex c2(4, -1);

        myComplex sum  = c1.add(c2);
        myComplex diff = c1.subtract(c2);
        myComplex prod = c1.multiply(c2);
        myComplex quot = c1.divide(c2);

        Utils::print("c1 value:");
        c1.display();

        Utils::print("c2 value:");
        c2.display();

        Utils::print("Sum:");
        sum.display();

        Utils::print("Difference:");
        diff.display();

        Utils::print("Product:");
        prod.display();

        Utils::print("Quotient:");
        quot.display();


        // ===========================================================================================
        Utils::print("\n========================= Matrix ======================");

        Matrix mat(2, 2);

        mat.setValue(0, 0, 1);
        mat.setValue(0, 1, 2);
        mat.setValue(1, 0, 3);
        mat.setValue(1, 1, 4);

        mat.display();

        // Determinant
         Utils::print("\nDeterminant:");
        std::cout << mat.determinant() << std::endl;

        // Inverse
        Utils::print("\nInverse:");
        Matrix inv = mat.inverse();
        inv.display();

        Utils::print("\nGaussian Elimination Solution:");
        std::vector<double> b = {5, 11};
        std::vector<double> solution = mat.solveGaussian(b);
        for (double val : solution)
        std::cout << val << " ";
        std::cout << std::endl;



        // ==========================================================================================
        Utils::print("\n========================= Root Finding ======================");

        // ---------- Bisection ----------
        BisectionMethod bisection(0, 5);
        double rootBisection = bisection.solve(equation);

        std::cout << "Bisection Root: "
                  << rootBisection << std::endl;


        // ---------- Fixed Point ----------
        FixedPointMethod fixedPoint(3);
        double rootFixed = fixedPoint.solve(g);

        std::cout << "Fixed Point Root: "
                  << rootFixed << std::endl;


        // ---------- Newton Raphson ----------
        NewtonRaphsonMethod newton(3, derivative);
        double rootNewton = newton.solve(equation);

        std::cout << "Newton-Raphson Root: "
                  << rootNewton << std::endl;

        

        Utils::print("\n========================= Program Completed ======================");


    }
    catch (const std::exception& e) {
        std::cerr << "Runtime Error: " << e.what() << std::endl;
    }

    return 0;
}
