#include "gtest/gtest.h"


#include <iostream>
#include <vector>
#include <set>
#include "set.hpp"

TEST(LiveCycle, DefaultConstructorTest) {
    auto tree = std::make_unique<Tree<int>>();
    EXPECT_FALSE(tree == nullptr);
}

TEST(LiveCycle, IteratorConstructorTest) {
    std::vector<int> list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 17, 14, 13, 16, 20, 19, 18};
    auto tree = std::make_unique<Tree<int>>(list.begin(), list.end());

    int curElem = 1;
    for (auto it = tree->begin(); it != tree->end(); ++it) {
        EXPECT_EQ(curElem, *it);
        ++curElem;
    }
}

TEST(LiveCycle, ListConstructorTest) {
    Tree<int>* tree2 = new Tree<int>{6, 3, 8, 9, 5, 4, 1, 7, 2};
    EXPECT_EQ(9, tree2->size());

    delete tree2;
    tree2 = nullptr;
}

TEST(LiveCycle, CopyConstructorTest) {
    Tree<int>* tree5 = new Tree<int>{5, 20, 1, 8, 2, 3, 4, 14, 18, 11, 6, 15, 9, 7, 17, 10, 13, 16, 12, 19};
    auto tree6 = std::make_unique<Tree<int>>(tree5); // copy constructor calling

    delete tree5;
    tree5 = nullptr;

    int curElem = 1;
    for (auto it = tree6->begin(); it != tree6->end(); ++it) {
        EXPECT_EQ(curElem, *it);
        ++curElem;
    }
}

TEST(LiveCycle, EqualOperatorTest) {
    Tree<int>* tree3 = new Tree<int>{5, 20, 1, 8, 2, 3, 4, 14, 18, 11, 6, 15, 9, 7, 17, 10, 13, 16, 12, 19};
    Tree<int>* tree4 = new Tree<int>;
    *tree4 = *tree3; // equal operator calling

    delete tree3;
    tree3 = nullptr;

    int curElem = 20;
    for (auto it = tree4->rbegin(); it != tree4->rend(); --it) {
        EXPECT_EQ(curElem, *it);
        --curElem;
    }

    delete tree4;
    tree4 = nullptr;
}

TEST(Iterator, StraightStrokeTest) {
    Tree<int>* tree = new Tree<int>{6, 3, 8, 9, 5, 4, 1, 7, 2, 7, 3};

    int curElem = 1;
    for (auto it = tree->begin(); it != tree->end(); ++it) {
        EXPECT_EQ(curElem, *it);
        ++curElem;
    }

    delete tree;
    tree = nullptr;
}

TEST(Iterator, ReverseStrokeTest) {
    Tree<int>* tree = new Tree<int>{9, 2, 3, 7, 1, 8, 5, 4, 6, 1, 9};

    int curElem = 9;
    for (auto it = tree->rbegin(); it != tree->rend(); --it) {
        EXPECT_EQ(curElem, *it);
        --curElem;
    }

    delete tree;
    tree = nullptr;
}

TEST(Iterator, ModifySetTest) {
    auto tree2 = std::make_unique<Tree<int>>();

    tree2->insert(5);
    tree2->insert(1);
    tree2->insert(9);
    tree2->insert(6);
    tree2->insert(7);
    tree2->insert(2);
    tree2->insert(3);
    tree2->insert(8);
    tree2->insert(4);

    tree2->erase(7);
    tree2->erase(4);
    tree2->erase(1);
    tree2->erase(9);

    int curElem = 2;
    for (auto it = tree2->begin(); it != tree2->end(); ++it) {
        if (curElem == 4 || curElem == 7) {
            ++curElem;
        }
        EXPECT_EQ(curElem, *it);
        ++curElem;
    }
}

TEST(MainOperation, AddTest) {
    auto tree = std::make_unique<Tree<int>>();

    for(int i = 1; i < 10; ++i) {
        tree->insert(i);
    }

    for (int i = 1; i < 8; ++i) {
        tree->erase(i);
    }

    int curElem = 8;
    for (auto it = tree->begin(); it != tree->end(); ++it) {
        EXPECT_EQ(curElem, *it);
        ++curElem;
    }

    EXPECT_EQ(tree->size(), 2);
}

