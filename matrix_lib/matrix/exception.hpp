#ifndef MATRIX_LIB_MATRIX_MATRIX_EXCEPTION_HPP_
#define MATRIX_LIB_MATRIX_MATRIX_EXCEPTION_HPP_

#include <exception>
#include "matrix.hpp"
#include "matrix_col.hpp"
#include "matrix_row.hpp"

class MatrixException : public std::exception {
    public:
        explicit MatrixException(const std::string& msg) : m_message(msg) {}

        const char* what() const noexcept override {
            return m_message.c_str();
        }
    
    private:
        std::string m_message;
};

class InvalidMatrixStream: public MatrixException {
 public:
  InvalidMatrixStream()
      : MatrixException("Error occurred while reading from stream") {}
};

class OutOfRange: public MatrixException {
 public:
  OutOfRange(size_t i, size_t j, const Matrix<double>& matrix)
      : MatrixException(
      "Indexes (" + std::to_string(i) + ", " + std::to_string(j) + ") are out of range. Matrix size is [" +
      std::to_string(matrix.getRows()) + ", " + std::to_string(matrix.getCols()) + "]"
  ) {}
};

// class DimensionMismatch: public MatrixException {
//  public:
//   DimensionMismatch(const Matrix<double>& m1, const Matrix<double>& m2)
//       : MatrixException(
//       "M1[" + std::to_string(m1.getRows()) + ", " + std::to_string(m1.getCols()) + "] and M2[" +
//       std::to_string(m2.getRows()) + ", " + std::to_string(m2.getCols()) + "] are not compatible"
//   ) {}

//   explicit DimensionMismatch(const Matrix<double>& m)
//       : MatrixException(
//       "M[" + std::to_string(m.getRows()) + ", " + std::to_string(m.getCols()) + "] isn't square matrix"
//   ) {}
// };

// class SingularMatrix: public MatrixException {
//  public:
//   SingularMatrix()
//       : MatrixException("Singular matrix") {}
// };

#endif // MATRIX_LIB_MATRIX_EXCEPTION_HPP_