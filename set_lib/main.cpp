#include <iostream>
#include "set.hpp"



int main() {
    // operator =
    Tree<int>* tree = new Tree<int>{6, 3, 8, 9, 5, 4, 1, 7, 2};
    Tree<int>* tree2 = new Tree<int>{1, 2};
    *tree2 = *tree;
    delete tree;

    for (auto it = tree2->rbegin(); it != tree2->rend(); --it) {
        std::cout << "current element value: " << it.m_pointer->getValue() << std::endl;
    }
    std::cout << std::endl;
    // copy constructor
    Tree<int>* tree3 = new Tree<int>{9, 2, 3, 7, 1, 8, 5, 4, 6};
    auto tree4 = std::make_unique<Tree<int>>(tree3);

    delete tree3;

    for (auto it = tree4->begin(); it != tree4->end(); ++it) {
        std::cout << "current element value: " << it.m_pointer->getValue() << std::endl;
    }
}