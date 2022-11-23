#pragma once  // pragma once

#include <iterator>

template<typename T>
class IsLessDefault;

template<typename T>
class ActionDefault;

template<class T, class IsLess = IsLessDefault<T>> class Tree;
template<class T1> class Node;


template<class Iterator>
class AvlTreeIterator {
    template<class, class> friend class Tree;
    template<class> friend class Node;
public:
    typedef Iterator iterator_type;
    typedef std::bidirectional_iterator_tag bidirectional_iterator;
    typedef iterator_type value_type;
    typedef ptrdiff_t difference_type;
    typedef iterator_type &reference;
    typedef iterator_type *pointer;

    iterator_type* m_pointer;
private:
    AvlTreeIterator(Iterator* pointer) : m_pointer(pointer) {}
public:
    AvlTreeIterator(const AvlTreeIterator &curIterator) : m_pointer(curIterator.m_pointer) {}

    bool operator==(AvlTreeIterator const &other) const { return m_pointer == other.m_pointer; }
    bool operator!=(AvlTreeIterator const &other) const { return m_pointer != other.m_pointer; }

    typename AvlTreeIterator::reference operator*() const { return *m_pointer; }
    AvlTreeIterator &operator++() {
        auto tmp = this;
        if (m_pointer) { m_pointer = m_pointer->next;}
        return *tmp;
    }
    AvlTreeIterator &operator--() {
        auto tmp = this;
        if (m_pointer) { m_pointer = m_pointer->prev;}
        return *tmp;
    }
};
