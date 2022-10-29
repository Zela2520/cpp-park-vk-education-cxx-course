#pragma once // NOLINT

#include "matrix_row.hpp"

/////////////////////////////////////Matrix col////////////////////////////////////////////////
template <typename T, size_t size>
class MatrixCol {
    public:
        MatrixCol();
        MatrixCol(size_t _size, T _defaultValue);
        explicit MatrixCol(const std::initializer_list<T> &list);
        MatrixCol(const MatrixCol& rhs) = default;
        MatrixCol<T, size>& operator=(const MatrixCol<T, size>& rhs);
        ~MatrixCol() = default;

        
        size_t getSize() const {return m_matrix.size();};
        
        T operator[](size_t index) const;
        T& operator[](size_t index);

        // Столбец (+-*) строка(*столбец)
        MatrixCol<T, size> operator+(const MatrixCol<T, size>& rhs) const;
        MatrixCol<T, size> operator-(const MatrixCol<T, size>& rhs) const;
        Matrix<T> operator*(const MatrixRow<T, size>& rhs) const;

        // Столбец (+-*) число
        MatrixCol<T, size> operator*(T value) const;
        MatrixCol<T, size> operator-(T value) const;
        MatrixCol<T, size> operator+(T value) const;
    
    private:
        std::array<T, size> m_matrix;
        size_t m_size;
};

#include "matrix_col_src.hpp"