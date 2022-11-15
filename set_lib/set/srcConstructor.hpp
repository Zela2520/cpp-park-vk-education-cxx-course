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
Tree<T, IsLess>::Tree(const std::initializer_list<T> &list) : Tree() {
    for (const auto &elem : list) {
        Add(elem);
    }
}

template<typename T, class IsLess>
Tree<T, IsLess>::~Tree() {
    this->postOrderTree(root, [](Node<T>& it) { delete &it; });
}
