#pragma once  // pragma once

template<class T>
typename AvlTree<T>::iterator AvlTree<T>::Begin() {
    if (m_root) {
        Node<T>* curNode = m_root;

        while (curNode->m_left) {
            curNode = curNode->m_left;
        }
        return typename AvlTree<T>::iterator(curNode);
    }

    return nullptr;
}

template<class T>
typename AvlTree<T>::iterator AvlTree<T>::End() {
    return nullptr;
}

template<class T>
typename AvlTree<T>::const_iterator AvlTree<T>::Begin() const {
    if (m_root) {
        Node<T> *curNode = m_root;
        while (curNode->m_left) {
            curNode = curNode->m_left;
        }
        return typename AvlTree<T>::const_iterator(curNode);
    }

    return nullptr;
}

template<class T>
typename AvlTree<T>::const_iterator AvlTree<T>::End() const {
    return nullptr;
}

template<class T>
Node<T>* AvlTree<T>::findMin(Node<T>* curNode) {
    while(curNode->m_left) {
        curNode = (curNode->m_left);
    }

    return curNode;
}
