#include <iostream>
#include <cassert>
#include <queue>
#include "set.hpp"


int main() {

    AvlTree<int> tree;

    for(int i = 1; i < 10; ++i) {
        tree.Add(i);
    }

    for (int i = 3; i < 8; ++i) {
        tree.Delete(i);
    }

    tree.BFS();
    tree.dfsInOrder(tree.getRoot());

    std::cout << "\n";

    std::cout << "set size: " << tree.Size() << std::endl << std::endl;

    // Node<int>* searchElem = tree.find(8);
    // std::cout << "search elem value is: " << *searchElem << std::endl;
    Node<int>* searchElem2 = tree.find(10);
    assert(searchElem2 == nullptr);



    return 0;
}
