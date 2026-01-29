#ifndef COMPLEX_HPP
#define COMPLEX_HPP

class myComplex {
private:
    float real;   // real
    float imag;   // imaginary
    float extra;  // extra
public:
    // Constructors
    myComplex();                          // default
    myComplex(float r, float i);          // 2-parameter
    myComplex(float r, float i, float e); // 3-parameter

    // Operations
    myComplex add(const myComplex& c) const;
    myComplex subtract(const myComplex& c) const;
    myComplex multiply(const myComplex& c) const;
    myComplex divide(const myComplex& c) const;

    myComplex conjugate() const;
    float norm() const;

    float getReal() const;
    float getImag() const;
    
    //to display object C
    void display() const;

};

#endif
