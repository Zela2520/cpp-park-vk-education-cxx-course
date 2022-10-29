#pragma once // NOLINT

template <typename T, size_t size>
MatrixCol<T, size>::MatrixCol() {
    m_size = size;
    this->m_matrix.fill(0);
}

template <typename T, size_t size>
MatrixCol<T, size>::MatrixCol(size_t _size, T _defaultValue) : m_size(_size) {
    m_size = _size;
    m_size = size;
    this->m_matrix.fill(_defaultValue);
}

template <typename T, size_t size>
MatrixCol<T, size>::MatrixCol(const std::initializer_list<T> &list) {
    m_size = size;
    size_t index = 0;
    for (const auto& elem : list) {
        m_matrix[index] = elem;
        ++index;
    }
}

template <typename T, size_t size>
MatrixCol<T, size>& MatrixCol<T, size>::operator=(const MatrixCol<T, size>& rhs) {
    if (this->m_matrix.size() != rhs.m_matrix.size()) {
        throw "error";
    }

    for (size_t j = 0; j < rhs.getSize(); ++j) {
        (*this)[j] = rhs[j];
    }

    return *this;
}

template <typename T, size_t size>
T MatrixCol<T, size>::operator[](size_t index) const {
    if (index > m_size) {
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

template <typename T, size_t size>
MatrixCol<T, size> MatrixCol<T, size>::operator+(const MatrixCol<T, size>& rhs) const {
    if (this->getSize() != rhs.getSize()) {
        throw "error";
    }

    MatrixCol<T, size> sumMatrix(this->getSize(), 0);

    for (size_t curRowIndex = 0; curRowIndex < this->getSize(); ++curRowIndex) {
        sumMatrix[curRowIndex] = (*this)[curRowIndex] + rhs[curRowIndex];
    }
    return sumMatrix;
}

template <typename T, size_t size>
MatrixCol<T, size> MatrixCol<T, size>::operator-(const MatrixCol<T, size>& rhs) const {
    if (this->getSize() != rhs.getSize()) {
        throw "error";
    }

    MatrixCol<T, size> matrixSubtraction(this->getSize(), 0);

    for (size_t curColMatrixColIndex = 0; curColMatrixColIndex < this->getSize(); ++curColMatrixColIndex) {
        matrixSubtraction[curColMatrixColIndex] = (*this)[curColMatrixColIndex] - rhs[curColMatrixColIndex];
    }
    return matrixSubtraction;
}

template <typename T, size_t size>
Matrix<T> MatrixCol<T, size>::operator*(const MatrixRow<T, size>& rhs) const {
    if (this->getSize() != rhs.getSize()) {
        throw "error";
    }

    Matrix<T> matrixMultiplication(this->getSize(), this->getSize());

    for (size_t curRow = 0; curRow < this->getSize(); ++curRow) {
        for (size_t curCol = 0; curCol < this->getSize(); ++curCol) {
            matrixMultiplication(curRow, curCol) = (*this)[curRow] * rhs[curCol];
        }
    }

    return matrixMultiplication;
}


// Строка (+-*) число
template <typename T, size_t size>
MatrixCol<T, size> MatrixCol<T, size>::operator*(T value) const {
    if (!(this->getSize())) {
        throw "error";
    }

    MatrixCol<T, size> matrixMultiplication(this->getSize(), 0);

    for (size_t curRowIndex = 0; curRowIndex < this->getSize(); ++curRowIndex) {
        matrixMultiplication[curRowIndex] = (*this)[curRowIndex] * value;
    }
    return matrixMultiplication;
}

template <typename T, size_t size>
MatrixCol<T, size> MatrixCol<T, size>::operator-(T value) const {
    if (!(this->getSize())) {
        throw "error";
    }

    MatrixCol<T, size> matrixMultiplication(this->getSize(), 0);

    for (size_t curRowIndex = 0; curRowIndex < this->getSize(); ++curRowIndex) {
        matrixMultiplication[curRowIndex] = (*this)[curRowIndex] - value;
    }
    return matrixMultiplication;
}

template <typename T, size_t size>
MatrixCol<T, size> MatrixCol<T, size>::operator+(T value) const {
    if (!(this->getSize())) {
        throw "error";
    }

    MatrixCol<T, size> matrixMultiplication(this->getSize(), 0);

    for (size_t curRowIndex = 0; curRowIndex < this->getSize(); ++curRowIndex) {
        matrixMultiplication[curRowIndex] = (*this)[curRowIndex] + value;
    }
    return matrixMultiplication;
}
