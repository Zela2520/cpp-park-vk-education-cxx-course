#pragma once // pragma once

template<typename T>
AvlTree<T>::AvlTree(const std::initializer_list<T> &list) : AvlTree() {
    for (const auto &elem : list) {
        Add(elem);
    }
}
