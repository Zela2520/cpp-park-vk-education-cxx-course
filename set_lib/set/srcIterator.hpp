#pragma once  // pragma once

template<typename T, class IsLess>
typename Tree<T, IsLess>::iterator Tree<T, IsLess>::begin() const {
    if (root->size == 0) {
        return iterator(root, nullptr);
    }
    auto *curNode = this->root;
    while (curNode && curNode->left_child != nullptr) {
        curNode = curNode->left_child;
    }
    return iterator(curNode, nullptr);
}

template<typename T, class IsLess>
typename Tree<T, IsLess>::iterator Tree<T, IsLess>::end() const {
    if (root->size == 0) {
        return iterator(root, nullptr);
    }

    Node<T>* curNode = this->root;
    Node<T>* prevNode = nullptr;

    while (curNode != nullptr) {
        prevNode = curNode;
        curNode = curNode->right_child;
    }

    return iterator(curNode, prevNode);
}

template<typename T, class IsLess>
typename Tree<T, IsLess>::iterator Tree<T, IsLess>::rbegin() const {
   if (root) {
        Node<T>* curNode = root;

        while (curNode->right_child) {
            curNode = curNode->right_child;
        }
        return typename Tree<T, IsLess>::iterator(curNode);
    }
    return typename Tree<T, IsLess>::iterator(nullptr);
}

template<typename T, class IsLess>
typename Tree<T, IsLess>::iterator Tree<T, IsLess>::rend() const {
    return typename Tree<T, IsLess>::iterator(nullptr);
}
