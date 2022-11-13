#pragma once  // pragme once

#include <memory>
#include <queue>
#include <iostream>

#include "iterator.hpp"


template<class T> class AvlTree;

template <typename T>
class Node {
    T m_data;
    Node* m_left;
    Node* m_right;
    Node* m_parent;
    size_t m_height;

    explicit Node(const T &data, Node *parent = nullptr) : m_data{data}, m_left{nullptr}, m_right{nullptr},
                                                            m_parent{parent}, m_height{1} {

    };
    Node(const Node &other) : Node (other.m_data) {};
    ~Node() = default;

    template<class> friend class AvlTree;
    public:
        friend std::ostream &operator<< (std::ostream &os, const Node &curNode) {
            return os << curNode.m_data;
        }
};

template<typename T>
class AvlTree {

public:
    typedef AvlTreeIterator<Node<T>> iterator;
    typedef AvlTreeIterator<const Node<T>> const_iterator;

    AvlTree() : m_root(nullptr), m_size(0) {};
    AvlTree(const std::initializer_list<T> &list);
    ~AvlTree();

    void Add(const T &data);
    void Delete(const T &data);
    bool Has(const T &data) const;


    void Add(const Node<T> &curNode) { Add(curNode.m_data); }
    void Delete(const Node<T> &curNode) { Delete(curNode.m_data); }
    void Has(const Node<T> &curNode) { Has(curNode.m_data); }


    size_t Size() const { return m_size; }
    bool Empty() const { return m_size == 0; }

    iterator Begin();
    iterator End();

    const_iterator Begin() const;
    const_iterator End() const;
    // search functions 
    Node<T>* find(const T& data);
    Node<T>* findLowerBound(const T& data); // call find. addresed "next" field in returned Node in find method.

    void BFS();
    void dfsInOrder(Node<T>* curNode);

    Node<T>* getRoot() {return m_root;}

private:
    Node<T>* m_root = nullptr;
    size_t m_size;

    Node<T> *findMin(Node<T> *curNode);

    Node<T> *rotateRight(Node<T> *&curNode);
    Node<T> *rotateLeft(Node<T> *&curNode);

    Node<T> *doBalance(Node<T> *&curNode);
    void fixHeight(Node<T> *&curNode);
    short getBalance(Node<T> *curNode);
    size_t getHeight(Node<T> *&curNode);

    bool innerAdd(Node<T> *newNode, Node<T> *&curNode);
    bool innerDelete(const T &data);
    void DeleteNode(Node<T>*& deletedNode);

    void destroyTree(Node<T>* curNode);
};

template <typename T>
Node<T>* AvlTree<T>::find(const T& data) {
    if (!m_root) { return nullptr; }

    Node<T>* curNode = m_root;

    while(curNode) {
        if (curNode->m_data == data) {
            return curNode;
        }

        if (curNode->m_data > data) {
            curNode = curNode->m_left;
        } else {
            curNode = curNode->m_right;
        }
    }

    return nullptr;
}

#include "srcConstructor.hpp"
#include "srcAccess.hpp"
#include "srcModify.hpp"
#include "srcBalance.hpp"
#include "srcTraverse.hpp"