TEST(MainOperation, EraseTest) {
    auto tree3 = std::make_unique<Tree<int>>();

    tree3->insert(5);
    tree3->insert(1);
    tree3->insert(9);
    tree3->insert(6);
    tree3->insert(7);
    tree3->insert(2);
    tree3->insert(3);
    tree3->insert(8);
    tree3->insert(4);


    tree3->erase(5);
    tree3->erase(4);
    tree3->erase(1);
    tree3->erase(2);

    int curElem = 9;
    for (auto it = tree3->rbegin(); it != tree3->rend(); ++it) {
        if (curElem == 4) {
            --curElem;
        }
        if (curElem == 5) {
            --curElem;
        }
        EXPECT_EQ(curElem, *it);
        --curElem;
    }

    std::vector<int> vec;

    for (auto it = tree3->begin(); it != tree3->end(); ++it) {
        vec.push_back(*it);
    }

    EXPECT_EQ(vec.size(), 5);

    EXPECT_EQ(vec[0], 3);
    EXPECT_EQ(vec[1], 6);
    EXPECT_EQ(vec[2], 7);
    EXPECT_EQ(vec[3], 8);
    EXPECT_EQ(vec[4], 9);

    tree3->erase(3);
    tree3->erase(6);
    tree3->erase(7);
    tree3->erase(8);
    tree3->erase(9);
    
    EXPECT_EQ(tree3->size(), 0);
}

TEST(MainOperation, HasTest) {
    Tree<int>* tree2 = new Tree<int>{9, 2, 3, 7, 1, 8, 5, 4, 6};
    int curElem = 1;
    for (auto it = tree2->begin(); it != tree2->end(); ++it) {
        EXPECT_EQ(curElem, *it);
        ++curElem;
    }

    EXPECT_TRUE(tree2->Has(7) == true);
    EXPECT_TRUE(tree2->Has(10) == false);

    delete tree2;
    tree2 = nullptr;
}

TEST(GetData, FindTest) {
    Tree<int>* tree = new Tree<int>{6, 3, 8, 9, 5, 4, 1, 7, 2, 91, 21, 32, 12, 77, 44, 10, 21, 12, 55, 95, 11};
    EXPECT_EQ(19, tree->size());
    EXPECT_EQ(tree->FindNode(77)->getValue(), 77);
    EXPECT_EQ(tree->FindNode(21)->getValue(), 21);
    EXPECT_EQ(tree->FindNode(91)->getValue(), 91);
    EXPECT_TRUE(tree->FindNode(69) == nullptr);
    delete tree;
    tree = nullptr;
}

TEST(GetData, FindLowerBoundTest) {
    Tree<int>* tree = new Tree<int>{6, 3, 8, 9, 5, 4, 1, 7, 2, 91, 21, 32, 12, 77, 44, 10, 21, 12, 55, 95, 11};
    EXPECT_EQ(tree->findLowerBound(1)->getValue(), 2);
    EXPECT_EQ(tree->findLowerBound(8)->getValue(), 9);
    EXPECT_EQ(tree->findLowerBound(91)->getValue(), 95);
    EXPECT_TRUE(tree->findLowerBound(95) == nullptr);
    delete tree;
    tree = nullptr;
}

TEST(AlexeiTest, CheckConstnessTest) {
    Tree<int>* tree = new Tree<int>{-4, 5, 3, 0, 7};
    EXPECT_TRUE(tree->find(3) != tree->end());

    EXPECT_TRUE(*tree->lower_bound(2) == 3);
    EXPECT_TRUE(tree->lower_bound(8) == tree->end());
    EXPECT_TRUE(*tree->lower_bound(-2) == 0);
    
    EXPECT_TRUE(tree->empty() != true);
    EXPECT_TRUE(tree->size() == 5);

    auto first = tree->begin();
    Tree<int>::iterator last = tree->end();

    EXPECT_TRUE(*first == -4);
    EXPECT_TRUE(*(--last) == 7);

    delete tree;
    tree = nullptr;
}

