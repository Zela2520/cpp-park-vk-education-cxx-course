#pragma once // pragma once

template<typename T, class IsLess>
Tree<T, IsLess>::Tree(const IsLess& is_less) : isLess(is_less) {
    root = new Node<T>;
    root->size = 0;
}

template<typename T, class IsLess>
template<std::random_access_iterator Iterator>
Tree<T, IsLess>::Tree(Iterator begin, Iterator end) : Tree() {
   std::random_access_iterator auto randIterator = begin;
   while (randIterator != end) {
       insert(*randIterator++);
   }
}

template<typename T, class IsLess>
Tree<T, IsLess>::Tree(const std::initializer_list<T> &list) : Tree() {
    for (const auto &elem : list) {
        insert(elem);
    }
}

template<typename T, class IsLess>
void Tree<T, IsLess>::copyTree(Node<T> *copyObj, Node<T> *target) {
    if (copyObj) {
        target->height = copyObj->height; 
        target->size = copyObj->size;
        insertLinks(target);
        if (copyObj->left_child) {
            target->left_child = new Node<T>(copyObj->left_child->value);
            target->left_child->parent = target;
            copyTree(copyObj->left_child, target->left_child);
        }
        if (copyObj->right_child) {
            target->right_child = new Node<T>(copyObj->right_child->value);
            target->right_child->parent = target;
            copyTree(copyObj->right_child, target->right_child);
        }
    }
}

template<typename T, class IsLess>
Tree<T, IsLess>::Tree(const Tree* other) {
    if (other->root) {
        this->root = new Node<T>(other->root->value);
        copyTree(other->root, this->root);
    }
}

template<typename T, class IsLess>
Tree<T, IsLess>& Tree<T, IsLess>::operator=(const Tree &other) {
    if (other.root && other.root != this->root) {
        Node<T>* deleteRoot = this->root;
        Node<T>* newRoot = new Node<T>(other.root->value);
        copyTree(other.root, newRoot);
        this->root = newRoot;
        this->root->size = other.root->size;
        this->postOrderTree(deleteRoot, [](Node<T>& it) { delete &it; });
    }
    return *this;
}

template<typename T, class IsLess>
void Tree<T, IsLess>::destroyTree(Node<T>* curNode) {
    if (curNode) {
        destroyTree(curNode->left_child);
        destroyTree(curNode->right_child);
        delete curNode;
    }
}

template<typename T, class IsLess>
Tree<T, IsLess>::~Tree() {
    this->postOrderTree(root, [](Node<T>& it) { delete &it; });
}
