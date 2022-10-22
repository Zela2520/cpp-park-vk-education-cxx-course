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
#include <string>

class MatrixException;
class InvalidMatrixStream;
class OutOfRange;

///////////////////////////////////////Simple matrix////////////////////////////////////////////////  
template <typename T = double, size_t row = 1, size_t col = 1>
class Matrix {
    public:
        Matrix();
        Matrix(const std::initializer_list<T> &list);
        explicit Matrix(size_t _row, size_t _col);
        Matrix(const Matrix& rhs) = default;
        Matrix& operator=(const Matrix& rhs) = default;
        ~Matrix() = default;

        size_t getSize() const {return m_row * m_col;}

        size_t getRows() const { return this->m_row; }
        size_t getCols() const { return this->m_col; }

        double operator()(size_t cur_row, size_t cur_col) const;
        const double& operator()(size_t cur_row, size_t cur_col);

        

    private:
        size_t m_row;
        size_t m_col;
        std::vector<T> m_matrix;
};

template <typename T, size_t row, size_t col>
Matrix<T, row, col>::Matrix() {
    this->m_row = row;
    this->m_col = col;
    this->m_matrix.resize(this->m_row * this->m_col, 0);
}

template <typename T, size_t row, size_t col>
Matrix<T, row, col>::Matrix(const std::initializer_list<T> &list) {
    // тут получается обязательно необходимо указать размер матрицы при создании
    m_row = row;
    m_col = col;
    for (const auto &elem : list) {
        m_matrix.push_back(elem);
    }
}

template <typename T, size_t row, size_t col>
Matrix<T, row, col>::Matrix(size_t _row, size_t _col) : m_row(_row), m_col(_col) {
    this->m_matrix.resize(this->m_row * this->m_col, 0);
}

template <typename T, size_t row, size_t col>
double Matrix<T, row, col>::operator()(size_t cur_row, size_t cur_col) const {
    if (this->getRows() <= cur_row || this->getCols() <= cur_col) {
        throw "Out of range error";
    }

    return this->m_matrix[(cur_row * this->m_col) + cur_col];
}

template <typename T, size_t row, size_t col>
const double& Matrix<T, row, col>::operator()(size_t cur_row, size_t cur_col) {
    if (this->getRows() <= cur_row || this->getCols() <= cur_col) {
        throw "Out of range error";
    }

    return this->m_matrix[(cur_row * this->m_col) + cur_col];
}

// class Real {
//     public:
//         explicit Real() : m_number(0.0) {}
//         explicit Real(double number) : m_number(number) {}
        
//         operator double() const { return m_number; }
//         float toFloat() const { return static_cast<float>(m_number); }
//         int toInt() const { return static_cast<int>(m_number); }

//     private:
//         double m_number;
// };

// template <typename T = double, size_t size = 1>
// class MatrixCol;
///////////////////////////////////////Matrix row////////////////////////////////////////////////
// template <typename T = double, size_t size = 1>
// class MatrixRow {
//     public:
//         MatrixRow();
//         MatrixRow(size_t _size, T _dafaultValue);
//         MatrixRow(const std::initializer_list<T> &list);
        
//         size_t getSize() const {return m_matrix.size();};
        
//         T operator[](size_t index) const;
//         T& operator[](size_t index);
        
//         // T& operator(size_pos);
//         // T& operator(size_pos) const;
        
//         bool operator==(const MatrixRow& rhs) const;
//         bool operator!=(const MatrixRow& rhs) const;
        
//         MatrixRow operator+(const MatrixRow& rhs) const;
//         MatrixRow operator-(const MatrixRow& rhs) const;
        
        
//         MatrixRow operator*(int value) const;
//         // Matrix operator*(const VectorCol& rhs) const;
//         // Matrix operator(const Matrix& rhs) const;
//         /*
//             на самом деле на выходе строка (VectorRow)
//         */
        
        
    
//     private:
//         std::vector<T> m_matrix;
//         size_t m_size;
// };

// template <typename T, size_t size>
// MatrixRow<T, size>::MatrixRow() {
//     m_size = size;
//     this->m_matrix.resize(size, 0);
// }

// template <typename T, size_t size>
// MatrixRow<T, size>::MatrixRow(size_t _size, T _dafaultValue) : m_size(_size) {
//     this->m_matrix.resize(this->m_size, _dafaultValue);
// }

// template <typename T, size_t size>
// MatrixRow<T, size>::MatrixRow(const std::initializer_list<T> &list) {
//     m_size = size;
//     for (const auto &elem : list) {
//         m_matrix.push_back(elem);
//     }
//     m_size = m_matrix.size();
// }

// template <typename T, size_t size>
// T MatrixRow<T, size>::operator[](size_t index) const {
//     if (index < 0 || index > m_size) {
//         throw "error";
//     }

//     return m_matrix[index];
// }

// template <typename T, size_t size>
// T& MatrixRow<T, size>::operator[](size_t index) {
//     if (index > m_size) {
//         throw "error";
//     }

//     return m_matrix[index];
// }

///////////////////////////////////////Matrix col////////////////////////////////////////////////

// template <typename T, size_t size>
// class MatrixCol {
//     public:
//         MatrixCol();
//         MatrixCol(size_t _size, T _dafaultValue);
//         MatrixCol(const std::initializer_list<T> &list);
        
//         size_t getSize() const {return m_matrix.size();};
        
//         T operator[](size_t index) const;
//         T& operator[](size_t index);
        
//         // T& operator(size_pos);
//         // T& operator(size_pos) const;
        
//         bool operator==(const MatrixCol& rhs) const;
//         bool operator!=(const MatrixCol& rhs) const;
        
//         MatrixCol operator+(const MatrixCol& rhs) const;
//         MatrixCol operator-(const MatrixCol& rhs) const;
        
        
//         MatrixCol operator*(int value) const;
//         // Matrix operator*(const VectorCol& rhs) const;
//         // Matrix operator(const Matrix& rhs) const;
//         /*
//             на самом деле на выходе строка (VectorRow)
//         */
        
        
    
//     private:
//         std::vector<T> m_matrix;
//         size_t m_size;
// };

// template <typename T, size_t size>
// MatrixCol<T, size>::MatrixCol() {
//     m_size = size;
//     this->m_matrix.resize(size, 0);
// }

// template <typename T, size_t size>
// MatrixCol<T, size>::MatrixCol(size_t _size, T _dafaultValue) : m_size(_size) {
//     this->m_matrix.resize(this->m_size, _dafaultValue);
// }

// template <typename T, size_t size>
// MatrixCol<T, size>::MatrixCol(const std::initializer_list<T> &list) {
//     m_size = size;
//     for (const auto &elem : list) {
//         m_matrix.push_back(elem);
//     }
//     m_size = m_matrix.size();
// }

// template <typename T, size_t size>
// T MatrixCol<T, size>::operator[](size_t index) const {
//     if (index < 0 || index > m_size) {
//         throw "error";
//     }

//     return m_matrix[index];
// }

// template <typename T, size_t size>
// T& MatrixCol<T, size>::operator[](size_t index) {
//     if (index > m_size) {
//         throw "error";
//     }

//     return m_matrix[index];
// }

#endif // MATRIX_LIB_MATRIX_MATRIX_HPP_
