#pragma once // NOLINT

#include "matrix_row.hpp"

/////////////////////////////////////Matrix col////////////////////////////////////////////////
template <typename T, size_t size>
class MatrixCol {
    public:
        MatrixCol();
        MatrixCol(size_t _size, T _dafaultValue);
        explicit MatrixCol(const std::initializer_list<T> &list);
        MatrixCol(const MatrixCol& rhs) = default;
        MatrixCol& operator=(const MatrixCol& rhs);
        ~MatrixCol() = default;

        
        size_t getSize() const {return m_matrix.size();};
        
        T operator[](size_t index) const;
        T& operator[](size_t index);

        // Столбец (+-*) строка(*столбец)
        MatrixCol<T> operator+(const MatrixCol<T>& rhs) const;
        MatrixCol<T> operator-(const MatrixCol<T>& rhs) const;
        Matrix<T> operator*(const MatrixRow<T>& rhs) const;

        // Столбец (+-*) число
        MatrixCol<T> operator*(T value) const;
        MatrixCol<T> operator-(T value) const;
        MatrixCol<T> operator+(T value) const;
    
    private:
        std::vector<T> m_matrix;
        size_t m_size;
};

template <typename T, size_t size>
MatrixCol<T, size>::MatrixCol() {
    m_size = size;
    this->m_matrix.resize(size, 0);
}

template <typename T, size_t size>
MatrixCol<T, size>::MatrixCol(size_t _size, T _dafaultValue) : m_size(_size) {
    this->m_matrix.resize(this->m_size, _dafaultValue);
}

template <typename T, size_t size>
MatrixCol<T, size>::MatrixCol(const std::initializer_list<T> &list) {
    for (const auto &elem : list) {
        m_matrix.push_back(elem);
    }
    m_size = m_matrix.size();
}

template <typename T, size_t size>
MatrixCol<T, size>& MatrixCol<T, size>::operator=(const MatrixCol& rhs) {
    this->m_size = rhs.m_size;
    this->m_matrix.resize(m_size, 0);
    size_t i = 0;
    for (auto& elem : rhs.m_matrix) {
        this->m_matrix[i] = elem;
        ++i;
    }

    return *this;
}

template <typename T, size_t size>
T MatrixCol<T, size>::operator[](size_t index) const {
    if (index > m_size) {
        throw "error";
    }

    return m_matrix[index];
}

template <typename T, size_t size>
T& MatrixCol<T, size>::operator[](size_t index) {
    if (index > m_size) {
        throw "error";
    }

    return m_matrix[index];
}

template <typename T, size_t size>
MatrixCol<T> MatrixCol<T, size>::operator+(const MatrixCol<T>& rhs) const {
    if (this->getSize() != rhs.getSize()) {
        throw "error";
    }

    MatrixCol<T> sumMatrix(this->getSize(), 0);

    for (size_t curRowIndex = 0; curRowIndex < this->getSize(); ++curRowIndex) {
        sumMatrix[curRowIndex] = (*this)[curRowIndex] + rhs[curRowIndex];
    }
    return sumMatrix;
}

template <typename T, size_t size>
MatrixCol<T> MatrixCol<T, size>::operator-(const MatrixCol<T>& rhs) const {
    if (this->getSize() != rhs.getSize()) {
        throw "error";
    }

    MatrixCol<T> matrixSubtraction(this->getSize(), 0);

    for (size_t curColMatrixColIndex = 0; curColMatrixColIndex < this->getSize(); ++curColMatrixColIndex) {
        matrixSubtraction[curColMatrixColIndex] = (*this)[curColMatrixColIndex] - rhs[curColMatrixColIndex];
    }
    return matrixSubtraction;
}

template <typename T, size_t size>
Matrix<T> MatrixCol<T, size>::operator*(const MatrixRow<T>& rhs) const {
    if (this->getSize() != rhs.getSize()) {
        throw "error";
    }

    Matrix<T> matrixMultiplication(this->getSize(), this->getSize());

    for (size_t curRow = 0; curRow < this->getSize(); ++curRow) {
        for (size_t curCol = 0; curCol < this->getSize(); ++curCol) {
            matrixMultiplication(curRow, curCol) = (*this)[curRow] * rhs[curCol];
        }
    }

    return matrixMultiplication;
}


// Строка (+-*) число
template <typename T, size_t size>
MatrixCol<T> MatrixCol<T, size>::operator*(T value) const {
    if (!(this->getSize())) {
        throw "error";
    }

    MatrixCol<T> matrixMultiplication(this->getSize(), 0);

    for (size_t curRowIndex = 0; curRowIndex < this->getSize(); ++curRowIndex) {
        matrixMultiplication[curRowIndex] = (*this)[curRowIndex] * value;
    }
    return matrixMultiplication;
}

template <typename T, size_t size>
MatrixCol<T> MatrixCol<T, size>::operator-(T value) const {
    if (!(this->getSize())) {
        throw "error";
    }

    MatrixCol<T> matrixMultiplication(this->getSize(), 0);

    for (size_t curRowIndex = 0; curRowIndex < this->getSize(); ++curRowIndex) {
        matrixMultiplication[curRowIndex] = (*this)[curRowIndex] - value;
    }
    return matrixMultiplication;
}

template <typename T, size_t size>
MatrixCol<T> MatrixCol<T, size>::operator+(T value) const {
    if (!(this->getSize())) {
        throw "error";
    }

    MatrixCol<T> matrixMultiplication(this->getSize(), 0);

    for (size_t curRowIndex = 0; curRowIndex < this->getSize(); ++curRowIndex) {
        matrixMultiplication[curRowIndex] = (*this)[curRowIndex] + value;
    }
    return matrixMultiplication;
}
