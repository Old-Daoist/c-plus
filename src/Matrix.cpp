#include "../include/Matrix.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

// Constructor
Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    if (r <= 0 || c <= 0)
        throw std::invalid_argument("Matrix dimensions must be positive");

    data.resize(rows, std::vector<double>(cols, 0.0));
}

// Set value
void Matrix::setValue(int r, int c, double value) {
    if (r < 0 || r >= rows || c < 0 || c >= cols)
        throw std::out_of_range("Index out of range");

    data[r][c] = value;
}

// Get value
double Matrix::getValue(int r, int c) const {
    if (r < 0 || r >= rows || c < 0 || c >= cols)
        throw std::out_of_range("Index out of range");

    return data[r][c];
}

// Display
void Matrix::display() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            std::cout << data[i][j] << " ";
        std::cout << std::endl;
    }
}

// Getters
int Matrix::getRows() const { return rows; }
int Matrix::getCols() const { return cols; }


// =======================
// Minor helper
// =======================
static Matrix getMinor(const Matrix& mat, int skipRow, int skipCol) {

    int n = mat.getRows();
    Matrix minor(n - 1, n - 1);

    int r = 0;

    for (int i = 0; i < n; i++) {
        if (i == skipRow) continue;

        int c = 0;
        for (int j = 0; j < n; j++) {
            if (j == skipCol) continue;

            minor.setValue(r, c, mat.getValue(i, j));
            c++;
        }
        r++;
    }
    return minor;
}


// =======================
// Determinant
// =======================
double Matrix::determinant() const {

    if (rows != cols)
        throw std::runtime_error("Matrix must be square.");

    if (rows == 1)
        return data[0][0];

    if (rows == 2)
        return data[0][0]*data[1][1] - data[0][1]*data[1][0];

    double det = 0;

    for (int j = 0; j < cols; j++) {
        Matrix minor = getMinor(*this, 0, j);
        double cofactor = ((j % 2 == 0) ? 1 : -1)
                          * data[0][j]
                          * minor.determinant();
        det += cofactor;
    }

    return det;
}


// =======================
// Inverse
// =======================
Matrix Matrix::inverse() const {

    if (rows != cols)
        throw std::runtime_error("Matrix must be square.");

    double det = determinant();

    if (std::abs(det) < 1e-10)
        throw std::runtime_error("Matrix is singular.");

    Matrix adj(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            Matrix minor = getMinor(*this, i, j);

            double cofactor = minor.determinant();
            if ((i + j) % 2 != 0)
                cofactor = -cofactor;

            adj.setValue(j, i, cofactor);
        }
    }

    Matrix inv(rows, cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            inv.setValue(i, j, adj.getValue(i, j) / det);

    return inv;
}


// =======================
// Gaussian Elimination
// =======================
std::vector<double> Matrix::solveGaussian(const std::vector<double>& b) const {

    if (rows != cols)
        throw std::runtime_error("Matrix must be square.");

    if (b.size() != static_cast<size_t>(rows))

        throw std::runtime_error("Dimension mismatch.");

    int n = rows;

    // Augmented matrix
    std::vector<std::vector<double>> aug(n, std::vector<double>(n + 1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            aug[i][j] = data[i][j];

        aug[i][n] = b[i];
    }

    // Forward elimination
    for (int i = 0; i < n; i++) {

        if (std::abs(aug[i][i]) < 1e-10)
            throw std::runtime_error("Zero pivot encountered.");

        for (int j = i + 1; j < n; j++) {

            double factor = aug[j][i] / aug[i][i];

            for (int k = i; k <= n; k++)
                aug[j][k] -= factor * aug[i][k];
        }
    }

    // Back substitution
    std::vector<double> x(n);

    for (int i = n - 1; i >= 0; i--) {

        x[i] = aug[i][n];

        for (int j = i + 1; j < n; j++)
            x[i] -= aug[i][j] * x[j];

        x[i] /= aug[i][i];
    }

    return x;
}
