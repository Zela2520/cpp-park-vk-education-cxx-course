#include "gtest/gtest.h"


#include <iostream>
#include "set.hpp"


TEST(SetLib, LiveCycleTest) {
    AvlTree<int> tree;
    AvlTree<int> tree2{1, 2, 3, 4, 5, 6, 7, 8, 9};
}

TEST(SetLib, IteratorTest) {

}

TEST(SetLib, ModifyTest) {
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

    AvlTree<int> tree4;
    for(int i = 100; i > 0; --i) {
        tree4.Add(i);
    }
    for (int i = 1; i < 101; ++i) {
        tree4.Delete(i);
    }
    EXPECT_EQ(tree4.Size(), 0);

    AvlTree<int> tree5;
    for(int i = 1; i < 101; ++i) {
        tree5.Add(i);
    }
    for (int i = 100; i > 0; --i) {
        tree5.Delete(i);
    }
    EXPECT_EQ(tree5.Size(), 0);
}

TEST(SetLib, DeleteRootTest) {
    AvlTree<int> tree{1, 2, 3, 4, 5, 6, 7, 8, 9};

    tree.Delete(4);

    EXPECT_EQ(tree.Size(), 8);
    EXPECT_EQ(tree.getRootData(), 5);
}

TEST(SetLib, GetDataTest) {
    AvlTree<int> tree{1, 2, 3, 4, 5, 6, 7, 8, 9};
    EXPECT_EQ(tree.find(3)->getData(), 3);
    // EXPECT_EQ(tree.findLowerBound(4)->getData(), 5);
    
    EXPECT_TRUE(tree.find(10) == nullptr);
    // EXPECT_EQ(tree.findLowerBound(9)->getData() == nullptr);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}