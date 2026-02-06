#include <iostream>
#include <exception>

// add new header files here
#include "Include/Utils.hpp"
#include "Include/Matrix.hpp"
#include "Include/Rootfinding.hpp"
#include "Include/complex.hpp"


// Equation for root finding
double equation(double x) {
    return x * x - 4;
}

int main() {
    try {
        // ===============================
        Utils::print("========================= Complex Number ======================");

        myComplex c1(2, 3);   
        myComplex c2(4, -1);

        myComplex sum = c1.add(c2);
        myComplex diff = c1.subtract(c2);
        myComplex prod = c1.multiply(c2);

        Utils::print("c1 value below");
        c1.display();

        Utils::print("c2 value below ");
        c2.display();

        Utils::print("Sum below");
        sum.display();

        Utils::print("Difference below ");
        diff.display();

        Utils::print("Product below ");
        prod.display();

        Utils::print("\n==================Matrix entry================");

        Matrix mat(2, 2);
        mat.setValue(0, 0, 1);
        mat.setValue(0, 1, 2);
        mat.setValue(1, 0, 3);
        mat.setValue(1, 1, 4);

        mat.display();

        // ===============================
        Utils::print("\n============= Root Finding (Bisection Method) ============");

        double root = RootFinding::bisection(equation, 3, 5); //add parameters here
        std::cout << "Root found between: " << root << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Runtime Error: " << e.what() << std::endl;
    }

    return 0;
}
