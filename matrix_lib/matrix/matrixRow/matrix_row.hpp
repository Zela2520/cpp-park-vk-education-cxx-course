#pragma once // NOLINT

#include <vector>
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <set>
#include <complex>
#include <string>

class MatrixException;
class InvalidMatrixStream;
class OutOfRange;

#define EPS (std::numeric_limits<double>::epsilon()*1e-07)

template <typename T = double, size_t row = 1, size_t col = 1>
class Matrix;
template <typename T = double, size_t size = 1>
class MatrixCol;

/////////////////////////////////////Matrix row////////////////////////////////////////////////
template <typename T = double, size_t size = 1>
class MatrixRow {
    public:
        MatrixRow();
        MatrixRow(size_t _size, T _dafaultValue);
        explicit MatrixRow(const std::initializer_list<T> &list);
        MatrixRow(const MatrixRow& rhs) = default;
        MatrixRow<T>& operator=(const MatrixRow<T>& rhs);
        ~MatrixRow() = default; 
        
        size_t getSize() const {return m_matrix.size();};
        
        T operator[](size_t index) const;
        T& operator[](size_t index);

        // Строка (+-*) строка(*столбец)
        MatrixRow<T> operator+(const MatrixRow<T>& rhs) const;
        MatrixRow<T> operator-(const MatrixRow<T>& rhs) const;
        T operator*(const MatrixCol<T>& rhs) const;

        // Строка (+-*) число
        MatrixRow<T> operator*(T value) const;
        MatrixRow<T> operator-(T value) const;
        MatrixRow<T> operator+(T value) const;

        // Строка (*) матрица (разных размеров)
        MatrixRow<T> operator*(const Matrix<T>& rhs) const;
        
    private:
        std::vector<T> m_matrix;
        size_t m_size;
};

#include "matrix_row_src.hpp"
