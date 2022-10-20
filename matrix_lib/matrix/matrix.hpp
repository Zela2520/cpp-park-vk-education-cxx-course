#ifndef MATRIX_LIB_MATRIX_MATRIX_HPP_
#define MATRIX_LIB_MATRIX_MATRIX_HPP_


#include <vector>
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <set>
#include <complex>
#include "exception.hpp"


class Real {
    public:
        explicit Real() : m_number(0.0) {}
        explicit Real(double number) : m_number(number) {}
        
        operator double() const { return m_number; }
        float toFloat() const { return static_cast<float>(m_number); }
        int toInt() const { return static_cast<int>(m_number); }

    private:
        double m_number;
};

template <typename T = double, size_t row = 1, size_t col = 1>
class Matrix {
    public:
        Matrix();
        explicit Matrix(size_t _row, size_t _col);
        explicit Matrix(std::istream& input_stream);
        Matrix(const Matrix& rhs) = default;
        Matrix& operator=(const Matrix& rhs) = default;
        ~Matrix() = default;

        size_t getNumberOfMatrixElements() const {return m_row * m_col;}

        size_t getRows() const { return this->m_row; }
        size_t getCols() const { return this->m_col; }

        // double operator()(size_t row, size_t col) const;
        // double& operator()(size_t row, size_t col);

    private:
        size_t m_row;
        size_t m_col;
        std::vector<T> m_matrix;
};


#endif // MATRIX_LIB_MATRIX_MATRIX_HPP_