TEST(AlexeiTest, CheckCopyCorrectness) {
    std::vector<int> elems = {3, 3, -1, 6, 0, 0, 17, -5, 4, 2};
    Tree<int>s1(elems.begin(), elems.end());
    Tree<int> s2;
    std::set<int> set_elems(elems.begin(), elems.end());
    s2 = s1;

    s2.insert(5);
    s2.insert(18);
    s2.insert(-2);

    auto s1_it = s1.begin(), s2_it = s2.begin();
    auto s_it = set_elems.begin();

    while (s1_it != s1.end() || s2_it != s2.end() || s_it != set_elems.end()) {
        if (*s2_it == 5 || *s2_it == 18 || *s2_it == -2) {
            ++s2_it;
            continue;
        }
        EXPECT_EQ(*s1_it, *s2_it);
        EXPECT_EQ(*s1_it, *s_it);
        EXPECT_EQ(*s2_it, *s_it);
            
        ++s1_it, ++s2_it, ++s_it;
    }

    s1 = s2; // Тута
    s2.insert(19);
    auto cur_end = s2.end();
    --cur_end;
    s1_it = s1.begin(), s2_it = s2.begin();

    while (s1_it != s1.end() || s2_it != cur_end) {
        EXPECT_EQ(*s1_it, *s2_it);
        ++s1_it, ++s2_it;
    }

    s1 = s1 = s2;
    s1_it = s1.begin(), s2_it = s2.begin();

    while (s1_it != s1.end() || s2_it != s2.end()) {
        EXPECT_EQ(*s1_it, *s2_it);
        ++s1_it, ++s2_it;
    }
}

TEST(AlexeiTest, CheckEmpty) {
    Tree<std::string> s;
    EXPECT_TRUE(s.empty() == true);

    auto begin = s.begin(), end = s.end();
    EXPECT_TRUE(begin == end);

    std::string elem("abacaba");
    s.insert(elem);
    EXPECT_EQ(*s.lower_bound("aac"), elem);

    Tree<std::string> empty;
    Tree<std::string> s2{"opa"};
    s2 = empty;
    EXPECT_TRUE(s2.size() == 0);

    Tree<std::string> s3(&s2);
    EXPECT_TRUE(s3.empty() == true);
}

TEST(AlexeiTest, CheckIterators) {
    Tree<std::pair<int, int>> s{{-3, 5}, {5, 5}, {-4, 1}, {-4, 4}, {0, 1}, {3, 0}};
    EXPECT_EQ(s.begin()->second, 1);
    EXPECT_EQ((++s.begin())->first, -4);
    
    Tree<std::pair<int, int> >::iterator cur = s.end();
    Tree<int> small{1};
    Tree<int>::iterator it;
    it = small.begin();
    EXPECT_EQ(*it, 1);
    
    auto begin = s.begin();
    begin++;
    cur--;
    EXPECT_TRUE(begin != cur);

    while (begin != cur) {
        ++begin;
        --cur;
    }
    EXPECT_TRUE(begin == cur);
}

TEST(AlexeiTest, CheckErase) {
    Tree<std::string> s{"abacaba", "hello", "p"};
    s.erase("miss");
    s.erase("hello");
    EXPECT_EQ(s.size(), 2);

    s.erase("p");
    EXPECT_EQ(*s.begin(), "abacaba");

    s.erase("1");
    s.erase("abacaba");
    s.erase("012");
    EXPECT_TRUE(s.empty() == true);
}

struct StrangeInt {
    int x;
    static int counter;
    StrangeInt() {
        ++counter;
    }
    StrangeInt(int x): x(x) {
        ++counter;
    }
    StrangeInt(const StrangeInt& rs): x(rs.x) {
        ++counter;
    }
    bool operator <(const StrangeInt& rs) const {
        return x < rs.x;
    }

    static void init() {
        counter = 0;
    }

    ~StrangeInt() {
        --counter;
    }

    friend std::ostream& operator <<(std::ostream& out, const StrangeInt& x) {
        out << x.x;
        return out;
    }
};
int StrangeInt::counter;

TEST(AlexeiTest, CheckOperatorLess) {
    Tree<StrangeInt> s{-5, -3, -6, 13, 7, 1000, 963};
    auto it = s.lower_bound(999);
    ++it;
    EXPECT_TRUE(it == s.end());
}

TEST(AlexeiTest, CheckDestructor) {
    StrangeInt::init();
    {
        Tree<StrangeInt> s{5, 4, 3, 2, 1, 0};
        EXPECT_EQ(s.size(), 6);
    }
    EXPECT_EQ(StrangeInt::counter, 0);
    {
        Tree<StrangeInt> s{-3, 3, -2, 2, -1, 1};
        Tree<StrangeInt> s1(&s);
        s1.insert(0);
        Tree<StrangeInt> s2(&s1);
        EXPECT_TRUE(s1.find(0) != s1.end());

        s1 = s;
        EXPECT_TRUE(s1.find(0) == s1.end());
    }
    EXPECT_EQ(StrangeInt::counter, 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
