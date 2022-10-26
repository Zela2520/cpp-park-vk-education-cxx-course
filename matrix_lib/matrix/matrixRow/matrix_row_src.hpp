#pragma once // NOLINT

template <typename T, size_t size>
MatrixRow<T, size>::MatrixRow() {
    m_size = size;
    this->m_matrix.fill(0);
}

template <typename T, size_t size>
MatrixRow<T, size>::MatrixRow(size_t _size, T _defaultValue) {
    m_size = _size;
    m_size = size;
    this->m_matrix.fill(_defaultValue);
}

template <typename T, size_t size>
MatrixRow<T, size>::MatrixRow(const std::initializer_list<T> &list) {
    m_size = size;
    size_t index = 0;
    for (const auto& elem : list) {
        m_matrix[index] = elem;
        ++index;
    }
}

template <typename T, size_t size>
MatrixRow<T, size>& MatrixRow<T, size>::operator=(const MatrixRow<T, size>& rhs) {
    if (this->m_matrix.size() != rhs.m_matrix.size()) {
        throw "error";
    }

    for (size_t j = 0; j < rhs.getSize(); ++j) {
        (*this)[j] = rhs[j];
    }

    return *this;
}

template <typename T, size_t size>
T MatrixRow<T, size>::operator[](size_t index) const {
    if (index > m_size) {
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

template <typename T, size_t size>
MatrixRow<T, size> MatrixRow<T, size>::operator+(const MatrixRow<T, size>& rhs) const {
    if (this->getSize() != rhs.getSize()) {
        throw "error";
    }

    MatrixRow<T, size> sumMatrix(this->getSize(), 0);

    for (size_t curRowIndex = 0; curRowIndex < this->getSize(); ++curRowIndex) {
        sumMatrix[curRowIndex] = (*this)[curRowIndex] + rhs[curRowIndex];
    }
    return sumMatrix;
}

template <typename T, size_t size>
MatrixRow<T, size> MatrixRow<T, size>::operator-(const MatrixRow<T, size>& rhs) const {
    if (this->getSize() != rhs.getSize()) {
        throw "error";
    }

    MatrixRow<T, size> matrixSubtraction(this->getSize(), 0);

    for (size_t curRowIndex = 0; curRowIndex < this->getSize(); ++curRowIndex) {
        matrixSubtraction[curRowIndex] = (*this)[curRowIndex] - rhs[curRowIndex];
    }
    return matrixSubtraction;
}

template <typename T, size_t size>
T MatrixRow<T, size>::operator*(const MatrixCol<T, size>& rhs) const {
    if (this->getSize() != rhs.getSize()) {
        throw "error";
    }

    T resMultiplication = 0;

    for (size_t curRowIndex = 0; curRowIndex < this->getSize(); ++curRowIndex) {
        resMultiplication += (*this)[curRowIndex] * rhs[curRowIndex];
    }

    return resMultiplication;
}

template <typename T, size_t size>
MatrixRow<T, size> MatrixRow<T, size>::operator*(T value) const {
    if (!(this->getSize())) {
        throw "error";
    }

    MatrixRow<T, size> matrixMultiplication(this->getSize(), 0);

    for (size_t curRowIndex = 0; curRowIndex < this->getSize(); ++curRowIndex) {
        matrixMultiplication[curRowIndex] = (*this)[curRowIndex] * value;
    }
    return matrixMultiplication;
}

template <typename T, size_t size>
MatrixRow<T, size> MatrixRow<T, size>::operator-(T value) const {
    if (!(this->getSize())) {
        throw "error";
    }

    MatrixRow<T, size> matrixSubtraction(this->getSize(), 0);

    for (size_t curRowIndex = 0; curRowIndex < this->getSize(); ++curRowIndex) {
        matrixSubtraction[curRowIndex] = (*this)[curRowIndex] - value;
    }

    return matrixSubtraction;
}

template <typename T, size_t size>
MatrixRow<T, size> MatrixRow<T, size>::operator+(T value) const {
    if (!(this->getSize())) {
        throw "error";
    }

    MatrixRow<T, size> sumMatrix(this->getSize(), 0);

    for (size_t curRowIndex = 0; curRowIndex < this->getSize(); ++curRowIndex) {
        sumMatrix[curRowIndex] = (*this)[curRowIndex] + value;
    }
    return sumMatrix;
}

template <typename T, size_t size>
MatrixRow<T, size> MatrixRow<T, size>::operator*(const Matrix<T>& rhs) const {
    if (this->getSize() != rhs.getRows() || this->getSize() != rhs.getCols()) {
        throw "error";
    }

    MatrixRow<T, size> matrixMultiplication(rhs.getCols(), 0);

    for (size_t j = 0; j < rhs.getCols(); ++j) {
        T tempRes = 0;
        for (size_t curRow = 0; curRow < rhs.getRows(); ++curRow) {
            tempRes += (*this)[curRow] * rhs(curRow, j);
        }
        matrixMultiplication[j] = tempRes;
    }

    return matrixMultiplication;
}