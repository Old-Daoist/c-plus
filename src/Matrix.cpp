#include "../Include/Matrix.hpp"
#include <iostream>
#include <stdexcept>

// Constructor
Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    if (r <= 0 || c <= 0) {
        throw std::invalid_argument("Matrix dimensions must be positive");
    }

    data.resize(rows, std::vector<double>(cols, 0.0));
}

// Set value with bounds checking
void Matrix::setValue(int r, int c, double value) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        throw std::out_of_range("Matrix index out of range");
    }

    data[r][c] = value;
}

// Get value with bounds checking
double Matrix::getValue(int r, int c) const {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        throw std::out_of_range("Matrix index out of range");
    }

    return data[r][c];
}

// Display matrix
void Matrix::display() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
