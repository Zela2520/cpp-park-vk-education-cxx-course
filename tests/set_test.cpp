#include "gtest/gtest.h"


#include <iostream>
#include "set.hpp"


TEST(SetLib, LiveCycleTest) {
    auto tree = std::make_unique<Tree<int>>();
    EXPECT_FALSE(tree == nullptr);
    Tree<int>* tree2 = new Tree<int>{6, 3, 8, 9, 5, 4, 1, 7, 2};
    EXPECT_EQ(9, tree2->Size());
    delete tree2;
    tree2 = nullptr;
}

TEST(SetLib, IteratorTest) {
    Tree<int>* tree = new Tree<int>{6, 3, 8, 9, 5, 4, 1, 7, 2};

    int curElem = 1;
    for (auto it = tree->begin(); it != tree->end(); ++it) {
        EXPECT_EQ(curElem, it.m_pointer->value);
        ++curElem;
    }

    curElem = 9;
    for (auto it = tree->rbegin(); it != tree->rend(); --it) {
        EXPECT_EQ(curElem, it.m_pointer->value);
        --curElem;
    }

    delete tree;
    tree = nullptr;

    auto tree2 = std::make_unique<Tree<int>>();

    tree2->Add(5);
    tree2->Add(1);
    tree2->Add(9);
    tree2->Add(6);
    tree2->Add(7);
    tree2->Add(2);
    tree2->Add(3);
    tree2->Add(8);
    tree2->Add(4);


    tree2->Erase(7);
    tree2->Erase(4);
    tree2->Erase(1);
    tree2->Erase(9);

    curElem = 2;
    for (auto it = tree2->begin(); it != tree2->end(); ++it) {
        if (curElem == 4 || curElem == 7) {
            ++curElem;
        }
        EXPECT_EQ(curElem, it.m_pointer->value);
        ++curElem;
    }
}

TEST(SetLib, ModifyTest) {
    auto tree = std::make_unique<Tree<int>>();
    for(int i = 1; i < 10; ++i) {
        tree->Add(i);
    }
    for (int i = 1; i < 8; ++i) {
        tree->Erase(i);
    }

    int curElem = 8;
    for (auto it = tree->begin(); it != tree->end(); ++it) {
        EXPECT_EQ(curElem, it.m_pointer->value);
        ++curElem;
    }
    EXPECT_EQ(tree->Size(), 2);


    Tree<int>* tree2 = new Tree<int>{9, 2, 3, 7, 1, 8, 5, 4, 6};
    curElem = 1;
    for (auto it = tree2->begin(); it != tree2->end(); ++it) {
        EXPECT_EQ(curElem, it.m_pointer->value);
        ++curElem;
    }
    delete tree2;
    tree2 = nullptr;
}

TEST(SetLib, GetDataTest) {
    Tree<int>* tree = new Tree<int>{6, 3, 8, 9, 5, 4, 1, 7, 2, 91, 21, 32, 12, 77, 44, 10, 21, 12, 55, 95, 11};
    EXPECT_EQ(tree->Find(91)->value, 91);
    EXPECT_EQ(tree->findLowerBound(91)->value, 95);
    
    EXPECT_TRUE(tree->Find(69) == nullptr);
    EXPECT_TRUE(tree->findLowerBound(95) == nullptr);
    delete tree;
    tree = nullptr;
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
