#include "gtest/gtest.h"


#include <iostream>
#include "set.hpp"


TEST(SetLib, ConstructorTest) {
    AvlTree<int> tree;

    for(int i = 1; i < 10; ++i) {
        tree.Add(i);
    }
    for (int i = 1; i < 8; ++i) {
        tree.Delete(i);
    }
    EXPECT_EQ(tree.Size(), 2);

    AvlTree<int> tree2{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 9; i > 0; --i) {
        tree2.Delete(i);
    }
    EXPECT_EQ(tree2.Size(), 0);

    AvlTree<int> tree3;
    for(int i = 9; i > 0; --i) {
        tree3.Add(i);
    }
    for (int i = 1; i < 10; ++i) {
        tree3.Delete(i);
    }
    EXPECT_EQ(tree3.Size(), 0);
}

TEST(SetLib, DeleteRootTest) {
    AvlTree<int> tree;
    for(int i = 1; i < 10; ++i) {
        tree.Add(i);
    }

    tree.Delete(4);

    EXPECT_EQ(tree.Size(), 8);
    EXPECT_EQ(tree.getRootData(), 5);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}