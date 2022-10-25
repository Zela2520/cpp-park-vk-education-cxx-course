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

#include "matrix_col_src.hpp"