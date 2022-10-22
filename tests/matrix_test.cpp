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
