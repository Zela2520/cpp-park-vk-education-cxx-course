#pragma once  // pragma once

template<typename T, class IsLess>
Node<T>* Tree<T, IsLess>::Find(const T& elem) const {
    Node<T>* it = root;
    auto finded_node = std::make_unique<Node<T>>();
    finded_node->value = elem;

    while (it) {
        if (it->value == elem) {
            return it;
        }

        if (isLess(*finded_node, *it)) {
            it = it->left_child;
        } else {
            it = it->right_child;
        }
    }
    return nullptr;
}

template<typename T, class IsLess>
Node<T>* Tree<T, IsLess>::findLowerBound(const T& data) const {
    return find(data)->next;
}

template<typename T, class IsLess>
Node<T>* Tree<T, IsLess>::popMin(Node<T>* begin) {
    Node<T>* it = begin;
    while (it->left_child) {
        it = it->left_child;
    }

    if (it->right_child) {
        std::swap(it->value, it->right_child->value);
        Node<T>* saved_min = it->right_child;
        it->right_child->parent = nullptr;
        it->right_child = nullptr;
        Balance(it);
        return saved_min;
    } else {
        Node<T>* saved_parent = it->parent;
        if (it == begin) {
            it->parent->right_child = nullptr;
        } else {
            it->parent->left_child = nullptr;
        }

        it->parent = nullptr;
        Balance(saved_parent);
        return it;
    }
    return it;
}

template<typename T, class IsLess>
bool Tree<T, IsLess>::Has(const T &data) const{
    Node<T>* curNode = root;
    while(curNode) {
        if (curNode->value == data) {
            return true;
        }
        else if (curNode->value < data) {
            curNode = curNode->right_child;
        }
        else {
            curNode = curNode->left_child;
        }
    }
    return false;
}

template<typename T, class IsLess>
typename Tree<T, IsLess>::iterator Tree<T, IsLess>::begin() {
    if (root) {
        Node<T>* curNode = root;

        while (curNode->left_child) {
            curNode = curNode->left_child;
        }
        return typename Tree<T, IsLess>::iterator(curNode);
    }

    return nullptr;
}

template<typename T, class IsLess>
typename Tree<T, IsLess>::iterator Tree<T, IsLess>::end() {
    return nullptr;
}

template<typename T, class IsLess>
typename Tree<T, IsLess>::iterator Tree<T, IsLess>::rbegin() {
    if (root) {
        Node<T>* curNode = root;

        while (curNode->right_child) {
            curNode = curNode->right_child;
        }
        return typename Tree<T, IsLess>::iterator(curNode);
    }

    return nullptr;
}

template<typename T, class IsLess>
typename Tree<T, IsLess>::iterator Tree<T, IsLess>::rend() {
    return nullptr;
}

template<typename T, class IsLess>
typename Tree<T, IsLess>::const_iterator Tree<T, IsLess>::begin() const {
    if (root) {
        Node<T> *curNode = root;
        while (curNode->left_child) {
            curNode = curNode->left_child;
        }
        return typename Tree<T, IsLess>::const_iterator(curNode);
    }

    return nullptr;
}

template<typename T, class IsLess>
typename Tree<T, IsLess>::const_iterator Tree<T, IsLess>::end() const {
    return nullptr;
}

template<typename T, class IsLess>
typename Tree<T, IsLess>::const_iterator Tree<T, IsLess>::rbegin() const {
    if (root) {
        Node<T>* curNode = root;

        while (curNode->right_child) {
            curNode = curNode->right_child;
        }
        return typename Tree<T, IsLess>::const_iterator(curNode);
    }

    return nullptr;
}

template<typename T, class IsLess>
typename Tree<T, IsLess>::const_iterator Tree<T, IsLess>::rend() const {
    return nullptr;
}

template<typename T, class IsLess>
Node<T>* Tree<T, IsLess>::findMin(Node<T>* node) {
    while(node->left_child) {
        node = (node->left_child);
    }
    return node;
}

template<typename T, class IsLess>
Node<T>* Tree<T, IsLess>::findMax(Node<T>* node) {
    while(node->right_child) {
        node = (node->right_child);
    }
    return node;
}
