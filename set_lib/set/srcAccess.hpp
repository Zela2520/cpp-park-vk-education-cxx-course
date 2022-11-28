#pragma once  // pragma once

template<typename T, class IsLess>
typename Tree<T, IsLess>::iterator Tree<T, IsLess>::find(const T& elem) const {
    Node<T>* it = root;

    while (it) {
        if (it->value == elem) {
            return typename Tree<T, IsLess>::iterator(it);
        }

        if (isLess(elem, it->value)) {
            it = it->left_child;
        } else {
            it = it->right_child;
        }
    }
    return typename Tree<T, IsLess>::iterator(nullptr);
}

template<typename T, class IsLess>
Node<T>* Tree<T, IsLess>::FindNode(const T& elem) const {
    Node<T>* it = root;

    while (it) {
        if (it->value == elem) {
            return it;
        }

        if (isLess(elem, it->value)) {
            it = it->left_child;
        } else {
            it = it->right_child;
        }
    }

    return nullptr;
}

template<typename T, class IsLess>
typename Tree<T, IsLess>::iterator Tree<T, IsLess>::lower_bound(const T& data) const {
    if (FindNode(data)) {
        return typename Tree<T, IsLess>::iterator(FindNode(data)->next);
    }

    Node<T>* curNode = findMin(root);
    while (curNode) {
        if (curNode->value > data) {
            return typename Tree<T, IsLess>::iterator(curNode);
        }
        curNode = curNode->next;
    }
    return typename Tree<T, IsLess>::iterator(nullptr);
}

template<typename T, class IsLess>
Node<T>* Tree<T, IsLess>::findLowerBound(const T& data) const {
    if (FindNode(data)) {
        return FindNode(data)->next;
    }

    Node<T>* curNode = findMin(root);
    while (curNode) {
        if (curNode->value > data) {
            return curNode;
        }
        curNode = curNode->next;
    }
    return nullptr;
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
        if (!saved_min->next || !saved_min->prev) {
            if (!saved_min->prev) {
                saved_min->next->prev = nullptr;
            } else {
                it->prev->next = nullptr;
            }
            saved_min->next = saved_min->prev = nullptr;
        } else {
            saved_min->prev->next = saved_min->next;
            saved_min->next->prev = saved_min->prev;
            saved_min->prev = saved_min->next = nullptr;
        }

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
        if (!it->next || !it->prev) {
            if (!it->prev) {
                it->next->prev = nullptr;
            } else {
                it->prev->next = nullptr;
            }
            it->next = it->prev = nullptr;
        } else {
            it->prev->next = it->next;
            it->next->prev = it->prev;
            it->prev = it->next = nullptr;
        }

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
Node<T>* Tree<T, IsLess>::findMin(Node<T>* node) const {
    while(node->left_child) {
        node = (node->left_child);
    }
    return node;
}

template<typename T, class IsLess>
Node<T>* Tree<T, IsLess>::findMax(Node<T>* node) const {
    while(node->right_child) {
        node = (node->right_child);
    }
    return node;
}
