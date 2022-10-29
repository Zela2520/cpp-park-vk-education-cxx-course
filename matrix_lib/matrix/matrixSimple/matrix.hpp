#pragma once // NOLINT


#include "matrix_col.hpp"

#define eps2 1e7
///////////////////////////////////////Simple matrix////////////////////////////////////////////////  
template <typename T, size_t row, size_t col>
class Matrix {
    public:
        Matrix();
        explicit Matrix(const std::initializer_list<T> &list);
        explicit Matrix(size_t _row, size_t _col);
        Matrix(const Matrix& rhs) = default;
        Matrix<T, row, col>& operator=(const Matrix<T>& rhs);
        ~Matrix() = default;

        size_t getSize() const {return m_row * m_col;}

        size_t getRows() const { return this->m_row; }
        size_t getCols() const { return this->m_col; }

        T operator()(size_t cur_row, size_t cur_col) const;
        T& operator()(size_t cur_row, size_t cur_col);


        // извлечение диагонали строки или столбца 
        MatrixRow<T, col> getDiagonal();
        MatrixRow<T, col> getRow(size_t rowNumber);
        MatrixCol<T, row> getCol(size_t colNumber);

        bool operator==(const Matrix<T, row, col>& rhs) const;
        bool operator!=(const Matrix<T, row, col>& rhs) const;

        Matrix<T> operator+(const Matrix<T, row, col>& rhs) const;
        Matrix<T> operator-(const Matrix<T, row, col>& rhs) const;
        Matrix<T> operator*(const Matrix<T, row, col>& rhs) const;

        Matrix<T> operator+(const MatrixRow<T, col>& rhs) const;
        Matrix<T> operator-(const MatrixRow<T, col>& rhs) const;

        Matrix<T> operator+(const MatrixCol<T, row>& rhs) const;
        Matrix<T> operator-(const MatrixCol<T, row>& rhs) const;

        MatrixCol<T, row> operator*(const MatrixCol<T, row>& rhs) const;

        Matrix<T> operator+(T val) const;
        Matrix<T> operator-(T val) const;

        Matrix<T> operator*(T val) const; // правостороннее
        template <typename T3, size_t row3, size_t col3>
        friend Matrix<T3> operator*(T3 val, const Matrix<T3, row3, col3>& matrix); // левостороннее

        template <typename T1, size_t N, size_t M>
        friend void fillMinor(const Matrix<T1, N, M>& matrix, size_t del_row, size_t del_col, Matrix<double>& new_matrix);
        template <typename T2, size_t N1, size_t M1>
        friend Matrix<T2> returnFilledMinor(const Matrix<T2, N1, M1>& matrix, size_t del_row, size_t del_col, Matrix<T2>* new_matrix);

        Matrix<T> transp() const;
        T det() const;
        Matrix<T> adj() const;
        Matrix<T> inv() const;

    private:
        size_t m_row;
        size_t m_col;
        std::vector<T> m_matrix;
};

#include "matrix_src.hpp"
