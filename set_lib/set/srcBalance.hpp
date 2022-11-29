#pragma once // pragma once

template<typename T, class IsLess>
void Tree<T, IsLess>::fixHeight(Node<T>* begin) {
    if (!begin) {
        return;
    }

    int hl = Height(begin->left_child);
    int hr = Height(begin->right_child);

    begin->height = ((hl > hr) ? hl : hr) + 1;

    fixHeight(begin->parent);
}

template<typename T, class IsLess>
void Tree<T, IsLess>::fixSize(Node<T>* begin) {
    if (!begin) {
        return;
    }

    begin->size = Size(begin->left_child) + Size(begin->right_child) + 1;

    fixSize(begin->parent);
}

template<typename T, class IsLess>
Node<T>* Tree<T, IsLess>::rotateRight(Node<T>* begin) {
    Node<T>* tmp_left = begin->left_child;
    begin->left_child = tmp_left->right_child;
    if (tmp_left->right_child) {
        tmp_left->right_child->parent = begin;
    }

    tmp_left->right_child = begin;

    tmp_left->parent = begin->parent;

    if (begin == Root()) {
        tmp_left->parent = nullptr;
        root = tmp_left;
    } else if (isLess(tmp_left->value, begin->parent->value)) {
        begin->parent->left_child = tmp_left;
    } else {
        begin->parent->right_child = tmp_left;
    }

    begin->parent = tmp_left;

    fixHeight(begin);
    fixHeight(tmp_left);

    fixSize(begin);
    fixSize(tmp_left);

    return tmp_left;
}

template<typename T, class IsLess>
Node<T>* Tree<T, IsLess>::rotateLeft(Node<T>* begin) {
    Node<T>* tmp_right = begin->right_child;
    begin->right_child = tmp_right->left_child;
    if (tmp_right->left_child) {
        tmp_right->left_child->parent = begin;
    }

    tmp_right->left_child = begin;

    tmp_right->parent = begin->parent;

    if (begin == Root()) {
        tmp_right->parent = nullptr;
        root = tmp_right;
    } else if (isLess(tmp_right->value, begin->parent->value)) {
        begin->parent->left_child = tmp_right;
    } else {
        begin->parent->right_child = tmp_right;
    }

    begin->parent = tmp_right;

    fixHeight(begin);
    fixHeight(tmp_right);

    fixSize(begin);
    fixSize(tmp_right);

    return tmp_right;
}

template<typename T, class IsLess>
void Tree<T, IsLess>::Balance(Node<T>* begin) {
    if (!begin) {
        return;
    }

    fixHeight(begin);
    fixSize(begin);
    if (bFactor(begin) == 2) {
        if (bFactor(begin->right_child) < 0) {
            rotateRight(begin->right_child);
        }
        rotateLeft(begin);
        return;
    }

    if (bFactor(begin) == -2) {
        if (bFactor(begin->left_child) > 0 ) {
            rotateLeft(begin->left_child);
            rotateRight(begin);
        } else {
            rotateRight(begin);
        }
        return;
    }

    Balance(begin->parent);
}
