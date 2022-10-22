#ifndef MATRIX_LIB_MATRIX_ROW_MATRIX_ROW_HPP_
#define MATRIX_LIB_MATRIX_ROW_MATRIX_ROW_HPP_

#include "matrix.hpp"

template <typename T = double, size_t size = 1>
class MatrixRow {
    public:
        MatrixRow();
        MatrixRow(size_t _size, T _dafaultValue);
        MatrixRow(const std::initializer_list<T> &list);
        
        size_t getSize() const {return m_matrix.size();};
        
        T operator[](size_t index) const;
        T& operator[](size_t index);
        
        // T& operator(size_pos);
        // T& operator(size_pos) const;
        
        bool operator==(const MatrixRow& rhs) const;
        bool operator!=(const MatrixRow& rhs) const;
        
        MatrixRow operator+(const MatrixRow& rhs) const;
        MatrixRow operator-(const MatrixRow& rhs) const;
        
        
        MatrixRow operator*(int value) const;
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
    m_size = size;
    for (const auto &elem : list) {
        m_matrix.push_back(elem);
    }
    m_size = m_matrix.size();
}

template <typename T, size_t size>
T MatrixRow<T, size>::operator[](size_t index) const {
    if (index < 0 || index >= m_size) {
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

#endif // MATRIX_LIB_MATRIX_ROW_MATRIX_ROW_HPP_