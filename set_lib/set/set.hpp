#pragma once  // pragme once

#include <iostream>
#include <cassert>
#include <stack>
#include <queue>
#include <memory>
#include <typeinfo>
#include <iterator>


template<typename T>
class IsLessDefault;

template<typename T>
class NodeComparatorDefault;

template<typename T>
class ActionDefault;

template<class T, class IsLess = IsLessDefault<T>> class Tree;

template<typename T1, class NodeComparator = NodeComparatorDefault<T1>>
class Node {
    Node<T1, NodeComparator>* parent;
    Node<T1, NodeComparator>* left_child;
    Node<T1, NodeComparator>* right_child;
    Node<T1, NodeComparator>* next;
    Node<T1, NodeComparator>* prev;
    NodeComparator comp;

    int height;
    size_t size;
    T1 value;

    // Helpfull classes
    struct AvlTreeIterator {
        using value_type = T1;
        using difference_type = ptrdiff_t;
        using pointer = T1*;
        using reference = T1&;
        using iterator_category = std::bidirectional_iterator_tag;

        Node<T1, NodeComparator> *m_current;
        Node<T1, NodeComparator> *m_prev;

        explicit AvlTreeIterator(Node<T1, NodeComparator> *ptr = nullptr, Node<T1, NodeComparator> *prev = nullptr);
        AvlTreeIterator(const AvlTreeIterator &);

        AvlTreeIterator &operator=(const AvlTreeIterator &);

        AvlTreeIterator &operator++();
        AvlTreeIterator operator++(int);
        AvlTreeIterator &operator--();
        AvlTreeIterator operator--(int);

        reference operator*() const;
        pointer operator->() const;

        bool operator==(AvlTreeIterator other) const;
        bool operator!=(AvlTreeIterator other) const;

        template<typename T, class IsLess> friend class Tree;
        template<class> friend class IsLessDefault;
        template<class> friend class ActionDefault;
    };

public:
    Node() : parent(nullptr), left_child(nullptr), right_child(nullptr), next(nullptr), prev(nullptr), height(1), size(1) {}
    Node(T1 _value) : parent(nullptr), left_child(nullptr), right_child(nullptr), next(nullptr), prev(nullptr), height(1), size(1), value(_value) {}
    friend std::ostream &operator<< (std::ostream &os, const Node &curNode) {
        return os << curNode.value;
    }
    Node(const Node& rs): value(rs.value) {}

    T1 getValue() const {return value;}

    bool operator<(const Node& rs) const {return comp(this->value, rs.value);}
    bool operator==(const Node& rs) const {return !comp(this->value, rs.value) && !comp(rs.value, this->value);}
    bool operator>(const Node& rs) const {return !comp(this->value, rs.value);}

    template<typename T, class IsLess> friend class Tree;
    template<class> friend class IsLessDefault;
    template<class> friend class ActionDefault;
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
    Node<T>* findMin(Node<T>* targetBranch) const;
    Node<T>* findMax(Node<T>* targetBranch) const;

    // links
    void insertLinks(Node<T>* new_node);

    // copy function
    void copyTree(Node<T>* copyObj, Node<T>* target);

public:
    using iterator = typename Node<T>::AvlTreeIterator;   
    using reverse_iterator = std::reverse_iterator<typename Node<T>::AvlTreeIterator>;

    Tree(const IsLess& is_less = IsLessDefault<T>());
   template<std::random_access_iterator Iterator>
   Tree(Iterator begin, Iterator end);
    Tree(const std::initializer_list<T> &list);
    Tree(const Tree *other);
    Tree& operator=(const Tree &other);
    ~Tree();
    void destroyTree(Node<T>* curNode);

    iterator begin() const;
    iterator end() const;

    iterator rbegin() const;
    iterator rend() const;

    void insert(const T& elem);
    void erase(const T& elem);
    bool Has(const T &data) const;

    Node<T>* Root() const {return root;}
    bool empty() const {if (!root || (root && root->size == 0)) {return true;} return false;}
    size_t size() {if (empty()) {return 0;} return root->size;}

    // search functions
    iterator find(const T& elem) const; // +
    Node<T>* FindNode(const T& elem) const; // +
    Node<T>* findLowerBound(const T& data) const; // +
    iterator lower_bound(const T& data) const; // +
    Node<T>* getRoot() {return root;} // +
    T getRootData() const {return root->value;} // +

    template<class Action = ActionDefault<T>>
    void postOrderTree(Node<T>* begin, const Action& act);
    void bfs();
};

#include "baseIterator.hpp"
#include "srcCompare.hpp"
#include "srcIterator.hpp"
#include "srcConstructor.hpp"
#include "srcBalance.hpp"
#include "srcAccess.hpp"
#include "srcLinks.hpp"
#include "srcModify.hpp"
#include "srcTraverse.hpp"
