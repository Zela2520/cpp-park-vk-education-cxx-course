#pragma once // pragma once

template<typename T>
class IsLessDefault {
public:
    bool operator() (const Node<T>& l, const Node<T>& r) const {return l.value < r.value;}
};

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
        Add(*randIterator++);
    }
}

template<typename T, class IsLess>
Tree<T, IsLess>::Tree(const std::initializer_list<T> &list) : Tree() {
    for (const auto &elem : list) {
        Add(elem);
    }
}

template<typename T, class IsLess>
void Tree<T, IsLess>::copyTree(Node<T> *copyObj, Node<T> *target) {
    if (copyObj && target) {
        target->value = copyObj->value;
        addLinks(target);
        if (copyObj->left_child) {
            target->left_child = new Node<T>();
            target->left_child->parent = target;
            copyTree(copyObj->left_child, target->left_child);
        }
        if (copyObj->right_child) {
            target->right_child = new Node<T>();
            target->right_child->parent = target;
            copyTree(copyObj->right_child, target->right_child);
        }
    }
}

template<typename T, class IsLess>
Tree<T, IsLess>::Tree(const Tree* other) : Tree() {
    if (other->root) {
        copyTree(other->root, this->root);
    }
}

template<typename T, class IsLess>
Tree<T, IsLess>& Tree<T, IsLess>::operator=(const Tree &other) {
    if (other.root) {
        copyTree(other.root, this->root);
    }
    return *this;
}

template<typename T, class IsLess>
Tree<T, IsLess>::~Tree() {
    this->postOrderTree(root, [](Node<T>& it) { delete &it; });
}
