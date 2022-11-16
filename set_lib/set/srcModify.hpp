#pragma once // pragma once

template<typename T, class IsLess>
void Tree<T, IsLess>::Add(const T& elem) {
    if (root->size == 0) {
        root->value = elem;
        ++root->size;
        return;
    }

    Node<T>* it = root;
    Node<T>* new_node = new Node<T>;
    new_node->value = elem;
    new_node->height = 1;

    Node<T>* saved_parent;
    while (it) {
        saved_parent = it;
        if (it->value == new_node->value) {
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
    if (new_node == root && new_node->left_child && new_node->right_child) {
        new_node->left_child->next = new_node;
        new_node->prev = new_node->left_child;
        new_node->next = new_node->right_child;
        new_node->right_child->prev = new_node;
    } else {
        if (new_node->parent && new_node->parent->left_child == new_node) {   // если нода вставлена влево
            if (new_node->right_child) {
                new_node->next = findMin(new_node->right_child);
                new_node->next->prev = new_node;
            } else {
                new_node->next = new_node->parent; // для левого сына, next - его родитель.
                new_node->parent->prev = new_node;
            }


            if (new_node->left_child) {
                Node<T>* prevNode = findMax(new_node->left_child);
                new_node->prev = prevNode;
                prevNode->next = new_node;
            } else {
                auto ptr = new_node->parent;
                while (ptr->parent && ptr->parent->left_child == ptr) {
                    ptr = ptr->parent;
                }
                if (ptr->parent && ptr->parent->right_child == ptr) {
                    ptr->parent->next = new_node;
                    new_node->prev = ptr->parent;
                }
            }
        } else if (new_node->parent && new_node->parent->right_child == new_node) {   // если нода вставлена вправо
            new_node->parent->next = findMin(new_node);
            if (new_node->left_child) {
                new_node->prev = findMin(new_node);
                new_node->prev->next = new_node;
            } else {
                new_node->prev = new_node->parent;
            }

            // расмматриваем левое поддерево правого поддерева
            if (new_node->right_child) {
                Node<T>* nextNode = findMin(new_node->right_child);
                new_node->next = nextNode;
                nextNode->prev = new_node;
            } else {
                // поднимаемся из правого поддерева левого поддерева
                auto ptr = new_node->parent;
                while (ptr->parent && ptr->parent->right_child == ptr) {
                    ptr = ptr->parent;
                }
                if (ptr->parent && ptr->parent->left_child == ptr) {
                    new_node->next = ptr->parent;
                    ptr->parent->prev = new_node;
                }
            }
        }
    }
}

template<typename T, class IsLess>
void Tree<T, IsLess>::Erase(const T& elem) {

    Node<T>* del_node = Find(elem);
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

        if (!del_node->next || !del_node->value) {
            del_node->next = del_node->prev = nullptr;
        } else {
            del_node->prev->next = del_node->next;
            del_node->next->prev = del_node->prev;
            del_node->prev = del_node->next = nullptr;
        }


        delete del_node;
    }

}
