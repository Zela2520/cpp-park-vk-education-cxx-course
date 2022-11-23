#pragma once // pragma once

template<typename T, class IsLess>
template<class Action>
void Tree<T, IsLess>::postOrderTree(Node<T>* begin, const Action& act) {
    Node<T>* it = begin;
    std::stack<Node<T>*> stack;
    Node<T>* last_visited_node = nullptr;
    Node<T>* top_node = nullptr;

    while (!stack.empty() || it != nullptr) {
        if (it) {
            stack.push(it);
            it = it->left_child;
        } else {
            top_node = stack.top();
            if (!(top_node->right_child == nullptr) && !(last_visited_node == top_node->right_child)) {
                it = top_node->right_child;
            } else {
                stack.pop();
                last_visited_node = top_node;
                act(*top_node);
            }
        }
    }
}


template<typename T, class IsLess>
void Tree<T, IsLess>::bfs() {
    std::queue<Node<T>*> m_queue;
    m_queue.push(root);

    while(!m_queue.empty()) {
        Node<T>* curNode = m_queue.front();
        m_queue.pop();
        if (curNode) {
            std::cout << "data: " << curNode->value;
            if (curNode->next) {
                std::cout << "  \tnext: " << curNode->next->value;
            }
            if (curNode->prev) {
                std::cout << "  \tprev: " << curNode->prev->value;
            }

            std::cout << "\theight: " << curNode->height;

            if (curNode->parent) {
                std::cout << "\tparent: " << curNode->parent->value;
            }

            std::cout << std::endl;

            if (curNode->left_child) {
                m_queue.push(curNode->left_child);
            }

            if (curNode->right_child) {
                m_queue.push(curNode->right_child);
            }
        }

    }
}
