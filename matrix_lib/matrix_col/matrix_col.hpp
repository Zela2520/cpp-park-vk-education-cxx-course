#ifndef MATRIX_LIB_MATRIX_COL_MATRIX_COL_HPP_
#define MATRIX_LIB_MATRIX_COL_MATRIX_COL_HPP_

#include "matrix.hpp"

class MatrixException;
class InvalidMatrixStream;
class OutOfRange;

template <typename T = double, size_t size = 1>
class MatrixCol {
    public:
        MatrixCol();
        MatrixCol(size_t _size, T _dafaultValue);
        MatrixCol(const std::initializer_list<T> &list);
        
        size_t getSize() const {return m_matrix.size();};
        
        T operator[](size_t index) const;
        T& operator[](size_t index);
        
        // T& operator(size_pos);
        // T& operator(size_pos) const;
        
        bool operator==(const MatrixCol& rhs) const;
        bool operator!=(const MatrixCol& rhs) const;
        
        MatrixCol operator+(const MatrixCol& rhs) const;
        MatrixCol operator-(const MatrixCol& rhs) const;
        
        
        MatrixCol operator*(int value) const;
        // Matrix operator*(const VectorCol& rhs) const;
        // Matrix operator(const Matrix& rhs) const;
        /*
            на самом деле на выходе строка (VectorRow)
        */
        
        
    
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
    m_size = size;
    for (const auto &elem : list) {
        m_matrix.push_back(elem);
    }
    m_size = m_matrix.size();
}

template <typename T, size_t size>
T MatrixCol<T, size>::operator[](size_t index) const {
    if (index < 0 || index > m_size) {
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

#endif // MATRIX_LIB_MATRIX_COL_MATRIX_COL_HPP_
