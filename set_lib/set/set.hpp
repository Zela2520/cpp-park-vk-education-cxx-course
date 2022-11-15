#pragma once  // pragme once

#include <iostream>
#include <cassert>
#include <stack>
#include <queue>
#include <memory>


#include "iterator.hpp"

template<class T, class IsLess> class Tree;

template<typename T1>
struct Node {
    Node<T1>* parent;
    Node<T1>* left_child;
    Node<T1>* right_child;
    Node<T1>* next;
    Node<T1>* prev;

    int height;
    size_t size;
    T1 value;

    Node() : parent(nullptr), left_child(nullptr), right_child(nullptr), next(nullptr), prev(nullptr), height(1), size(1) {}
    Node(T1 _value) : parent(nullptr), left_child(nullptr), right_child(nullptr), next(nullptr), prev(nullptr), height(1), size(1), value(_value) {}

    friend std::ostream &operator<< (std::ostream &os, const Node &curNode) {
        return os << curNode.value;
    }

    template<class> friend class AvlTreeIterator;
};


template<typename T, class IsLess>
class Tree {
    Node<T>* root;
    IsLess isLess;

    int bFactor(Node<T>* begin) {return Height(begin->right_child) - Height(begin->left_child);}
    Node<T>* rotateRight(Node<T>* begin);
    Node<T>* rotateLeft(Node<T>* begin);
    void Balance(Node<T>* begin);
    void fixHeight(Node<T>* begin);
    void fixSize(Node<T>* begin);

    int Height(Node<T>* node) {return node ? node->height : 0;}
    size_t Size(Node<T>* node) {return node ? node->size : 0;}


    Node<T>* popMin(Node<T>* begin);
    Node<T>* findMin(Node<T>* targetBranch);
    Node<T>* findMax(Node<T>* targetBranch);

public:
    typedef AvlTreeIterator<Node<T>> iterator;
    typedef AvlTreeIterator<const Node<T>> const_iterator;

    Tree(const IsLess& is_less = IsLessDefault<T>());
    Tree(const T&) = delete;
    Tree(const std::initializer_list<T> &list);
    Tree& operator=(const Tree &other) = delete;
    ~Tree();

    iterator begin();
    iterator end();

    iterator rbegin();
    iterator rend();

    const_iterator begin() const;
    const_iterator end() const;

    const_iterator rbegin() const;
    const_iterator rend() const;

    void Add(const T& elem);
    void Erase(const T& elem);
    bool Has(const T &data) const;

    void Add(const Node<T> &curNode) { Add(curNode.value); }
    void Erase(const Node<T> &curNode) { Erase(curNode.value); }
    void Has(const Node<T> &curNode) { Has(curNode.value); }

    Node<T>* Root() const {return root;}
    bool isEmpty() const {return root == nullptr;}
    size_t Size() {if (isEmpty()) {return 0;} return root->size;}

    // search functions
    Node<T>* Find(const T& elem) const; // +
    Node<T>* findLowerBound(const T& data) const; // +
    Node<T>* getRoot() {return root;} // +
    T getRootData() const {return root->value;} // +

    template<class Action = ActionDefault<T>>
    void postOrderTree(Node<T>* begin, const Action& act);
    void bfs();
};

#include "srcConstructor.hpp"
#include "srcBalance.hpp"
#include "srcAccess.hpp"
#include "srcModify.hpp"
#include "srcTraverse.hpp"
