#include "gtest/gtest.h"

#include "exception.hpp"
#include <iostream>


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
    MatrixRow<double, 4> vectorRow = matrix.getDiagonal();
    EXPECT_EQ(4, vectorRow.getSize());

    EXPECT_EQ(1, vectorRow[0]);
    EXPECT_EQ(6, vectorRow[1]);
    EXPECT_EQ(11, vectorRow[2]);
    EXPECT_EQ(16, vectorRow[3]);
}

TEST(MatrixLib, getRowTest) {
    Matrix<double, 3, 4> matrix({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});

    MatrixRow<double, 4> vectorRow1 = matrix.getRow(0);
    EXPECT_EQ(1, vectorRow1[0]);
    EXPECT_EQ(2, vectorRow1[1]);
    EXPECT_EQ(3, vectorRow1[2]);
    EXPECT_EQ(4, vectorRow1[3]);

    MatrixRow<double, 4> vectorRow2 = matrix.getRow(1);
    EXPECT_EQ(5, vectorRow2[0]);
    EXPECT_EQ(6, vectorRow2[1]);
    EXPECT_EQ(7, vectorRow2[2]);
    EXPECT_EQ(8, vectorRow2[3]);

    MatrixRow<double, 4> vectorRow3 = matrix.getRow(2);
    EXPECT_EQ(9, vectorRow3[0]);
    EXPECT_EQ(10, vectorRow3[1]);
    EXPECT_EQ(11, vectorRow3[2]);
    EXPECT_EQ(12, vectorRow3[3]);
}

TEST(MatrixLib, getColTest) {
    Matrix<double, 3, 4> matrix({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});

    MatrixCol<double, 3> vectorCol1 = matrix.getCol(0);
    EXPECT_EQ(1, vectorCol1[0]);
    EXPECT_EQ(5, vectorCol1[1]);
    EXPECT_EQ(9, vectorCol1[2]);

    MatrixCol<double, 3> vectorCol2 = matrix.getCol(1);
    EXPECT_EQ(2, vectorCol2[0]);
    EXPECT_EQ(6, vectorCol2[1]);
    EXPECT_EQ(10, vectorCol2[2]);

    MatrixCol<double, 3> vectorCol3 = matrix.getCol(2);
    EXPECT_EQ(3, vectorCol3[0]);
    EXPECT_EQ(7, vectorCol3[1]);
    EXPECT_EQ(11, vectorCol3[2]);

    MatrixCol<double, 3> vectorCol4 = matrix.getCol(3);
    EXPECT_EQ(4, vectorCol4[0]);
    EXPECT_EQ(8, vectorCol4[1]);
    EXPECT_EQ(12, vectorCol4[2]);
}

