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

    bool Delete(Node<T>*& root, T data);
    void DeleteNode(Node<T>*& deletedNode);

    void bfs(Node<T>* root);

};

template <typename T>
void DeleteNode(Node<T>*& deletedNode) {

}

template <typename T>
bool Node<T>::Delete(Node<T>*& root, T data) {
    if (!root) { return false; }

    Node<T>* curNode = find(root, data);
    if (curNode) {
        DeleteNode(curNode);
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
        std::cout << tmpNode->m_data << std::endl;
        m_queue.pop();

        if (tmpNode->m_left != nullptr) {
            m_queue.push(tmpNode->m_left);
        }
        if (tmpNode->m_right != nullptr) {
            m_queue.push(tmpNode->m_right);
        }
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

    root->bfs(root);

    Node<int>* findElem = root->find(root, 20);

    if (!findElem) {
        std::cout << "Element doesn't exist" << std::endl; 
    } else {
        std::cout << findElem->m_data << std::endl;
    }


    return 0;
}
