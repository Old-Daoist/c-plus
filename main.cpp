#include <iostream>
#include "complex.hpp"

using namespace std;

int main() {

    cout << "MyComplex Class\n\n";

    myComplex c1(1, 2);
    myComplex c2(3, 4);
    myComplex c3;

    // Addition
    c3 = c1.add(c2);
     cout << "Addition: "
           << c3.getReal() << " + " << c3.getImag() << "i\n";    

    // Subtraction
    myComplex sub = c1.subtract(c2);
    cout << "Subtraction: "
         << sub.getReal() << " + " << sub.getImag() << "i\n";

    // Multiplication
    myComplex mul = c1.multiply(c2);
    cout << "Multiplication: "
         << mul.getReal() << " + " << mul.getImag() << "i\n";

    // Division
    myComplex div = c1.divide(c2);
    cout << "Division: "
         << div.getReal() << " + " << div.getImag() << "i\n";

    // Conjugate
    myComplex conj = c1.conjugate();
    cout << "Conjugate of c1: "
         << conj.getReal() << " + " << conj.getImag() << "i\n";

    // Norm
    cout << "Norm of c1: " << c1.norm() << endl;

    c1.display();
    c2.display();
    c3.display();

    return 0;
}