TEST(MatrixLib, MatrixComparisonTest) {
    Matrix<double, 3, 4> matrix1({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
    Matrix<double, 3, 4> matrix2({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});

    bool comparisonResult = false;
    if (matrix1 == matrix2) {
        comparisonResult = true;
    }

    EXPECT_TRUE(comparisonResult == true);

    comparisonResult = false;

    matrix1(0, 0) = 2;
    MatrixCol<double, 3> vectorCol1 = matrix1.getCol(0);
    EXPECT_EQ(2, vectorCol1[0]);
    EXPECT_EQ(5, vectorCol1[1]);
    EXPECT_EQ(9, vectorCol1[2]);

    if (matrix1 != matrix2) {
        comparisonResult = true;
    }

    EXPECT_TRUE(comparisonResult == true);
}

TEST(MatrixLib, MatrixSumTest) {
    Matrix<double, 3, 4> matrix1;
    Matrix<double, 3, 4> matrix2;

    double initValue = 1;
    for (size_t curRow = 0; curRow < matrix1.getRows(); ++curRow) {
        for (size_t curCol = 0; curCol < matrix1.getCols(); ++curCol) {
            matrix1(curRow, curCol) = initValue;
            matrix2(curRow, curCol) = initValue;
            ++initValue;
        }
    }

    Matrix<double, 3, 4> sumMatrix;
    sumMatrix = matrix1 + matrix2;

    MatrixCol<double, 3> vectorCol1 = sumMatrix.getCol(0);

    EXPECT_EQ(2, vectorCol1[0]);
    EXPECT_EQ(10, vectorCol1[1]);
    EXPECT_EQ(18, vectorCol1[2]);

    MatrixCol<double, 3> vectorCol2 = sumMatrix.getCol(1);
    EXPECT_EQ(4, vectorCol2[0]);
    EXPECT_EQ(12, vectorCol2[1]);
    EXPECT_EQ(20, vectorCol2[2]);

    MatrixCol<double, 3> vectorCol3 = sumMatrix.getCol(2);
    EXPECT_EQ(6, vectorCol3[0]);
    EXPECT_EQ(14, vectorCol3[1]);
    EXPECT_EQ(22, vectorCol3[2]);

    MatrixCol<double, 3> vectorCol4 = sumMatrix.getCol(3);
    EXPECT_EQ(8, vectorCol4[0]);
    EXPECT_EQ(16, vectorCol4[1]);
    EXPECT_EQ(24, vectorCol4[2]);
}

TEST(MatrixLib, MatrixSubtractionTest) {
    Matrix<double, 3, 4> matrix1;
    Matrix<double, 3, 4> matrix2;

    double initValue = 1;
    for (size_t curRow = 0; curRow < matrix1.getRows(); ++curRow) {
        for (size_t curCol = 0; curCol < matrix1.getCols(); ++curCol) {
            matrix1(curRow, curCol) = initValue;
            matrix2(curRow, curCol) = initValue;
            ++initValue;
        }
    }

    Matrix<double> subtractionMatrix(matrix1.getRows(), matrix1.getCols());
    subtractionMatrix = matrix1 - matrix2;

    for (size_t curRow = 0; curRow < matrix1.getRows(); ++curRow) {
        for (size_t curCol = 0; curCol < matrix1.getCols(); ++curCol) {
            EXPECT_EQ(0, subtractionMatrix(curRow, curCol));
        }
    }
}

TEST(MatrixLib, addValueToMatrix) {
    Matrix<double, 2, 2> matrix1;
    double initValue = 1;
    for (size_t curRow = 0; curRow < matrix1.getRows(); ++curRow) {
        for (size_t curCol = 0; curCol < matrix1.getCols(); ++curCol) {
            matrix1(curRow, curCol) = initValue;
            ++initValue;
        }
    }

    Matrix<double> resMatrix(matrix1.getRows(), matrix1.getCols());
    resMatrix = matrix1 + 3;

    EXPECT_EQ(4, resMatrix(0, 0));
    EXPECT_EQ(5, resMatrix(0, 1));
    EXPECT_EQ(6, resMatrix(1, 0));
    EXPECT_EQ(7, resMatrix(1, 1));
}

TEST(MatrixLib, subtractValueToMatrix) {
    Matrix<double, 2, 2> matrix1;
    double initValue = 1;
    for (size_t curRow = 0; curRow < matrix1.getRows(); ++curRow) {
        for (size_t curCol = 0; curCol < matrix1.getCols(); ++curCol) {
            matrix1(curRow, curCol) = initValue;
            ++initValue;
        }
    }

    Matrix<double> resMatrix(matrix1.getRows(), matrix1.getCols());
    resMatrix = matrix1 - 3;

    EXPECT_EQ(-2, resMatrix(0, 0));
    EXPECT_EQ(-1, resMatrix(0, 1));
    EXPECT_EQ(0, resMatrix(1, 0));
    EXPECT_EQ(1, resMatrix(1, 1));
}

TEST(MatrixLib, multiplyValueToMatrix) {
    Matrix<double, 2, 2> matrix1;
    double initValue = 1;
    for (size_t curRow = 0; curRow < matrix1.getRows(); ++curRow) {
        for (size_t curCol = 0; curCol < matrix1.getCols(); ++curCol) {
            matrix1(curRow, curCol) = initValue;
            ++initValue;
        }
    }

    Matrix<double> resMatrix(matrix1.getRows(), matrix1.getCols());
    resMatrix = matrix1 * 3;

    EXPECT_EQ(3, resMatrix(0, 0));
    EXPECT_EQ(6, resMatrix(0, 1));
    EXPECT_EQ(9, resMatrix(1, 0));
    EXPECT_EQ(12, resMatrix(1, 1));
}

TEST(MatrixLib, multiplyMatrixToVectorCol) {
    Matrix<double, 4, 4> matrix1({
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12,
        13, 14, 15, 16
    });

    MatrixCol<double, 4> matrixCol(4, 0);
    double initValue2 = 1;
    for (size_t index = 0; index < matrixCol.getSize(); ++index) {
        matrixCol[index] = initValue2;
        ++initValue2;
    };

    MatrixCol<double, 4> resMatrix(4, 0);
    resMatrix = matrix1 * matrixCol;

    EXPECT_EQ(30, resMatrix[0]);
    EXPECT_EQ(70, resMatrix[1]);
    EXPECT_EQ(110, resMatrix[2]);
    EXPECT_EQ(150, resMatrix[3]);
}

TEST(MatrixLib, MatrixMultiplicationTest) {
    Matrix<double, 4, 4> matrix1;
    Matrix<double, 4, 4> matrix2;

    double initValue = 1;
    for (size_t curRow = 0; curRow < matrix1.getRows(); ++curRow) {
        for (size_t curCol = 0; curCol < matrix1.getCols(); ++curCol) {
            matrix1(curRow, curCol) = initValue;
            matrix2(curRow, curCol) = initValue;
            ++initValue;
        }
    }

    Matrix<double, 4, 4> multiplicationMatrix;
    multiplicationMatrix = matrix1 * matrix2;

    MatrixRow<double, 4> vectorRow = multiplicationMatrix.getDiagonal();

    EXPECT_EQ(90, vectorRow[0]);
    EXPECT_EQ(228, vectorRow[1]);
    EXPECT_EQ(398, vectorRow[2]);
    EXPECT_EQ(600, vectorRow[3]);
}

TEST(MatrixLib, MatrixRightMultiplicationTest) {
    Matrix<double, 4, 4> matrix1;

    double initValue = 1;
    for (size_t curRow = 0; curRow < matrix1.getRows(); ++curRow) {
        for (size_t curCol = 0; curCol < matrix1.getCols(); ++curCol) {
            matrix1(curRow, curCol) = initValue;
            ++initValue;
        }
    }

    Matrix<double, 4, 4> rightMultiplicationMatrix;
    rightMultiplicationMatrix = matrix1 * 3;

    MatrixRow<double, 4> vectorRow = rightMultiplicationMatrix.getDiagonal();

    EXPECT_EQ(3, vectorRow[0]);
    EXPECT_EQ(18, vectorRow[1]);
    EXPECT_EQ(33, vectorRow[2]);
    EXPECT_EQ(48, vectorRow[3]);
}

TEST(MatrixLib, MatrixLeftMultiplicationTest) {
    Matrix<double, 4, 4> matrix1;

    double initValue = 1;
    for (size_t curRow = 0; curRow < matrix1.getRows(); ++curRow) {
        for (size_t curCol = 0; curCol < matrix1.getCols(); ++curCol) {
            matrix1(curRow, curCol) = initValue;
            ++initValue;
        }
    }

    Matrix<double, 4, 4> leftMultiplicationMatrix;
    leftMultiplicationMatrix = 3 * matrix1;

    MatrixRow<double, 4> vectorRow = leftMultiplicationMatrix.getDiagonal();

    EXPECT_EQ(3, vectorRow[0]);
    EXPECT_EQ(18, vectorRow[1]);
    EXPECT_EQ(33, vectorRow[2]);
    EXPECT_EQ(48, vectorRow[3]);
}

TEST(MatrixLib, TranspMatrixTest) {
    Matrix<double, 4, 4> matrix1({  1, 2, 3, 4,
                                    5, 6, 7, 8,
                                    9, 10, 11, 12,
                                    13, 14, 15, 16}
                                );

    Matrix<double, 4, 4> matrix2({  1, 5, 9, 13,
                                    2, 6, 10, 14,
                                    3, 7, 11, 15,
                                    4, 8, 12, 16}
                                );                                

    Matrix<double> transpMatrix(matrix1.getRows(), matrix1.getCols());
    transpMatrix = matrix1.transp();

    for (size_t curRow = 0; curRow < matrix1.getRows(); ++curRow) {
        for (size_t curCol = 0; curCol < matrix1.getCols(); ++curCol) {
            EXPECT_EQ(matrix2(curRow, curCol), transpMatrix(curRow, curCol));
        }
    }
}

TEST(MatrixLib, DetMatrixTest) {
    Matrix<double, 2, 2> matrix1({1, 2,
                                5, 16});
    double det = matrix1.det();
    EXPECT_EQ(6, det);

    Matrix<double, 3, 3> matrix2({1, 2, 3,
                                5, 16, 1,
                                -1, 2, 2});
    double det2 = matrix2.det();
    EXPECT_EQ(86, det2);

    Matrix<double, 4, 4> matrix3({1, 2, 3, 5,
                                16, 1, -1, 2,
                                2, 8, 9, 10,
                                1, -1, 6, 2});
    double det3 = matrix3.det();
    EXPECT_EQ(-1947, det3);
}

TEST(MatrixLib, AdjMatrixTest) {
    Matrix<double, 2, 2> matrix1({1, 2,
                                5, 16});

    Matrix<double, 2, 2> matrix2({ 16, -2,
                                   -5, 1}
                                );                                 

    Matrix<double> adjMatrix(matrix1.getRows(), matrix1.getCols());
    adjMatrix = matrix1.adj();

    for (size_t curRow = 0; curRow < matrix1.getRows(); ++curRow) {
        for (size_t curCol = 0; curCol < matrix1.getCols(); ++curCol) {
            EXPECT_EQ(matrix2(curRow, curCol), adjMatrix(curRow, curCol));
        }
    }


    Matrix<double, 3, 3> matrix3({1, 2, 3,
                                5, 16, 1,
                                -1, 2, 2});

    Matrix<double, 3, 3> matrix4({30, 2, -46,
                                -11, 5, 14,
                                26, -4, 6});                                

    Matrix<double> adjMatrix2(matrix3.getRows(), matrix3.getCols());
    adjMatrix2 = matrix3.adj();

    for (size_t curRow = 0; curRow < matrix3.getRows(); ++curRow) {
        for (size_t curCol = 0; curCol < matrix3.getCols(); ++curCol) {
            EXPECT_EQ(matrix4(curRow, curCol), adjMatrix2(curRow, curCol));
        }
    }


    Matrix<double, 4, 4> matrix5({1, 2, 3, 5,
                                16, 1, -1, 2,
                                2, 8, 9, 10,
                                1, -1, 6, 2});

    Matrix<double, 4, 4> matrix6({98, -123, -15, -47,
                                672, -9, -381, 234,
                                402, 12, -141, -312,
                                -919, 21, 240, 103});

    Matrix<double> adjMatrix3(matrix5.getRows(), matrix5.getCols());
    adjMatrix3 = matrix5.adj();

    for (size_t curRow = 0; curRow < matrix5.getRows(); ++curRow) {
        for (size_t curCol = 0; curCol < matrix5.getCols(); ++curCol) {
            EXPECT_EQ(matrix6(curRow, curCol), adjMatrix3(curRow, curCol));
        }
    }
}

TEST(MatrixLib, InvMatrixTest) {
    Matrix<double, 2, 2> matrix1({1, 2,
                                5, 16});

    Matrix<double, 2, 2> matrix2({ 2.66667, -0.333333,
                                   -0.833333, 0.166667}
                                );                                

    Matrix<double> invMatrix(matrix1.getRows(), matrix1.getCols());
    invMatrix = matrix1.inv();

    for (size_t curRow = 0; curRow < matrix1.getRows(); ++curRow) {
        for (size_t curCol = 0; curCol < matrix1.getCols(); ++curCol) {
            EXPECT_TRUE(std::abs(matrix2(curRow, curCol) - invMatrix(curRow, curCol)) < 1e-3);
        }
    }


    Matrix<double, 3, 3> matrix3({1, 2, 3,
                                5, 16, 1,
                                -1, 2, 2});

    Matrix<double, 3, 3> matrix4({0.348837, 0.0232558, -0.534884,
                                -0.127907, 0.0581395, 0.162791,
                                0.302326, -0.0465116, 0.0697674});

    Matrix<double> invMatrix2(matrix3.getRows(), matrix3.getCols());
    invMatrix2 = matrix3.inv();

    for (size_t curRow = 0; curRow < matrix3.getRows(); ++curRow) {
        for (size_t curCol = 0; curCol < matrix3.getCols(); ++curCol) {
            EXPECT_TRUE(std::abs(matrix4(curRow, curCol) - invMatrix2(curRow, curCol)) <= 1e-3);
        }
    }


    Matrix<double, 4, 4> matrix5({1, 2, 3, 5,
                                16, 1, -1, 2,
                                2, 8, 9, 10,
                                1, -1, 6, 2});

    Matrix<double, 4, 4> matrix6({-0.0503338, 0.0631741, 0.0077041, 0.0241397,
                                -0.345146, 0.0046224, 0.195686, -0.120185,
                                -0.206471, -0.0061633, 0.0724191, 0.160246,
                                0.472008, -0.0107858, -0.123267, -0.0529019});

    Matrix<double> invMatrix3(matrix5.getRows(), matrix5.getCols());
    invMatrix3 = matrix5.inv();

    for (size_t curRow = 0; curRow < matrix5.getRows(); ++curRow) {
        for (size_t curCol = 0; curCol < matrix5.getCols(); ++curCol) {
            EXPECT_TRUE(std::abs(matrix6(curRow, curCol) - invMatrix3(curRow, curCol)) <= 1e-3);
        }
    }
}

TEST(MatrixLib, addVectorRowToMatrixTest) {
    Matrix<double, 3, 4> matrix1;
    double initValue = 1;
    for (size_t curRow = 0; curRow < matrix1.getRows(); ++curRow) {
        for (size_t curCol = 0; curCol < matrix1.getCols(); ++curCol) {
            matrix1(curRow, curCol) = initValue;
            ++initValue;
        }
    }

    MatrixRow<double, 4> matrixRow;
    double initValue2 = 3;
    for (size_t index = 0; index < matrixRow.getSize(); ++index) {
        matrixRow[index] = initValue2;
        ++initValue2;
    }

    Matrix<double, 3, 4> resMatrix;
    resMatrix = matrix1 + matrixRow;

    EXPECT_EQ(4, resMatrix(0, 0));
    EXPECT_EQ(6, resMatrix(0, 1));
    EXPECT_EQ(8, resMatrix(0, 2));
    EXPECT_EQ(10, resMatrix(0, 3));

    EXPECT_EQ(8, resMatrix(1, 0));
    EXPECT_EQ(10, resMatrix(1, 1));
    EXPECT_EQ(12, resMatrix(1, 2));
    EXPECT_EQ(14, resMatrix(1, 3));

    EXPECT_EQ(12, resMatrix(2, 0));
    EXPECT_EQ(14, resMatrix(2, 1));
    EXPECT_EQ(16, resMatrix(2, 2));
    EXPECT_EQ(18, resMatrix(2, 3));
}

TEST(MatrixLib, subtractVectorRowToMatrixTest) {
    Matrix<double, 3, 4> matrix1;
    double initValue = 1;
    for (size_t curRow = 0; curRow < matrix1.getRows(); ++curRow) {
        for (size_t curCol = 0; curCol < matrix1.getCols(); ++curCol) {
            matrix1(curRow, curCol) = initValue;
            ++initValue;
        }
    }

    MatrixRow<double, 4> matrixRow;
    double initValue2 = 3;
    for (size_t index = 0; index < matrixRow.getSize(); ++index) {
        matrixRow[index] = initValue2;
        ++initValue2;
    }

    Matrix<double, 3, 4> resMatrix;
    resMatrix = matrix1 - matrixRow;

    EXPECT_EQ(-2, resMatrix(0, 0));
    EXPECT_EQ(-2, resMatrix(0, 1));
    EXPECT_EQ(-2, resMatrix(0, 2));
    EXPECT_EQ(-2, resMatrix(0, 3));

    EXPECT_EQ(2, resMatrix(1, 0));
    EXPECT_EQ(2, resMatrix(1, 1));
    EXPECT_EQ(2, resMatrix(1, 2));
    EXPECT_EQ(2, resMatrix(1, 3));

    EXPECT_EQ(6, resMatrix(2, 0));
    EXPECT_EQ(6, resMatrix(2, 1));
    EXPECT_EQ(6, resMatrix(2, 2));
    EXPECT_EQ(6, resMatrix(2, 3));
}

TEST(MatrixLib, addVectorColToMatrixTest) {
    Matrix<double, 3, 4> matrix1;
    double initValue = 1;
    for (size_t curRow = 0; curRow < matrix1.getRows(); ++curRow) {
        for (size_t curCol = 0; curCol < matrix1.getCols(); ++curCol) {
            matrix1(curRow, curCol) = initValue;
            ++initValue;
        }
    }

    MatrixCol<double, 3> MatrixCol;
    double initValue2 = 3;
    for (size_t index = 0; index < MatrixCol.getSize(); ++index) {
        MatrixCol[index] = initValue2;
        ++initValue2;
    }

    Matrix<double> resMatrix(matrix1.getRows(), matrix1.getCols());
    resMatrix = matrix1 + MatrixCol;

    EXPECT_EQ(4, resMatrix(0, 0));
    EXPECT_EQ(5, resMatrix(0, 1));
    EXPECT_EQ(6, resMatrix(0, 2));
    EXPECT_EQ(7, resMatrix(0, 3));

    EXPECT_EQ(9, resMatrix(1, 0));
    EXPECT_EQ(10, resMatrix(1, 1));
    EXPECT_EQ(11, resMatrix(1, 2));
    EXPECT_EQ(12, resMatrix(1, 3));

    EXPECT_EQ(14, resMatrix(2, 0));
    EXPECT_EQ(15, resMatrix(2, 1));
    EXPECT_EQ(16, resMatrix(2, 2));
    EXPECT_EQ(17, resMatrix(2, 3));
}

TEST(MatrixLib, subtractVectorColToMatrixTest) {
    Matrix<double, 3, 4> matrix1;
    double initValue = 1;
    for (size_t curRow = 0; curRow < matrix1.getRows(); ++curRow) {
        for (size_t curCol = 0; curCol < matrix1.getCols(); ++curCol) {
            matrix1(curRow, curCol) = initValue;
            ++initValue;
        }
    }

    MatrixCol<double, 3> MatrixCol(3, 0);
    double initValue2 = 3;
    for (size_t index = 0; index < MatrixCol.getSize(); ++index) {
        MatrixCol[index] = initValue2;
        ++initValue2;
    }

    Matrix<double> resMatrix(matrix1.getRows(), matrix1.getCols());
    resMatrix = matrix1 - MatrixCol;

    EXPECT_EQ(-2, resMatrix(0, 0));
    EXPECT_EQ(-1, resMatrix(0, 1));
    EXPECT_EQ(0, resMatrix(0, 2));
    EXPECT_EQ(1, resMatrix(0, 3));

    EXPECT_EQ(1, resMatrix(1, 0));
    EXPECT_EQ(2, resMatrix(1, 1));
    EXPECT_EQ(3, resMatrix(1, 2));
    EXPECT_EQ(4, resMatrix(1, 3));

    EXPECT_EQ(4, resMatrix(2, 0));
    EXPECT_EQ(5, resMatrix(2, 1));
    EXPECT_EQ(6, resMatrix(2, 2));
    EXPECT_EQ(7, resMatrix(2, 3));
}

TEST(MatrixRow, ConstructorTest) {
    MatrixRow<double, 3> matrix(3, 4);
    EXPECT_EQ(3, matrix.getSize());
    double expectValue = 4;
    for (size_t index = 0; index < matrix.getSize(); ++index) {
        EXPECT_EQ(expectValue, matrix[index]);
    }

    MatrixRow<double, 12> matrix1({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
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

TEST(MatrixRow, rowAdditionTest) {
    MatrixRow<double, 3> matrix(3, 0);
    MatrixRow<double, 3> matrix2(3, 0);
    EXPECT_EQ(3, matrix.getSize());
    EXPECT_EQ(3, matrix2.getSize());
    double initValue = 1;
    for (size_t index = 0; index < matrix.getSize(); ++index) {
        matrix[index] = initValue;
        matrix2[index] = initValue + 1;
        ++initValue;
    }

    MatrixRow<double, 3> matrixSum(3, 0);
    matrixSum = matrix + matrix2;

    EXPECT_EQ(3, matrixSum[0]);
    EXPECT_EQ(5, matrixSum[1]);
    EXPECT_EQ(7, matrixSum[2]);
}

TEST(MatrixCol, ColAdditionTest) {
    MatrixCol<double, 3> matrix(3, 0);
    MatrixCol<double, 3> matrix2(3, 0);
    EXPECT_EQ(3, matrix.getSize());
    EXPECT_EQ(3, matrix2.getSize());
    double initValue = 1;
    for (size_t index = 0; index < matrix.getSize(); ++index) {
        matrix[index] = initValue;
        matrix2[index] = initValue + 1;
        ++initValue;
    }

    MatrixCol<double, 3> matrixSum(3, 0);
    matrixSum = matrix + matrix2;

    EXPECT_EQ(3, matrixSum[0]);
    EXPECT_EQ(5, matrixSum[1]);
    EXPECT_EQ(7, matrixSum[2]);
}

TEST(MatrixRow, rowSubtractionTest) {
    MatrixRow<double, 3> matrix(3, 0);
    MatrixRow<double, 3> matrix2(3, 0);
    EXPECT_EQ(3, matrix.getSize());
    EXPECT_EQ(3, matrix2.getSize());
    double initValue = 1;
    for (size_t index = 0; index < matrix.getSize(); ++index) {
        matrix[index] = initValue;
        matrix2[index] = initValue + 1;
        ++initValue;
    }

    MatrixRow<double, 3> matrixSubtraction(3, 0);
    matrixSubtraction = matrix - matrix2;

    EXPECT_EQ(-1, matrixSubtraction[0]);
    EXPECT_EQ(-1, matrixSubtraction[1]);
    EXPECT_EQ(-1, matrixSubtraction[2]);
}

TEST(MatrixCol, ColSubtractionTest) {
    MatrixCol<double, 3> matrix(3, 0);
    MatrixCol<double, 3> matrix2(3, 0);
    EXPECT_EQ(3, matrix.getSize());
    EXPECT_EQ(3, matrix2.getSize());
    double initValue = 1;
    for (size_t index = 0; index < matrix.getSize(); ++index) {
        matrix[index] = initValue;
        matrix2[index] = initValue + 1;
        ++initValue;
    }

    MatrixCol<double, 3> matrixSubtraction(3, 0);
    matrixSubtraction = matrix - matrix2;

    EXPECT_EQ(-1, matrixSubtraction[0]);
    EXPECT_EQ(-1, matrixSubtraction[1]);
    EXPECT_EQ(-1, matrixSubtraction[2]);
}

TEST(MatrixRow, rowMultiplicationTest) {
    MatrixRow<double, 3> matrix(3, 0);
    MatrixCol<double, 3> matrix2(3, 0);
    EXPECT_EQ(3, matrix.getSize());
    EXPECT_EQ(3, matrix2.getSize());
    double initValue = 1;
    for (size_t index = 0; index < matrix.getSize(); ++index) {
        matrix[index] = initValue;
        matrix2[index] = initValue + 1;
        ++initValue;
    }

    double resMultiplication;
    resMultiplication = matrix * matrix2;

    EXPECT_EQ(20, resMultiplication);
}

TEST(MatrixCol, colMultiplicationTest) {
    MatrixRow<double, 4> matrix(4, 0);
    MatrixCol<double, 4> matrix2(4, 0);
    EXPECT_EQ(4, matrix.getSize());
    EXPECT_EQ(4, matrix2.getSize());
    double initValue = 1;
    for (size_t index = 0; index < matrix.getSize(); ++index) {
        matrix[index] = initValue;
        matrix2[index] = initValue + 1;
        ++initValue;
    }

    Matrix<double> resMatrix(4, 4);
    resMatrix = matrix2 * matrix;

    EXPECT_EQ(2, resMatrix(0, 0));
    EXPECT_EQ(4, resMatrix(0, 1));
    EXPECT_EQ(6, resMatrix(0, 2));
    EXPECT_EQ(8, resMatrix(0, 3));

    EXPECT_EQ(3, resMatrix(1, 0));
    EXPECT_EQ(6, resMatrix(1, 1));
    EXPECT_EQ(9, resMatrix(1, 2));
    EXPECT_EQ(12, resMatrix(1, 3));
    

    EXPECT_EQ(4, resMatrix(2, 0));
    EXPECT_EQ(8, resMatrix(2, 1));
    EXPECT_EQ(12, resMatrix(2, 2));
    EXPECT_EQ(16, resMatrix(2, 3));

    EXPECT_EQ(5, resMatrix(3, 0));
    EXPECT_EQ(10, resMatrix(3, 1));
    EXPECT_EQ(15, resMatrix(3, 2));
    EXPECT_EQ(20, resMatrix(3, 3));
}

TEST(MatrixRow, rowValueMultiplicationTest) {
    MatrixRow<double, 3> matrix(3, 0);
    double multiplier = 3;
    double initValue = 1;
    for (size_t index = 0; index < matrix.getSize(); ++index) {
        matrix[index] = initValue;
        ++initValue;
    }

    MatrixRow<double, 3> matrixMultiplication(3, 0);
    matrixMultiplication = matrix * multiplier;

    EXPECT_EQ(3, matrixMultiplication[0]);
    EXPECT_EQ(6, matrixMultiplication[1]);
    EXPECT_EQ(9, matrixMultiplication[2]);
}

TEST(MatrixRow, rowValueSumTest) {
    MatrixRow<double, 3> matrix(3, 0);
    double addingValue = 3;
    double initValue = 1;
    for (size_t index = 0; index < matrix.getSize(); ++index) {
        matrix[index] = initValue;
        ++initValue;
    }

    MatrixRow<double, 3> matrixSum(3, 0);
    matrixSum = matrix + addingValue;

    EXPECT_EQ(4, matrixSum[0]);
    EXPECT_EQ(5, matrixSum[1]);
    EXPECT_EQ(6, matrixSum[2]);
}

TEST(MatrixRow, rowValueSubtractionTest) {
    MatrixRow<double, 3> matrix(3, 0);
    double substractionValue = 3;
    double initValue = 1;
    for (size_t index = 0; index < matrix.getSize(); ++index) {
        matrix[index] = initValue;
        ++initValue;
    }

    MatrixRow<double, 3> matrixSubtraction(3, 0);
    matrixSubtraction = matrix - substractionValue;

    EXPECT_EQ(-2, matrixSubtraction[0]);
    EXPECT_EQ(-1, matrixSubtraction[1]);
    EXPECT_EQ(0, matrixSubtraction[2]);
}





TEST(MatrixCol, ColValueMultiplicationTest) {
    MatrixCol<double, 3> matrix(3, 0);
    double multiplier = 3;
    double initValue = 1;
    for (size_t index = 0; index < matrix.getSize(); ++index) {
        matrix[index] = initValue;
        ++initValue;
    }

    MatrixCol<double, 3> matrixMultiplication(3, 0);
    matrixMultiplication = matrix * multiplier;

    EXPECT_EQ(3, matrixMultiplication[0]);
    EXPECT_EQ(6, matrixMultiplication[1]);
    EXPECT_EQ(9, matrixMultiplication[2]);
}

TEST(MatrixCol, ColValueSumTest) {
    MatrixCol<double, 3> matrix(3, 0);
    double addingValue = 3;
    double initValue = 1;
    for (size_t index = 0; index < matrix.getSize(); ++index) {
        matrix[index] = initValue;
        ++initValue;
    }

    MatrixCol<double, 3> matrixSum(3, 0);
    matrixSum = matrix + addingValue;

    EXPECT_EQ(4, matrixSum[0]);
    EXPECT_EQ(5, matrixSum[1]);
    EXPECT_EQ(6, matrixSum[2]);
}

TEST(MatrixCol, ColValueSubtractionTest) {
    MatrixCol<double, 3> matrix(3, 0);
    double substractionValue = 3;
    double initValue = 1;
    for (size_t index = 0; index < matrix.getSize(); ++index) {
        matrix[index] = initValue;
        ++initValue;
    }

    MatrixCol<double, 3> matrixSubtraction(3, 0);
    matrixSubtraction = matrix - substractionValue;

    EXPECT_EQ(-2, matrixSubtraction[0]);
    EXPECT_EQ(-1, matrixSubtraction[1]);
    EXPECT_EQ(0, matrixSubtraction[2]);
}




TEST(MatrixRow, rowOnMatrixMultiplicationTest) {
    Matrix<double> matrix1(4, 4);

    double initValue = 1;
    for (size_t curRow = 0; curRow < matrix1.getRows(); ++curRow) {
        for (size_t curCol = 0; curCol < matrix1.getCols(); ++curCol) {
            matrix1(curRow, curCol) = initValue;
            ++initValue;
        }
    }

    MatrixRow<double, 4> matrixRow1(4, 0);
    double initValue2 = 1;
    for (size_t index = 0; index < matrixRow1.getSize(); ++index) {
        matrixRow1[index] = initValue2;
        ++initValue2;
    }

    MatrixRow<double, 4> matrixRowRes(4, 0);
    matrixRowRes = matrixRow1 * matrix1;

    EXPECT_EQ(90, matrixRowRes[0]);
    EXPECT_EQ(100, matrixRowRes[1]);
    EXPECT_EQ(110, matrixRowRes[2]);
    EXPECT_EQ(120, matrixRowRes[3]);
}

TEST(MatrixCol, ConstructorTest) {
    MatrixCol<double, 3> matrix(3, 4);
    EXPECT_EQ(3, matrix.getSize());
    double expectValue = 4;
    for (size_t index = 0; index < matrix.getSize(); ++index) {
        EXPECT_EQ(expectValue, matrix[index]);
    }

    MatrixCol<double, 12> matrix1({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
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

TEST(MatrixLib, CreateMatrixFromVector) {
    MatrixCol<double, 3> matrixCol1({1, 2, 3});
    MatrixCol<double, 3> matrixCol2({4, 5, 6});
    MatrixCol<double, 3> matrixCol3({7, 8, 9});
    MatrixCol<double, 3> matrixCol4({10, 11, 12});
    
    Matrix<MatrixCol<double, 3>, 2, 2> matrix({  matrixCol1, matrixCol2, matrixCol3, matrixCol4});

    EXPECT_EQ(1, matrix(0, 0)[0]);
    EXPECT_EQ(2, matrix(0, 0)[1]);
    EXPECT_EQ(3, matrix(0, 0)[2]);

    EXPECT_EQ(4, matrix(0, 1)[0]);
    EXPECT_EQ(5, matrix(0, 1)[1]);
    EXPECT_EQ(6, matrix(0, 1)[2]);

    EXPECT_EQ(7, matrix(1, 0)[0]);
    EXPECT_EQ(8, matrix(1, 0)[1]);
    EXPECT_EQ(9, matrix(1, 0)[2]);

    EXPECT_EQ(10, matrix(1, 1)[0]);
    EXPECT_EQ(11, matrix(1, 1)[1]);
    EXPECT_EQ(12, matrix(1, 1)[2]);

    MatrixRow<double, 3> matrixRow1({1, 2, 3});
    MatrixRow<double, 3> matrixRow2({4, 5, 6});
    MatrixRow<double, 3> matrixRow3({7, 8, 9});
    MatrixRow<double, 3> matrixRow4({10, 11, 12});

    Matrix<MatrixRow<double, 3>, 2, 2> matrix2({matrixRow1, matrixRow2, matrixRow3, matrixRow4});

    EXPECT_EQ(1, matrix2(0, 0)[0]);
    EXPECT_EQ(2, matrix2(0, 0)[1]);
    EXPECT_EQ(3, matrix2(0, 0)[2]);

    EXPECT_EQ(4, matrix2(0, 1)[0]);
    EXPECT_EQ(5, matrix2(0, 1)[1]);
    EXPECT_EQ(6, matrix2(0, 1)[2]);

    EXPECT_EQ(7, matrix2(1, 0)[0]);
    EXPECT_EQ(8, matrix2(1, 0)[1]);
    EXPECT_EQ(9, matrix2(1, 0)[2]);

    EXPECT_EQ(10, matrix2(1, 1)[0]);
    EXPECT_EQ(11, matrix2(1, 1)[1]);
    EXPECT_EQ(12, matrix2(1, 1)[2]);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
