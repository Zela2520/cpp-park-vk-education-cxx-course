#pragma once // pragma once


// с помощью этого компаратора можно перегрузить все операторы сравнения внутри Tree
template<typename T>
class IsLessDefault {
public:
    bool operator() (const Node<T>& l, const Node<T>& r) const {return l.value < r.value;}
};

// с помощью этого компаратора можно перегрузить все операторы сравнения внутри Node-ы
template<typename T>
class NodeComparatorDefault {
public:
    bool operator() (const T& l, const T& r) const {return l < r;}
};
