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

template <typename T, size_t size>
MatrixRow<T, size>::MatrixRow() {
    m_size = size;
    this->m_matrix.resize(size, 0);
}

template <typename T, size_t size>
MatrixRow<T, size>::MatrixRow(size_t _size, T _dafaultValue) : m_size(_size) {
    this->m_matrix.resize(this->m_size, _dafaultValue);
}

template <typename T, size_t size>
MatrixRow<T, size>::MatrixRow(const std::initializer_list<T> &list) {
    for (const auto &elem : list) {
        m_matrix.push_back(elem);
    }
    m_size = m_matrix.size();
}

template <typename T, size_t size>
MatrixRow<T>& MatrixRow<T, size>::operator=(const MatrixRow<T>& rhs) {
    this->m_size = rhs.getSize();
    this->m_matrix.resize(m_size, 0);
    size_t i = 0;
    for (size_t j = 0; j < rhs.getSize(); ++j) {
        (*this)[i] = rhs[j];
        ++i;
    }

    return *this;
}

template <typename T, size_t size>
T MatrixRow<T, size>::operator[](size_t index) const {
    if (index > m_size) {
        throw "error";
    }

    return m_matrix[index];
}

template <typename T, size_t size>
T& MatrixRow<T, size>::operator[](size_t index) {
    if (index > m_size) {
        throw "error";
    }

    return m_matrix[index];
}

template <typename T, size_t size>
MatrixRow<T> MatrixRow<T, size>::operator+(const MatrixRow<T>& rhs) const {
    if (this->getSize() != rhs.getSize()) {
        throw "error";
    }

    MatrixRow<T> sumMatrix(this->getSize(), 0);

    for (size_t curRowIndex = 0; curRowIndex < this->getSize(); ++curRowIndex) {
        sumMatrix[curRowIndex] = (*this)[curRowIndex] + rhs[curRowIndex];
    }
    return sumMatrix;
}

template <typename T, size_t size>
MatrixRow<T> MatrixRow<T, size>::operator-(const MatrixRow<T>& rhs) const {
    if (this->getSize() != rhs.getSize()) {
        throw "error";
    }

    MatrixRow<T> matrixSubtraction(this->getSize(), 0);

    for (size_t curRowIndex = 0; curRowIndex < this->getSize(); ++curRowIndex) {
        matrixSubtraction[curRowIndex] = (*this)[curRowIndex] - rhs[curRowIndex];
    }
    return matrixSubtraction;
}

template <typename T, size_t size>
T MatrixRow<T, size>::operator*(const MatrixCol<T>& rhs) const {
    if (this->getSize() != rhs.getSize()) {
        throw "error";
    }

    T resMultiplication = 0;

    for (size_t curRowIndex = 0; curRowIndex < this->getSize(); ++curRowIndex) {
        resMultiplication += (*this)[curRowIndex] * rhs[curRowIndex];
    }

    return resMultiplication;
}

template <typename T, size_t size>
MatrixRow<T> MatrixRow<T, size>::operator*(T value) const {
    if (!(this->getSize())) {
        throw "error";
    }

    MatrixRow<T> matrixMultiplication(this->getSize(), 0);

    for (size_t curRowIndex = 0; curRowIndex < this->getSize(); ++curRowIndex) {
        matrixMultiplication[curRowIndex] = (*this)[curRowIndex] * value;
    }
    return matrixMultiplication;
}

template <typename T, size_t size>
MatrixRow<T> MatrixRow<T, size>::operator-(T value) const {
    if (!(this->getSize())) {
        throw "error";
    }

    MatrixRow<T> matrixSubtraction(this->getSize(), 0);

    for (size_t curRowIndex = 0; curRowIndex < this->getSize(); ++curRowIndex) {
        matrixSubtraction[curRowIndex] = (*this)[curRowIndex] - value;
    }

    return matrixSubtraction;
}

template <typename T, size_t size>
MatrixRow<T> MatrixRow<T, size>::operator+(T value) const {
    if (!(this->getSize())) {
        throw "error";
    }

    MatrixRow<T> sumMatrix(this->getSize(), 0);

    for (size_t curRowIndex = 0; curRowIndex < this->getSize(); ++curRowIndex) {
        sumMatrix[curRowIndex] = (*this)[curRowIndex] + value;
    }
    return sumMatrix;
}

template <typename T, size_t size>
MatrixRow<T> MatrixRow<T, size>::operator*(const Matrix<T>& rhs) const {
    if (this->getSize() != rhs.getRows()) {
        throw "error";
    }

    MatrixRow<T> matrixMultiplication(rhs.getCols(), 0);

    for (size_t j = 0; j < rhs.getCols(); ++j) {
        T tempRes = 0;
        for (size_t curRow = 0; curRow < rhs.getRows(); ++curRow) {
            tempRes += (*this)[curRow] * rhs(curRow, j);
        }
        matrixMultiplication[j] = tempRes;
    }

    return matrixMultiplication;
}
