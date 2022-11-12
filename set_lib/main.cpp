#include <iostream>
#include <cassert>
#include <queue>
#include "set.hpp"


int main() {

    AvlTree<int> tree;

    for(int i = 1; i < 10; ++i) {
        tree.Add(i);
    }

    tree.BFS();
    tree.dfsInOrder(tree.getRoot());

    std::cout << "\n";

    std::cout << "set size: " << tree.Size() << "\n";



    return 0;
}
