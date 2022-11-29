#pragma once // pragma once


template<typename T, class IsLess>
void Tree<T, IsLess>::insert(const T& elem) {
    if (root->size == 0) {
        Node<T>* newRoot = new Node<T>(elem);
        delete root;
        
        root = newRoot;
        ++root->size;
        return;
    }

    Node<T>* it = root;
    Node<T>* new_node = new Node<T>(elem);
    new_node->height = 1;

    Node<T>* saved_parent;
    while (it) {
        saved_parent = it;
        if (!isLess(it->getValue(), new_node->getValue()) && !isLess(new_node->getValue(), it->getValue())) {
            delete new_node;
            return;
        }
        if (isLess(*new_node, *it)) {
            it = it->left_child;
        } else {
            it = it->right_child;
        }
    }

    new_node->parent = saved_parent;
    if (isLess(*new_node, *saved_parent)) {
        saved_parent->left_child = new_node;
    } else {
        saved_parent->right_child = new_node;
    }

    Balance(saved_parent);
    insertLinks(new_node);
}

template<typename T, class IsLess>
void Tree<T, IsLess>::erase(const T& elem) {

    Node<T>* del_node = FindNode(elem);
    if (!del_node) {
        return;
    }

    if (del_node == root && del_node->size == 1) {
        delete root;
        root = nullptr;
        return;
    }

    if (del_node->right_child) {
        Node<T>* min = popMin(del_node->right_child);
        del_node->value = min->value;
        delete min;
        return;
    } else {
        if (!del_node->left_child) {
            Node<T>* saved_parent = del_node->parent;
            if (del_node == root) {
                return;
            }

            if (isLess(*del_node, *del_node->parent)) {
                del_node->parent->left_child = nullptr;
            } else {
                del_node->parent->right_child = nullptr;
            }

            del_node->parent = nullptr;
            Balance(saved_parent);

            if (!del_node->next || !del_node->prev) {
                if (!del_node->prev) {
                    del_node->next->prev = nullptr;
                } else {
                    del_node->prev->next = nullptr;
                }
                del_node->next = del_node->prev = nullptr;
            } else {
                del_node->prev->next = del_node->next;
                del_node->next->prev = del_node->prev;
                del_node->prev = del_node->next = nullptr;
            }
            delete del_node;
            return;
        }
        del_node->left_child->parent = del_node->parent;

        if (del_node == root) {
            root = del_node->left_child;
            del_node->left_child->parent = nullptr;
        } else if (isLess(*del_node->left_child, *del_node->parent)) {
            del_node->parent->left_child = del_node->left_child;
        } else {
            del_node->parent->right_child = del_node->left_child;
        }

        Balance(del_node->left_child);
        
        if (!del_node->next || !del_node->prev) {
            del_node->next = del_node->prev = nullptr;
        } else {
            del_node->prev->next = del_node->next;
            del_node->next->prev = del_node->prev;
            del_node->prev = del_node->next = nullptr;
        }


        delete del_node;
    }

}
