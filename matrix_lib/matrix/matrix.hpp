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
        Matrix<T> operator*(const Matrix<T, row, col>& rhs) const;

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

    Matrix<T> subtractionMatrix(this->m_row, this->m_col);

    for (size_t curRow = 0; curRow < this->m_row; ++curRow) {
        for (size_t curCol = 0; curCol < this->m_col; ++curCol) {
            subtractionMatrix(curRow, curCol) = (*this)(curRow, curCol) - rhs(curRow, curCol);
        }
    }
    return subtractionMatrix;
}

template <typename T, size_t row, size_t col>
Matrix<T> Matrix<T, row, col>::operator*(const Matrix<T, row, col>& rhs) const {
    if (this->getCols() != rhs.getRows()) {
        throw "error";
    }

    Matrix<T> multiplicationMatrix(this->m_row, rhs.m_col);

    for (size_t curRow = 0; curRow < this->m_row; ++curRow) {
        for (size_t curCol = 0; curCol < rhs.m_col; ++curCol) {
            for (size_t k = 0; k < this->m_col; ++k) {
                multiplicationMatrix(curRow, curCol) += (*this)(curRow, k) * rhs(k, curCol);
            }
        }
    }

    return multiplicationMatrix;
}

template <typename T, size_t row, size_t col>
Matrix<T> Matrix<T, row, col>::operator*(T val) const {
    Matrix<T> multiplicationMatrix(this->m_row, this->m_col);

    for (size_t curRow = 0; curRow < this->m_row; ++curRow) {
        for (size_t curCol = 0; curCol < this->m_col; ++curCol) {
            multiplicationMatrix(curRow, curCol) = (*this)(curRow, curCol) * val;
        }
    }
    return multiplicationMatrix;
}

template <typename T, size_t row, size_t col>
Matrix<T> Matrix<T, row, col>::transp() const {
    Matrix<T> transpMatrix(this->m_row, this->m_col);

    for (size_t curRow = 0; curRow < this->m_row; ++curRow) {
        for (size_t curCol = 0; curCol < this->m_col; ++curCol) {
            transpMatrix(curCol, curRow) = (*this)(curRow, curCol);
        }
    }
    return transpMatrix;
}

template <typename T1, size_t N, size_t M>
void fillMinor(const Matrix<T1, N, M>& matrix, size_t del_row, size_t del_col, Matrix<double>* new_matrix) {
    size_t miss_rows = 0;

    for (size_t i = 0; i < matrix.getRows(); ++i) {
        if (i != del_row) {
            size_t miss_cols = 0;

            for (size_t j = 0; j < matrix.getCols(); ++j) {
                if (del_col != j) {
                    (*new_matrix)(i - miss_rows, j - miss_cols) = matrix(i, j);
                } else {
                    ++miss_cols;
                }
            }
        } else {
            ++miss_rows;
        }
    }
}

template <typename T, size_t row, size_t col>
T Matrix<T, row, col>::det() const {
    if (this->getRows() != this->getCols()) {
        throw "the real slim shady please stand up";
    }

    if (this->getRows() == 1) {
        return (*this)(0,0);
    } else if (this->getRows() == 2) {
        return (((*this)(0,0) * (*this)(1,1))
        - ((*this)(0,1) * (*this)(1,0)));
    }

    Matrix<T> minor_matrix(this->getRows() - 1, this->getCols() - 1);
    double sum_res = 0;
    int sig_n = 1;

    for (size_t curCol = 0; curCol < this->getCols(); ++curCol) {
        fillMinor((*this), 0, curCol, &minor_matrix);
        double temp_res = minor_matrix.det() * (*this)(0, curCol);
        sum_res += sig_n * temp_res;
        sig_n *= -1;
    }
    return sum_res;
}

template <typename T2, size_t N1, size_t M1>
Matrix<T2> returnFilledMinor(const Matrix<T2, N1, M1>& matrix, size_t del_row, size_t del_col, Matrix<T2>* new_matrix) {
    size_t miss_rows = 0;

    for (size_t i = 0; i < matrix.getRows(); ++i) {
        if (i != del_row) {
            size_t miss_cols = 0;

            for (size_t j = 0; j < matrix.getCols(); ++j) {
                if (del_col != j) {
                    (*new_matrix)(i - miss_rows, j - miss_cols) = matrix(i, j);
                } else {
                    ++miss_cols;
                }
            }
        } else {
            ++miss_rows;
        }
    }

    return *new_matrix;
}

template <typename T, size_t row, size_t col>
Matrix<T> Matrix<T, row, col>::adj() const {
    if (this->getRows() != this->getCols()) {
        throw "i repeat will the real slim shady please stand up";
    }

    const Matrix<T>& transpon_matrix = transp();
    Matrix<T> new_matrix(this->getRows(), this->getCols());
    Matrix<T> minor_matrix(this->getRows() - 1, this->getCols() - 1);

    for (size_t i = 0; i < transpon_matrix.getRows(); ++i) {
        for (size_t j = 0; j < transpon_matrix.getCols(); ++j) {
            double minor_res = 0.0;
            minor_res = returnFilledMinor(transpon_matrix, i, j, &minor_matrix).det();
            int minor_sign = 1;

            if (((i + 1) + (j + 1)) % 2 == TRUE) {
                minor_sign = -1;
            }
            new_matrix(i, j) = std::trunc((minor_res * minor_sign) * eps) / eps;
        }
    }
    return new_matrix;
}

template <typename T, size_t row, size_t col>
Matrix<T> Matrix<T, row, col>::inv() const {
    if (this->getRows() != this->getCols()) {
        throw "don't do it just don't do it ";
    }

    double det_matrix = det();

    if (det_matrix == 0) {
        throw "don't do it just don't do it ";
    }

    if (this->getRows() == 1) {
        Matrix<T> newmatrix(1, 1);
        newmatrix(0, 0) = 1 / (*this)(0, 0);
        return newmatrix;
    }

    const Matrix<T>& adj_matrix = adj();
    Matrix<T> newmatrix(this->getRows(), this->getCols());

    for (size_t i = 0; i < newmatrix.getRows(); ++i) {
        for (size_t j = 0; j < newmatrix.getCols(); ++j) {
            newmatrix(i, j) =  std::trunc((adj_matrix(i, j) / det_matrix) * eps) / eps;
        }
    }
    return newmatrix;
}

#endif // MATRIX_LIB_MATRIX_MATRIX_HPP_
