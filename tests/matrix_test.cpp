#include "gtest/gtest.h"

extern "C++" {
    #include "../matrix_lib/matrix/matrix.hpp"
}


TEST(MatrixLib, ConstructorTest) {
    Matrix matrix(3, 4);
    EXPECT_EQ(12, matrix.getNumberOfMatrixElements());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

