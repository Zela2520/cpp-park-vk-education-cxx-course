#pragma once // pragma once


template<typename T, class IsLess>
void Tree<T, IsLess>::addLinks(Node<T>* new_node) {
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
