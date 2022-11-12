#pragma once // pragma once

template<class T>
size_t AvlTree<T>::getHeight(Node<T>* &curNode) {
    return curNode ? curNode->m_height : 0;
}

template<class T>
void AvlTree<T>::fixHeight(Node<T>* &curNode) {
    curNode->m_height = std::max(getHeight(curNode->m_left), getHeight(curNode->m_right)) + 1;
}

template<class T>
short AvlTree<T>::getBalance(Node<T>* curNode) {
    return getHeight(curNode->m_right) - getHeight(curNode->m_left);
}

template<class T>
Node<T>* AvlTree<T>::doBalance(Node<T>* &curNode) {
    fixHeight(curNode);
    
    switch (getBalance(curNode)) {
        case 2: {
            if (getBalance(curNode->m_right) < 0) {
                curNode->m_right = rotateRight(curNode->m_right);
            }
            return rotateLeft(curNode);
        }
        case -2: {
            if (getBalance(curNode->m_left) > 0) {
                curNode->m_left = rotateLeft(curNode->m_left);
            }
            return rotateRight(curNode);
        }
        default: {
            return curNode;
        }
    }
}

template<typename T>
Node<T>* AvlTree<T>::rotateLeft(Node<T> *&curNode) {
    Node<T>* newRoot = curNode->m_right;
    curNode->m_right = newRoot->m_left;
    newRoot->m_left = curNode;

    newRoot->m_parent = newRoot->m_left->m_parent;
    newRoot->m_left->m_parent = newRoot;

    if (newRoot->m_parent) {
        newRoot->m_parent->m_right = newRoot;
    }

    if (newRoot->m_left->m_right) {
        newRoot->m_left->m_right->m_parent = newRoot->m_left;
    }

    fixHeight(newRoot->m_left);
    fixHeight(newRoot);

    return newRoot;
}

template<typename T>
Node<T>* AvlTree<T>::rotateRight(Node<T> * &curNode) {
    Node<T>* newRoot = curNode->m_left;
    curNode->m_left = newRoot->m_right;
    newRoot->m_right = curNode;

    newRoot->m_parent = newRoot->m_right->m_parent;
    newRoot->m_right->m_parent = newRoot;

    if (newRoot->m_parent) {
        newRoot->m_parent->m_left = newRoot;
    }

    if (newRoot->m_right->m_left) {
        newRoot->m_right->m_left->m_parent = newRoot->m_right;
    }

    fixHeight(newRoot->m_right);
    fixHeight(newRoot);
    
    return newRoot;
}
