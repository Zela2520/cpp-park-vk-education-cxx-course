#include <iostream>
#include <cassert>
#include <queue>
#include "set.hpp"

template <typename T>
struct Node {
    T m_data;
    Node* m_left;
    Node* m_right;
    Node* m_parrent;

    Node(T data = T{}, Node* left = nullptr, Node* right = nullptr, Node* parrent = nullptr) : m_data(data), m_left(left), m_right(right), m_parrent(parrent) {}

    Node<T>* find(Node<T>*& root, T data); // O(h), где h - глубина дерева 
    Node<T>* findMinimum(Node<T>*& root); // O(h), где h - глубина дерева
    Node<T>* findMaximum(Node<T>*& root); // O(h), где h - глубина дерева

    void insert(Node<T>*& root, T data); // O(h), где h - глубина дерева

    void DeleteNode(Node<T>*& deletedNode); // O(h), где h - глубина дерева
    bool Delete(Node<T>*& root, T data); // O(h), где h - глубина дерева

    void bfs(Node<T>* root);
    void dfsInOrder(Node<T>* root);

};

template <typename T>
void Node<T>::DeleteNode(Node<T>*& deletedNode) {
    if (!deletedNode->m_left && !deletedNode->m_right) {
        std::cout << "Branches doesn't exist" << std::endl;
        delete deletedNode;
        deletedNode = nullptr;
    } else {
        if (!deletedNode->m_left) {
            std::cout << "Right branch exist" << std::endl;
            deletedNode->m_parrent->m_right = deletedNode->m_right;
            delete deletedNode;
            deletedNode = nullptr;
        } else if (!deletedNode->m_right) {
            std::cout << "Left branch exist" << std::endl;
            deletedNode->m_parrent->m_left = deletedNode->m_left;
            delete deletedNode;
            deletedNode = nullptr;
        } else { // оба поддерева есть
            std::cout << "Both branches exist" << std::endl;

            Node<T>* min = deletedNode->m_right;
            while (min->m_left) {
                min = min->m_left;
            }

            if (min->m_parrent->m_left == min) {
                min->m_parrent->m_left = min->m_right;
            }

            if (min->m_parrent->m_right == min) {
                min->m_parrent->m_right = min->m_right;
            }

            deletedNode->m_data = min->m_data;
            delete min;
            min = min->m_left = min->m_right = nullptr;
        }
    }  
}

template <typename T>
bool Node<T>::Delete(Node<T>*& root, T data) {
    if (!root) { return false; }

    Node<T>* curNode = find(root, data);
    if (curNode) {
        // std::cout << "deleted data: " << curNode->m_data << std::endl;
        DeleteNode(curNode);
        // std::cout << "updated node data: " << curNode->m_data << std::endl;
        return true;
    }

    return false;
}

template <typename T>
Node<T>* Node<T>::find(Node<T>*& root, T data) {
    if (!root) { return nullptr; }

    Node<T>* curNode = root;

    while(curNode) {
        if (curNode->m_data == data) {
            return curNode;
        }

        if (curNode->m_data >= data) {
            curNode = curNode->m_left;
        } else {
            curNode = curNode->m_right;
        }
    }

    return nullptr;
}

template <typename T>
Node<T>* Node<T>::findMinimum(Node<T>*& root) {
    assert(root != nullptr);

    Node<T>* curNode = root;

    while (curNode->m_left) {
        curNode = curNode->m_left;
    }

    return curNode;
}

template <typename T>
Node<T>* Node<T>::findMaximum(Node<T>*& root) {
    assert(root != nullptr);

    Node<T>* curNode = root;

    while (curNode->m_right) {
        curNode = curNode->m_right ;
    }

    return curNode;
}

template <typename T>
void Node<T>::insert(Node<T>*& root, T data) {

    std::cout << "************insert debug************" << std::endl;

    if (root == nullptr) {
        root = new Node<T>(data, nullptr, nullptr, root);
        std::cout << "root value: " << root->m_data << std::endl;
        std::cout << "************insert debug first step end************" << std::endl;
        return;
    }

    Node<T>* curNode = root;
    Node<T>* insertNodeParrent;

    while (curNode) {
        if (curNode->m_data >= data) {
            insertNodeParrent = curNode;
            curNode = curNode->m_left;
            if (!curNode) {
                std::cout << "insertNodeParrent value: " << insertNodeParrent->m_data << std::endl;
                curNode = new Node<T>(data, nullptr, nullptr, insertNodeParrent);
                insertNodeParrent->m_left = curNode;
                std::cout << "curNode data: " << curNode->m_data << std::endl;
                return;
            }
        } else {
            insertNodeParrent = curNode;
            curNode = curNode->m_right;
            if (!curNode) {
                std::cout << "insertNodeParrent value: " << insertNodeParrent->m_data << std::endl;
                curNode = new Node<T>(data, nullptr, nullptr, insertNodeParrent);
                insertNodeParrent->m_right = curNode;
                std::cout << "curNode data: " << curNode->m_data << std::endl;
                return;
            }
        }
    }

    std::cout << "************insert debug end************" << std::endl;
}

template <typename T>
void Node<T>::bfs(Node<T>* root) {
    if (!root) { return; }
    std::queue<Node<T>*> m_queue;
    m_queue.push(root);

    while(!(m_queue.empty())) {
        Node<T>* tmpNode = m_queue.front();
        if (tmpNode != nullptr) {
            std::cout << "value: " << tmpNode->m_data << std::endl;
        }

        m_queue.pop();

        if (tmpNode->m_left != nullptr) {
            m_queue.push(tmpNode->m_left);
            std::cout << "parrent value: " << tmpNode->m_data << std::endl;
            std::cout << "left child value: " << tmpNode->m_left->m_data << std::endl;
        }
        if (tmpNode->m_right != nullptr) {
            m_queue.push(tmpNode->m_right);
            std::cout << "right child value: " << tmpNode->m_right->m_data << std::endl;
        }
    }
}

template <typename T>
void Node<T>::dfsInOrder(Node<T>* root) {
    if (root) {
        dfsInOrder(root->m_left);
        std::cout << "value: " << root->m_data << std::endl;
        dfsInOrder(root->m_right);
    }
}

int main() {
    Node<int>* root = nullptr;

    root->insert(root, 10);

    root->insert(root, 5);
    root->insert(root, 15);

    root->insert(root, 3);
    root->insert(root, 7);
    root->insert(root, 13);
    root->insert(root, 17);

    root->insert(root, 2);
    root->insert(root, 4);
    root->insert(root, 6);
    root->insert(root, 8);
    root->insert(root, 12);
    root->insert(root, 14);
    root->insert(root, 16);
    root->insert(root, 18);
    root->insert(root, 19);

    for (int i = 2; i < 20; ++i) {
        std::cout << i << std::endl; 
        root->Delete(root, i);
    }

    root->dfsInOrder(root);

    Node<int>* findElem = root->find(root, 8);

    if (!findElem) {
        std::cout << "Element doesn't exist" << std::endl; 
    } else {
        std::cout << "findElem data:" << findElem->m_data << std::endl;
    }

    return 0;
}
