#include "gtest/gtest.h"

#include "exception.hpp"
#include "utils.hpp"


TEST(MatrixLib, ConstructorTest) {
    Matrix<double> matrix(3, 4);
    EXPECT_EQ(12, matrix.getSize());

    Matrix<double, 3, 4> matrix1;
    EXPECT_EQ(12, matrix1.getSize());

    Matrix<double, 3, 4> matrix2({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
    double curElemValue = 1;
    for (size_t row = 0; row < matrix.getRows(); ++row) {
        for (size_t col = 0; col < matrix.getCols(); ++col) {
            EXPECT_EQ(curElemValue, matrix2(row, col));
            ++curElemValue;
        }
    }
}

TEST(MatrixLib, AccessToMatrixElementsTest) {
    Matrix<double, 3, 4> matrix({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
    EXPECT_EQ(4, matrix(1, 1));
}

TEST(MatrixLib, GetDiagonalTest) {

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
