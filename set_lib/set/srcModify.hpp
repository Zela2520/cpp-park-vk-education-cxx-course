#pragma once // pragma once

template<class T>
void AvlTree<T>::Add(const T &data) {
    if (innerAdd(new Node(data), m_root)) {
        ++m_size;
    }
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

                Node<T>* tmp = curNode->m_parent;
                while (tmp) {
                    tmp = doBalance(tmp);
                    Node<T>* child = tmp;
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

                Node<T>* tmp = curNode->m_parent;
                while (tmp) {
                    tmp = doBalance(tmp);
                    Node<T>* child = tmp;
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

template<class T>
void AvlTree<T>::Delete(const T &data) {
    if (innerDelete(data) && m_size > 0) {
        --m_size;
    }
}

template<class T>
bool AvlTree<T>::innerDelete(const T &data) {
    if (!m_root) { return false; }
    Node<T>* curNode = find(data);
    if (curNode) {
        std::cout << "deleted data: " << curNode->m_data << std::endl << std::endl;
        DeleteNode(curNode);
        return true;
    }

    return false;
}

template<class T>
void AvlTree<T>::DeleteNode(Node<T>*& deletedNode) {
    if (deletedNode == m_root) {
        if (!m_root->m_right && !m_root->m_left) {
            delete m_root;
            m_root = nullptr;
        } else {
            if (!m_root->m_left) {
                m_root = m_root->m_right;
                delete m_root->m_parent;
                m_root->m_parent = nullptr;
            }
            else if (!m_root->m_right) {
                m_root = m_root->m_left;
                delete m_root->m_parent;
                m_root->m_parent = nullptr;
            }
        }
        return;
    }
    if (!deletedNode->m_left && !deletedNode->m_right) { // случай для листового узла
        std::cout << "Branches doesn't exist." << std::endl;
        if (deletedNode->m_parent) {
            if (deletedNode->m_parent->m_left == deletedNode) {
                deletedNode->m_parent->m_left = nullptr;
            } else if (deletedNode->m_parent->m_right == deletedNode) {
                deletedNode->m_parent->m_right = nullptr;
            }
        }
        
        if (deletedNode->m_parent) {
            Node<T>* tmp = deletedNode->m_parent;
                while (tmp) {
                tmp = doBalance(tmp);
                Node<T>* child = tmp;
                tmp = tmp->m_parent;
                if (!tmp) {
                    m_root = child;
                }
            }
        }
        delete deletedNode;
    } else {
        if (!deletedNode->m_left) { // случай когда левой ветви нет

            deletedNode->m_right->m_parent = deletedNode->m_parent;
            if (deletedNode->m_parent) {
                if (deletedNode == deletedNode->m_parent->m_right) {
                    deletedNode->m_parent->m_right = deletedNode->m_right;
                } else if (deletedNode == deletedNode->m_parent->m_left) {
                    deletedNode->m_parent->m_left = deletedNode->m_right;
                }
            }
            
            if (deletedNode->m_parent) {
                Node<T>* tmp = deletedNode->m_parent;
                while (tmp) {
                    tmp = doBalance(tmp);
                    Node<T>* child = tmp;
                    tmp = tmp->m_parent;
                    if (!tmp) {
                        m_root = child;
                    }
                }
            }
            delete deletedNode;
        } else if (!deletedNode->m_right) { // случай когда правой ветви нет

            deletedNode->m_left->m_parent = deletedNode->m_parent;
            if (deletedNode->m_parent) {
                if (deletedNode == deletedNode->m_parent->m_right) {
                    deletedNode->m_parent->m_right = deletedNode->m_left;
                } else if (deletedNode == deletedNode->m_parent->m_left) {
                    deletedNode->m_parent->m_left = deletedNode->m_left;
                }
            }
            
            if (deletedNode->m_parent) {
                Node<T>* tmp = deletedNode->m_parent;
                while (tmp) {
                    tmp = doBalance(tmp);
                    Node<T>* child = tmp;
                    tmp = tmp->m_parent;
                    if (!tmp) {
                        m_root = child;
                    }
                }
            }
            delete deletedNode;
        } else { // обе ветки есть
            std::cout << "Both branches exist" << std::endl;

            Node<T>* minParrent = deletedNode;
            Node<T>* min = deletedNode->m_right;

            while (min->m_left) {
                minParrent = min;
                min = min->m_left;
            }

            if (minParrent->m_left == min) {
                minParrent->m_left = min->m_right;
                if (min->m_right) {
                    min->m_right->m_parent = minParrent;
                }
                min->m_parent = min->m_left = min->m_right = nullptr;
            }

            if (minParrent->m_right == min) {
                minParrent->m_right = min->m_right;
                if (min->m_right) {
                    min->m_right->m_parent = minParrent;
                }
                min->m_parent = min->m_left = min->m_right = nullptr;
            }

            deletedNode->m_data = min->m_data;

            min->m_right = nullptr;
            if (min->m_parent) {
                Node<T>* tmp = min->m_parent;
                while (tmp) {
                    tmp = doBalance(tmp);
                    Node<T>* child = tmp;
                    tmp = tmp->m_parent;
                    if (!tmp) {
                        m_root = child;
                    }
                }
            }
            delete min;
        }
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
void AvlTree<T>::destroyTree(Node<T>* curNode) {
    if (curNode) {
        destroyTree(curNode->m_left);
        destroyTree(curNode->m_right);
        delete curNode;
    }
}
