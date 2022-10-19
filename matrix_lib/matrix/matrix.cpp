#include "matrix.hpp"


Matrix::Matrix(size_t row, size_t col) : m_row(row), m_col(col) {
    this->m_matrix.resize(this->m_row * this->m_col, 0);
}
