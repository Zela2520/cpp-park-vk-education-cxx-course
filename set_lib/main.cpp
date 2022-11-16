#include <iostream>

#include "set.hpp"


int main() {
//    auto tree = std::make_unique<Tree<int>>();
//    Tree<int>* tree = new Tree<int>{9, 2, 3, 7, 1, 8, 5, 4, 6};
    Tree<int>* tree = new Tree<int>{6, 3, 8, 9, 5, 4, 1, 7, 2};
//    for (int i = 9; i > 0; --i) {
//        tree->Erase(i);
//    }
//        tree->Erase(8);
//    for (int i = 5; i < 10; ++i) {
//        tree->Erase(i);
//    }
//    tree->Erase(5);
//    tree->Erase(1);
//    tree->Erase(9);
//    tree->Erase(6);
//    tree->Erase(7);


//    Tree<int>* tree = new Tree<int>{6, 3, 8, 9, 5, 4, 1, 7, 2, 91, 21, 32, 12, 77, 44, 10, 21, 12, 55, 95, 11};

//    for (int i = 1; i < 10; ++i) {
//        tree->Add(i);
//    }

//    tree->bfs();
//
//    for (int i = 110; i > 1; --i) {
//        tree->Erase(i);
//    }

    for (auto it = tree->rbegin(); it != tree->rend(); --it) {
        std::cout << "current element value: " <<  it.m_pointer->value << std::endl;
//        if (it.m_pointer->next) {
//            std::cout << "next element value: " << it.m_pointer->next->value << std::endl;
//        }
//        if (it.m_pointer->prev) {
//            std::cout << "prev element value: " << it.m_pointer->prev->value << std::endl;
//        }
    }
//    for (int i = 1; i < 101; ++i) {
//        myTree->Add(i);
//    }

//    for (int i = 110; i > 1; --i) {
//        myTree->Erase(i);
//    }

//    myTree->Add(2);
//    myTree->Add(1);
//    myTree->Add(8);
//    myTree->Add(4);
//    myTree->Add(3);
//    myTree->Add(6);
//    myTree->Add(6);
//    if (myTree->Has(1)) {
//        std::cout << "I' m grut" << std::endl;
//    }

//    if (myTree->isEmpty()) {
//        std::cout << "set size: " << myTree->Size() << std::endl;
//    }
//
//    std::cout << "set size: " << myTree->Size() << std::endl;
//    myTree->bfs();



//    std::cout << "lowerBound test passed: " << tree->findLowerBound(91)->value << std::endl;
//    assert(tree->findLowerBound(95) == nullptr);

    return 0;
}

