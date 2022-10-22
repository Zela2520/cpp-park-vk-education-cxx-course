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

#define EPS (std::numeric_limits<double>::epsilon()*1e-07)
#define eps 1e7
#define TRUE 1

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
class MatrixCol;
/////////////////////////////////////Matrix row////////////////////////////////////////////////
template <typename T = double, size_t size = 1>
class MatrixRow {
    public:
        MatrixRow();
        MatrixRow(size_t _size, T _dafaultValue);
        explicit MatrixRow(const std::initializer_list<T> &list);
        MatrixRow(const MatrixRow& rhs) = default;
        MatrixRow& operator=(const MatrixRow& rhs);
        ~MatrixRow() = default; 
        
        size_t getSize() const {return m_matrix.size();};
        
        T operator[](size_t index) const;
        T& operator[](size_t index);
        
        
        bool operator==(const MatrixRow& rhs) const;
        bool operator!=(const MatrixRow& rhs) const;
        
        MatrixRow operator+(const MatrixRow& rhs) const;
        MatrixRow operator-(const MatrixRow& rhs) const;
        
        
        MatrixRow operator*(int value) const;
        
    private:
        std::vector<T> m_matrix;
        size_t m_size;
};

template <typename T, size_t size>
MatrixRow<T, size>::MatrixRow() {
    m_size = size;
    this->m_matrix.resize(size, 0);
}

template <typename T, size_t size>
MatrixRow<T, size>::MatrixRow(size_t _size, T _dafaultValue) : m_size(_size) {
    this->m_matrix.resize(this->m_size, _dafaultValue);
}

template <typename T, size_t size>
MatrixRow<T, size>::MatrixRow(const std::initializer_list<T> &list) {
    // auto l = list.begin();
    // for (size_t i = 0; i < list.size(); ++i) {
    //     m_matrix[i] = *l;
    //     ++l;
    // }
    for (const auto &elem : list) {
        m_matrix.push_back(elem);
    }
    m_size = m_matrix.size();
}

