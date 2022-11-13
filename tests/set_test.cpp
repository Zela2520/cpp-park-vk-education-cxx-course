#include "gtest/gtest.h"


#include <iostream>
#include "set.hpp"


TEST(MatrixLib, ConstructorTest) {
    AvlTree<int> tree;

    for(int i = 1; i < 10; ++i) {
        tree.Add(i);
    }

    for (int i = 1; i < 8; ++i) {
        tree.Delete(i);
    }

    EXPECT_EQ(tree.Size(), 2);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}