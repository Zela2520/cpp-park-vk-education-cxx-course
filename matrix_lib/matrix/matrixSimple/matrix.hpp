#pragma once // NOLINT

#include "matrix_col.hpp"
#define eps2 1e7

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

///////////////////////////////////////Simple matrix////////////////////////////////////////////////  
template <typename T, size_t row, size_t col>
class Matrix {
    public:
        Matrix();
        explicit Matrix(const std::initializer_list<T> &list);
        explicit Matrix(size_t _row, size_t _col);
        Matrix(const Matrix& rhs) = default;
        Matrix<T>& operator=(const Matrix<T>& rhs) {
            this->m_row = rhs.getRows();
            this->m_col = rhs.getCols();

            this->m_matrix.resize(m_row * m_col, 0);
            size_t index = 0;
            for (auto& elem : rhs.m_matrix) {
                this->m_matrix[index] = elem;
                ++index;
            }

            return *this;
        }
        ~Matrix() = default;

        size_t getSize() const {return m_row * m_col;}

        size_t getRows() const { return this->m_row; }
        size_t getCols() const { return this->m_col; }

        T operator()(size_t cur_row, size_t cur_col) const;
        T& operator()(size_t cur_row, size_t cur_col);



        // извлечение диагонали строки или столбца 
        MatrixRow<T> getDiagonal();
        MatrixRow<T> getRow(size_t rowNumber);
        MatrixCol<T> getCol(size_t colNumber);
        // 

        bool operator==(const Matrix<T, row, col>& rhs) const;
        bool operator!=(const Matrix<T, row, col>& rhs) const;

        Matrix<T> operator+(const Matrix<T, row, col>& rhs) const;
        Matrix<T> operator-(const Matrix<T, row, col>& rhs) const;
        Matrix<T> operator*(const Matrix<T, row, col>& rhs) const;

        // вот эта протестить и усе
        Matrix<T> operator+(const MatrixRow<T>& rhs) const;
        Matrix<T> operator-(const MatrixRow<T>& rhs) const;

        Matrix<T> operator+(const MatrixCol<T>& rhs) const;
        Matrix<T> operator-(const MatrixCol<T>& rhs) const;

        MatrixCol<T> operator*(const MatrixCol<T>& rhs) const;
        // вот эта протестить и усе

        Matrix<T> operator+(T val) const;
        Matrix<T> operator-(T val) const;
        // правостороннее
        Matrix<T> operator*(T val) const;
        // левостороннее
        friend Matrix<T> operator*(T val, const Matrix<T, row, col>& matrix) {
            Matrix<T> multiplicationMatrix(matrix.getRows(), matrix.getCols());

            for (size_t curRow = 0; curRow < matrix.getRows(); ++curRow) {
                for (size_t curCol = 0; curCol < matrix.getCols(); ++curCol) {
                    multiplicationMatrix(curRow, curCol) = matrix(curRow, curCol) * val;
                }
            }
            return multiplicationMatrix;
        }

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