template <typename T, size_t size>
MatrixRow<T, size>& MatrixRow<T, size>::operator=(const MatrixRow& rhs) {
    this->m_size = rhs.m_size;
    this->m_matrix.resize(m_size, 0);
    size_t i = 0;
    for (auto& elem : rhs.m_matrix) {
        this->m_matrix[i] = elem;
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
        
        bool operator==(const MatrixCol& rhs) const;
        bool operator!=(const MatrixCol& rhs) const;
        
        MatrixCol operator+(const MatrixCol& rhs) const;
        MatrixCol operator-(const MatrixCol& rhs) const;
        
        
        MatrixCol operator*(int value) const;
    
    private:
        std::vector<T> m_matrix;
        size_t m_size;
};

template <typename T, size_t size>
MatrixCol<T, size>::MatrixCol() {
    m_size = size;
    this->m_matrix.resize(size, 0);
}

template <typename T, size_t size>
MatrixCol<T, size>::MatrixCol(size_t _size, T _dafaultValue) : m_size(_size) {
    this->m_matrix.resize(this->m_size, _dafaultValue);
}

template <typename T, size_t size>
MatrixCol<T, size>::MatrixCol(const std::initializer_list<T> &list) {
    // auto l = list.begin();
    // for (size_t i = 0; i < list.size(); ++i) {
    //     m_matrix[i] = *l;
    //     ++l;
    // }
    for (const auto &elem : list) {
        m_matrix.push_back(elem);
    }
    m_size = m_matrix.size();
}

template <typename T, size_t size>
MatrixCol<T, size>& MatrixCol<T, size>::operator=(const MatrixCol& rhs) {
    this->m_size = rhs.m_size;
    this->m_matrix.resize(m_size, 0);
    size_t i = 0;
    for (auto& elem : rhs.m_matrix) {
        this->m_matrix[i] = elem;
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
















///////////////////////////////////////Simple matrix////////////////////////////////////////////////  
template <typename T = double, size_t row = 1, size_t col = 1>
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

        double operator()(size_t cur_row, size_t cur_col) const;
        double& operator()(size_t cur_row, size_t cur_col);

        // извлечение диагонали строки или столбца 
        MatrixRow<T> getDiagonal();
        MatrixRow<T> getRow(size_t rowNumber);
        MatrixCol<T> getCol(size_t colNumber);
        // 

        bool operator==(const Matrix<T, row, col>& rhs) const;
        bool operator!=(const Matrix<T, row, col>& rhs) const;

        Matrix<T> operator+(const Matrix<T, row, col>& rhs) const;
        Matrix<T> operator-(const Matrix<T, row, col>& rhs) const;
        Matrix operator*(const Matrix<T, row, col>& rhs) const;

        Matrix operator*(double val) const;

        // friend
        // Matrix operator*(double val, const Matrix& matrix);
        // friend
        // void fill_minor(const Matrix& matrix, size_t del_row, size_t del_col, Matrix* new_matrix);
        // friend
        // Matrix return_filled_minor(const Matrix& matrix, size_t del_row, size_t del_col, Matrix* new_matrix);

        Matrix transp() const;
        double det() const;
        Matrix adj() const;
        Matrix inv() const;

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
    m_row = row;
    m_col = col;
    for (auto &elem : list) {
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
double& Matrix<T, row, col>::operator()(size_t cur_row, size_t cur_col) {
    if (this->getRows() <= cur_row || this->getCols() <= cur_col) {
        throw "Out of range error";
    }

    return this->m_matrix[(cur_row * this->m_col) + cur_col];
}

template <typename T, size_t row, size_t col>
MatrixRow<T> Matrix<T, row, col>::getDiagonal() {
    try {
        if (m_col != m_row) {
            throw "error";
        }
    } catch (std::string& error) {
        std::cout << error << std::endl;
    }


    MatrixRow<T> mainDiagonal(this->m_col, 0);
    for (size_t i = 0; i < mainDiagonal.getSize(); ++i) {
        mainDiagonal[i] = (*this)(i, i);
    }

    return mainDiagonal;
}

template <typename T, size_t row, size_t col>
MatrixRow<T> Matrix<T, row, col>::getRow(size_t rowNumber) {
    try {
        if (rowNumber >= m_row) {
            throw "errror";
        }
    } catch (std::string& error) {
        std::cout << error << std::endl;
    }

    MatrixRow<T> vectorRow(this->m_col, 0);
    size_t index = 0;
    for (size_t curCol = 0; curCol < this->m_col; ++curCol) {
        vectorRow[index] = this->m_matrix[rowNumber * this->m_col + curCol];
        ++index;
    }

    return vectorRow;
}

template <typename T, size_t row, size_t col>
MatrixCol<T> Matrix<T, row, col>::getCol(size_t colNumber) {
    try {
        if (colNumber >= m_col) {
            throw "errror";
        }
    } catch (std::string& error) {
        std::cout << error << std::endl;
    }

    MatrixCol<T> vectorCol(this->m_row, 0);
    size_t index = 0;
    for (size_t curRow = 0; curRow < this->m_row; ++curRow) {
        vectorCol[index] = this->m_matrix[curRow * this->m_col + colNumber];
        ++index;
    }

    return vectorCol;
}

template <typename T, size_t row, size_t col>
bool Matrix<T, row, col>::operator==(const Matrix<T, row, col>& rhs) const {
    bool is_equal = true;

    if (this->getRows() != rhs.getRows() || this->getCols() != rhs.getCols()) {
        return false;
    }

    for (size_t curRow = 0; curRow < this->getRows(); ++curRow) {
        if (is_equal == false) {
            break;
        }

        for (size_t curCol = 0; curCol < this->getCols(); ++curCol) {
            if (std::abs((this->m_matrix[curRow * this->m_col + curCol] - rhs.m_matrix[curRow * this->m_col + curCol])) > EPS) {
                is_equal = false;
                break;
            }
        }
    }

    return is_equal;
}
template <typename T, size_t row, size_t col>
bool Matrix<T, row, col>::operator!=(const Matrix<T, row, col>& rhs) const {
    bool is_equal = false;

    if (this->getRows() != rhs.getRows() || this->getCols() != rhs.getCols()) {
        return true;
    }

    for (size_t curRow = 0; curRow < this->getRows(); ++curRow) {
        if (is_equal == true) {
            break;
        }

        for (size_t curCol = 0; curCol < this->getCols(); ++curCol) {
            if (std::abs((this->m_matrix[curRow * this->m_col + curCol] - rhs.m_matrix[curRow * this->m_col + curCol])) < EPS) {
                is_equal = true;
                break;
            }
        }
    }
    return is_equal;
}

template <typename T, size_t row, size_t col>
Matrix<T> Matrix<T, row, col>::operator+(const Matrix<T, row, col>& rhs) const {
    if (this->getRows() != rhs.getRows() || this->getCols() != rhs.getCols()) {
        throw "error";
    }

    Matrix<T> sumMatrix(this->m_row, this->m_col);

    for (size_t curRow = 0; curRow < this->m_row; ++curRow) {
        for (size_t curCol = 0; curCol < this->m_col; ++curCol) {
            sumMatrix(curRow, curCol) = (*this)(curRow, curCol) + rhs(curRow, curCol);
        }
    }
    return sumMatrix;
}

template <typename T, size_t row, size_t col>
Matrix<T> Matrix<T, row, col>::operator-(const Matrix<T, row, col>& rhs) const {
    if (this->getRows() != rhs.getRows() || this->getCols() != rhs.getCols()) {
        throw "error";
    }

    Matrix<T> sumMatrix(this->m_row, this->m_col);

    for (size_t curRow = 0; curRow < this->m_row; ++curRow) {
        for (size_t curCol = 0; curCol < this->m_col; ++curCol) {
            sumMatrix(curRow, curCol) = (*this)(curRow, curCol) - rhs(curRow, curCol);
        }
    }
    return sumMatrix;
}

// template <typename T, size_t row, size_t col>
// Matrix operator*(const Matrix& rhs) const {

// }

// template <typename T, size_t row, size_t col>
// Matrix operator*(double val) const {

// }

#endif // MATRIX_LIB_MATRIX_MATRIX_HPP_
