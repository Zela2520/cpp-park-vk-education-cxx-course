#pragma once // pragma once

template<typename T>
void AvlTree<T>::BFS() {
    std::queue<Node<T>*> m_queue;
    m_queue.push(m_root);

    while(!m_queue.empty()) {
        Node<T>* curNode = m_queue.front();
        m_queue.pop();

        std::cout << "data: " << curNode->m_data;
        std::cout << "   height: " << curNode->m_height;
        if (curNode->m_parent) {
            std::cout << "   parent: " << curNode->m_parent->m_data;
        }

        std::cout << std::endl;

        if (curNode->m_left) {
            m_queue.push(curNode->m_left);
        }

        if (curNode->m_right) {
            m_queue.push(curNode->m_right);
        }
    }
}

template<typename T>
void AvlTree<T>::dfsInOrder(Node<T>* curNode) {
    if (curNode) {
        dfsInOrder(curNode->m_left);
        std::cout << "value: " << curNode->m_data << std::endl;
        dfsInOrder(curNode->m_right);
    }
}
