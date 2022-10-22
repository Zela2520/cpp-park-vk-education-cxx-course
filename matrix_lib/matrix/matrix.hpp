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

template <typename T = double, size_t size = 1>
class VectorCol;
///////////////////////////////////////Matrix row////////////////////////////////////////////////
template <typename T = double, size_t size = 1>
class VectorRow {
    public:
        VectorRow(std::initializer_list<T> &list);
        VectorRow (size_t _size = 1, T _dafault_value = 0);
        explicit VectorRow(std::istream& input_stream);
        
        size_t getSize() const { return m_data.size(); };
        
        T& operator[](size_t pos);
        T& operator[](size_t pos) const;
        
        // T& operator(size_pos);
        // T& operator(size_pos) const;
        
        bool operator==(const VectorRow& rhs) const;
        bool operator!=(const VectorRow& rhs) const;
        
        VectorRow operator+(const VectorRow& rhs) const;
        VectorRow operator-(const VectorRow& rhs) const;
        
        
        VectorRow operator*(int value) const;
        // Matrix operator*(const VectorCol& rhs) const;
        // Matrix operator(const Matrix& rhs) const;
        /*
            на самом деле на выходе строка (VectorRow)
        */
        
        
    
    private:
        std::vector<T> m_data;
};

template <typename T, size_t size>
VectorRow<T, size>::VectorRow(std::initializer_list<T> &list) : VectorRow(list.size()) {
    auto i = 0;
    for (const auto &elem : list) {
        m_data[i] = elem;
        i += 1;
    }
}


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
Matrix<T, row, col>::Matrix(const std::initializer_list<T> &list) : m_row(row), m_col(col) {
    auto i = 0;
    for (const auto &elem : list) {
        m_matrix[i] = elem;
        ++i;
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

#endif // MATRIX_LIB_MATRIX_MATRIX_HPP_
