#include "gtest/gtest.h"

#include "exception.hpp"
#include "utils.hpp"
#include <vector>

TEST(ReadFileTest, DISABLED_read_file) {
    FileOpen file("./test_files/creation_case2.txt");
}

TEST(MatrixLib, ConstructorTest) {
    Matrix<double> matrix(3, 4);
    EXPECT_EQ(12, matrix.getNumberOfMatrixElements());

    Matrix<double, 3, 4> matrix1;
    EXPECT_EQ(12, matrix1.getNumberOfMatrixElements());
}

TEST(MatrixLib, DISABLED_CreateMatrixFromFile) {
    FileOpen file("./test_files/creation_case2.txt");
    Matrix<double> matrix(file.fs);
    EXPECT_EQ(80, matrix.getCols() * matrix.getRows());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
