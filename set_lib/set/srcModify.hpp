#pragma once // pragma once

template<class T>
void AvlTree<T>::Add(const T &data) {
    if (innerAdd(new Node(data), m_root)) {
        ++m_size;
    }
}

template<class T>
void AvlTree<T>::Delete(const T &data) {
    if (innerDelete(data, m_root) && m_size > 0) {
        --m_size;
    }
}

template<class T>
bool AvlTree<T>::Has(const T &data) const{
    Node<T>* curNode = m_root;
    while(curNode) {
        if (curNode->m_data == data) {
            return true;
        }
        else if (curNode->m_data < data) {
            curNode = curNode->m_right;
        }
        else {
            curNode = curNode->m_left;
        }
    }
    return false;
}

template<class T>
bool AvlTree<T>::innerAdd(Node<T>* newNode, Node<T>* &root) {

    if (!root) {
        root = newNode;
        return true;
    }

    Node<T>* curNode = root;
    Node<T>* AddNodeParent = nullptr;

    while (curNode) {
        if (curNode->m_data == newNode->m_data) {
            return false;
        } else if (curNode->m_data > newNode->m_data) {
            AddNodeParent = curNode;
            curNode = curNode->m_left;
            if (!curNode) {
                curNode = newNode;
                AddNodeParent->m_left = curNode;
                curNode->m_parent = AddNodeParent;

                auto* tmp = curNode->m_parent;
                while (tmp) {
                    tmp = doBalance(tmp);
                    auto* child = tmp;
                    tmp = tmp->m_parent;
                    if (!tmp) {
                        m_root = child;
                    }
                }
                return true;
            }
        } else {
            AddNodeParent = curNode;
            curNode = curNode->m_right;
            if (!curNode) {
                curNode = newNode;
                AddNodeParent->m_right = curNode;
                curNode->m_parent = AddNodeParent;

                auto* tmp = curNode->m_parent;
                while (tmp) {
                    tmp = doBalance(tmp);
                    auto* child = tmp;
                    tmp = tmp->m_parent;
                    if (!tmp) {
                        m_root = child;
                    }
                }
                return true;
            }
        }
    }

    return false;
}
