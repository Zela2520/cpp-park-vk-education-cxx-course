#ifndef MATRIX_LIB_MATRIX_MATRIX_HPP_
#define MATRIX_LIB_MATRIX_MATRIX_HPP_

#include <iostream>
#include <vector>
#include <cstddef>


class Matrix {
    public:
        explicit Matrix(size_t row, size_t col);
        Matrix(const Matrix& rhs) = default;
        Matrix& operator=(const Matrix& rhs) = default;
        ~Matrix() = default;

        size_t getNumberOfMatrixElements() const {return m_row * m_col;}

    private:
        size_t m_row;
        size_t m_col;
        std::vector<double> m_matrix;
};



#endif // MATRIX_LIB_MATRIX_MATRIX_HPP_
