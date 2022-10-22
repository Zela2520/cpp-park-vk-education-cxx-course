#include "gtest/gtest.h"

#include "exception.hpp"
#include "utils.hpp"


TEST(MatrixLib, ConstructorTest) {
    Matrix<double> matrix(3, 4);
    EXPECT_EQ(12, matrix.getSize());

    Matrix<double, 3, 4> matrix1;
    EXPECT_EQ(12, matrix1.getSize());

    Matrix<double, 6, 2> matrix2({  1, 2,
                                    3, 4, 
                                    5, 6,
                                    7, 8,
                                    9, 10,
                                    11, 12}
                                );

    EXPECT_EQ(1, matrix2(0, 0));
    EXPECT_EQ(2, matrix2(0, 1));                                
    EXPECT_EQ(3, matrix2(1, 0));
    EXPECT_EQ(4, matrix2(1, 1));
    EXPECT_EQ(5, matrix2(2, 0));
    EXPECT_EQ(6, matrix2(2, 1));                                
    EXPECT_EQ(7, matrix2(3, 0));
    EXPECT_EQ(8, matrix2(3, 1));
    EXPECT_EQ(9, matrix2(4, 0));
    EXPECT_EQ(10, matrix2(4, 1));                                
    EXPECT_EQ(11, matrix2(5, 0));
    EXPECT_EQ(12, matrix2(5, 1));

    EXPECT_EQ(6, matrix2.getRows());
    EXPECT_EQ(2, matrix2.getCols());
}

TEST(MatrixLib, AccessToMatrixElementsTest) {
    Matrix<double, 3, 4> matrix({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
    EXPECT_EQ(6, matrix(1, 1));
}

TEST(MatrixLib, getDiagonalTest) {
    Matrix<double, 4, 4> matrix({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16});
    MatrixRow<double> vectorRow = matrix.getDiagonal();

    EXPECT_EQ(1, vectorRow[0]);
    EXPECT_EQ(6, vectorRow[1]);
    EXPECT_EQ(11, vectorRow[2]);
    EXPECT_EQ(16, vectorRow[3]);
}

TEST(MatrixLib, getRowTest) {
    Matrix<double, 3, 4> matrix({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});

    MatrixRow<double> vectorRow1 = matrix.getRow(0);
    EXPECT_EQ(1, vectorRow1[0]);
    EXPECT_EQ(2, vectorRow1[1]);
    EXPECT_EQ(3, vectorRow1[2]);
    EXPECT_EQ(4, vectorRow1[3]);

    MatrixRow<double> vectorRow2 = matrix.getRow(1);
    EXPECT_EQ(5, vectorRow2[0]);
    EXPECT_EQ(6, vectorRow2[1]);
    EXPECT_EQ(7, vectorRow2[2]);
    EXPECT_EQ(8, vectorRow2[3]);

    MatrixRow<double> vectorRow3 = matrix.getRow(2);
    EXPECT_EQ(9, vectorRow3[0]);
    EXPECT_EQ(10, vectorRow3[1]);
    EXPECT_EQ(11, vectorRow3[2]);
    EXPECT_EQ(12, vectorRow3[3]);
}

TEST(MatrixLib, getColTest) {
    Matrix<double, 3, 4> matrix({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});

    MatrixCol<double> vectorCol1 = matrix.getCol(0);
    EXPECT_EQ(1, vectorCol1[0]);
    EXPECT_EQ(5, vectorCol1[1]);
    EXPECT_EQ(9, vectorCol1[2]);

    MatrixCol<double> vectorCol2 = matrix.getCol(1);
    EXPECT_EQ(2, vectorCol2[0]);
    EXPECT_EQ(6, vectorCol2[1]);
    EXPECT_EQ(10, vectorCol2[2]);

    MatrixCol<double> vectorCol3 = matrix.getCol(2);
    EXPECT_EQ(3, vectorCol3[0]);
    EXPECT_EQ(7, vectorCol3[1]);
    EXPECT_EQ(11, vectorCol3[2]);

    MatrixCol<double> vectorCol4 = matrix.getCol(3);
    EXPECT_EQ(4, vectorCol4[0]);
    EXPECT_EQ(8, vectorCol4[1]);
    EXPECT_EQ(12, vectorCol4[2]);
}

TEST(MatrixRow, ConstructorTest) {
    MatrixRow<double> matrix(3, 4);
    EXPECT_EQ(3, matrix.getSize());
    double expectValue = 4;
    for (size_t index = 0; index < matrix.getSize(); ++index) {
        EXPECT_EQ(expectValue, matrix[index]);
    }

    MatrixRow<double> matrix1({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
    double curValue = 1;
    for (size_t index = 0; index < matrix1.getSize(); ++index) {
        EXPECT_EQ(curValue, matrix1[index]);
        ++curValue;
    }

    MatrixRow<double, 4> matrix2;
    EXPECT_EQ(4, matrix2.getSize());
    double initValue = 0;
    for (size_t index = 0; index < matrix2.getSize(); ++index) {
        EXPECT_EQ(initValue, matrix2[index]);
    }
}

TEST(MatrixRow, AccessToMatrixElementsTest) {
    MatrixCol<double> matrix1({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
    EXPECT_EQ(7, matrix1[6]);
}

TEST(MatrixCol, ConstructorTest) {
    MatrixCol<double> matrix(3, 4);
    EXPECT_EQ(3, matrix.getSize());
    double expectValue = 4;
    for (size_t index = 0; index < matrix.getSize(); ++index) {
        EXPECT_EQ(expectValue, matrix[index]);
    }

    MatrixCol<double> matrix1({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
    double curValue = 1;
    for (size_t index = 0; index < matrix1.getSize(); ++index) {
        EXPECT_EQ(curValue, matrix1[index]);
        ++curValue;
    }

    MatrixCol<double, 4> matrix2;
    EXPECT_EQ(4, matrix2.getSize());
    double initValue = 0;
    for (size_t index = 0; index < matrix2.getSize(); ++index) {
        EXPECT_EQ(initValue, matrix2[index]);
    }
}

TEST(MatrixCol, AccessToMatrixElementsTest) {
    MatrixCol<double> matrix1({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
    EXPECT_EQ(7, matrix1[6]);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
