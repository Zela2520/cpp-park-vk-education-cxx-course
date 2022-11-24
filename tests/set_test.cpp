#include "gtest/gtest.h"


#include <iostream>
#include <vector>
#include "set.hpp"


TEST(SetLib, LiveCycleTest) {
    // default constructor
    auto tree = std::make_unique<Tree<int>>();
    EXPECT_FALSE(tree == nullptr);
    // list constructor
    Tree<int>* tree2 = new Tree<int>{6, 3, 8, 9, 5, 4, 1, 7, 2};
    EXPECT_EQ(9, tree2->Size());
    delete tree2;
    tree2 = nullptr;

    // operator =
    Tree<int>* tree3 = new Tree<int>{5, 20, 1, 8, 2, 3, 4, 14, 18, 11, 6, 15, 9, 7, 17, 10, 13, 16, 12, 19};
    Tree<int>* tree4 = new Tree<int>;
    *tree4 = *tree3;
    delete tree3;
    tree3 = nullptr;
    int curElem = 20;
    for (auto it = tree4->rbegin(); it != tree4->rend(); --it) {
        EXPECT_EQ(curElem, it.m_pointer->getValue());
        --curElem;
    }
    delete tree4;
    tree4 = nullptr;

    // copy constructor
    Tree<int>* tree5 = new Tree<int>{5, 20, 1, 8, 2, 3, 4, 14, 18, 11, 6, 15, 9, 7, 17, 10, 13, 16, 12, 19};
    auto tree6 = std::make_unique<Tree<int>>(tree5);
    delete tree5;

    curElem = 1;
    for (auto it = tree6->begin(); it != tree6->end(); ++it) {
        EXPECT_EQ(curElem, it.m_pointer->getValue());
        ++curElem;
    }
}

TEST(SetLib, IteratorTest) {
    Tree<int>* tree = new Tree<int>{6, 3, 8, 9, 5, 4, 1, 7, 2};

    int curElem = 1;
    for (auto it = tree->begin(); it != tree->end(); ++it) {
        EXPECT_EQ(curElem, it.m_pointer->getValue());
        ++curElem;
    }

    curElem = 9;
    for (auto it = tree->rbegin(); it != tree->rend(); --it) {
        EXPECT_EQ(curElem, it.m_pointer->getValue());
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
        EXPECT_EQ(curElem, it.m_pointer->getValue());
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
        EXPECT_EQ(curElem, it.m_pointer->getValue());
        ++curElem;
    }
    EXPECT_EQ(tree->Size(), 2);


    Tree<int>* tree2 = new Tree<int>{9, 2, 3, 7, 1, 8, 5, 4, 6};
    curElem = 1;
    for (auto it = tree2->begin(); it != tree2->end(); ++it) {
        EXPECT_EQ(curElem, it.m_pointer->getValue());
        ++curElem;
    }

    EXPECT_TRUE(tree2->Has(7) == true);
    EXPECT_TRUE(tree2->Has(10) == false);

    delete tree2;
    tree2 = nullptr;

    auto tree3 = std::make_unique<Tree<int>>();

    tree3->Add(5);
    tree3->Add(1);
    tree3->Add(9);
    tree3->Add(6);
    tree3->Add(7);
    tree3->Add(2);
    tree3->Add(3);
    tree3->Add(8);
    tree3->Add(4);


    tree3->Erase(5);
    tree3->Erase(4);
    tree3->Erase(1);
    tree3->Erase(2);

    curElem = 9;
    for (auto it = tree3->rbegin(); it != tree3->rend(); ++it) {
        if (curElem == 4) {
            --curElem;
        }
        if (curElem == 5) {
            --curElem;
        }
        EXPECT_EQ(curElem, it.m_pointer->getValue());
        --curElem;
    }

    std::vector<int> vec;

    for (auto it = tree3->begin(); it != tree3->end(); ++it) {
        vec.push_back(it.m_pointer->getValue());
    }

    EXPECT_EQ(vec.size(), 5);

    EXPECT_EQ(vec[0], 3);
    EXPECT_EQ(vec[1], 6);
    EXPECT_EQ(vec[2], 7);
    EXPECT_EQ(vec[3], 8);
    EXPECT_EQ(vec[4], 9);
}

TEST(SetLib, GetDataTest) {
    Tree<int>* tree = new Tree<int>{6, 3, 8, 9, 5, 4, 1, 7, 2, 91, 21, 32, 12, 77, 44, 10, 21, 12, 55, 95, 11};
    EXPECT_EQ(19, tree->Size());
    EXPECT_EQ(tree->Find(91)->getValue(), 91);
    EXPECT_EQ(tree->findLowerBound(91)->getValue(), 95);
    
    EXPECT_TRUE(tree->Find(69) == nullptr);
    EXPECT_TRUE(tree->findLowerBound(95) == nullptr);
    delete tree;
    tree = nullptr;
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
