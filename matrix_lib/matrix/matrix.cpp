#include "exception.hpp"


template class Matrix<double, 1, 1>;
template class Matrix<int, 1, 1>;
template class Matrix<float, 2, 2>;
template class Matrix<double, 3, 4>;
template class Matrix<size_t, 4, 4>;

template <typename T, size_t row, size_t col>
Matrix<T, row, col>::Matrix() {
    this->m_row = row;
    this->m_col = col;
    this->m_matrix.resize(this->m_row * this->m_col, 0);
}

template <typename T, size_t row, size_t col>
Matrix<T, row, col>::Matrix(size_t _row, size_t _col) : m_row(_row), m_col(_col) {
    this->m_matrix.resize(this->m_row * this->m_col, 0);
}

template <typename T, size_t row, size_t col>
Matrix<T, row, col>::Matrix(std::istream& input_stream) {

    if (input_stream.fail()) {
        throw InvalidMatrixStream();
    }

    if (!(input_stream >> this->m_row >> this->m_col)) {
        throw InvalidMatrixStream();
    }

    this->m_matrix.resize(this->m_row * this->m_col, 0);

    for (auto& elem : this->m_matrix) {
        if (!(input_stream >> elem)) {
            throw InvalidMatrixStream();
        }
    }
}
