#pragma once // pragma once

template<typename T>
class IsLessDefault {
public:
    bool operator() (const Node<T>& l, const Node<T>& r) const {return l.value < r.value;}
};