#ifndef INT_MATRIX_HPP_
#define INTERFACE_MATRIX_HPP_

#include <cstdint>
#include <unistd.h>

class MatrixInterface {
    public:
        virtual ~MatrixInterface() = default;
        virtual void createMatrix() = 0;
        virtual MatrixInterface& operator=(const MatrixInterface& rhs) = 0;

        virtual size_t getRows() const;
        virtual size_t getCols() const;

        virtual double operator()(size_t row, size_t col) const;
        virtual double& operator()(size_t row, size_t col);

        virtual bool operator==(const MatrixInterface& rhs) const;
        virtual bool operator!=(const MatrixInterface& rhs) const;

        MatrixInterface operator+(const MatrixInterface& rhs) const;
        MatrixInterface operator-(const MatrixInterface& rhs) const;
        MatrixInterface operator*(const MatrixInterface& rhs) const;

        MatrixInterface operator*(double val) const;

        virtual MatrixInterface transp() const;
        virtual double det() const;
        virtual MatrixInterface adj() const;
        virtual MatrixInterface inv() const;
};


class Matrix : public MatrixInterface {
    
};

class MatrixCol : public MatrixInterface {

};


class MatrixRow : public MatrixInterface {

};

#endif  // INTERFACE_MATRIX_HPP_