#pragma once  // pragma once

#include <iterator>

template<class T> class AvlTree;
template<class T> class Node;


template<class Iterator>
class AvlTreeIterator {
    template<class> friend class AvlTree;
    template<class> friend class Node;
public:
    typedef Iterator iterator_type;
    typedef std::bidirectional_iterator_tag bidirectional_iterator;
    typedef iterator_type value_type;
    typedef ptrdiff_t difference_type;
    typedef iterator_type &reference;
    typedef iterator_type *pointer;

    iterator_type* m_pointer;
    AvlTreeIterator(const AvlTreeIterator &curIterator) : m_pointer(curIterator.m_pointer) {}

    bool operator==(AvlTreeIterator const &other) const { return m_pointer == other.m_pointer; }
    bool operator!=(AvlTreeIterator const &other) const { return m_pointer != other.m_pointer; }

    typename AvlTreeIterator::reference operator*() const { return *m_pointer; }
    AvlTreeIterator &operator++() {
        auto prev = this;
        if (m_pointer) { m_pointer = m_pointer->next();}
        return *prev;
    }
private:
    AvlTreeIterator(Iterator* pointer) : m_pointer(pointer) {}
};
