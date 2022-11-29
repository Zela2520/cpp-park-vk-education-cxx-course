#pragma once  // pragma once

template<class T, class NodeComparator>
Node<T, NodeComparator>::AvlTreeIterator::AvlTreeIterator(Node<T, NodeComparator> *ptr, Node<T, NodeComparator> *prev) : m_current{ptr}, m_prev{prev} {}


template<class T, class NodeComparator>
Node<T, NodeComparator>::AvlTreeIterator::AvlTreeIterator(const AvlTreeIterator &other) : m_current{other.m_current}, m_prev{other.m_prev} {}


template<class T, class NodeComparator>
typename Node<T, NodeComparator>::AvlTreeIterator &Node<T, NodeComparator>::AvlTreeIterator::operator=(const AvlTreeIterator &other) {
    if (*this != other) {
        m_current = other.m_current;
        m_prev = other.m_prev;
    }
    return *this;
}

template<class T, class NodeComparator>
typename Node<T, NodeComparator>::AvlTreeIterator &Node<T, NodeComparator>::AvlTreeIterator::operator++() {
    m_prev = m_current;
    m_current = m_current->next;
    return *this;
}

template<class T, class NodeComparator>
typename Node<T, NodeComparator>::AvlTreeIterator Node<T, NodeComparator>::AvlTreeIterator::operator++(int) {
    auto tmp = m_current;
    auto prev = m_prev;
    AvlTreeIterator it(tmp, prev);
    m_prev = m_current;
    m_current = m_current->next;
    return it;
}

template<class T, class NodeComparator>
typename Node<T, NodeComparator>::AvlTreeIterator &Node<T, NodeComparator>::AvlTreeIterator::operator--() {
    if (!m_current) {
        m_current = m_prev;
        m_prev = m_prev->prev;
    } else {
        m_current = m_current->prev;
        if (m_current && m_current->prev) {
            m_prev = m_current->prev;
        }
    }
    return *this;
}

template<class T, class NodeComparator>
typename Node<T, NodeComparator>::AvlTreeIterator Node<T, NodeComparator>::AvlTreeIterator::operator--(int) {
    auto tmp = m_current;
    auto prev = m_prev;
    AvlTreeIterator it(tmp, prev);
    if (!m_current) {
        m_current = m_prev;
        m_prev = m_prev->prev;
    } else {
        m_current = m_current->prev;
        if (m_current && m_current->prev) {
            m_prev = m_current->prev;
        }
    }
    return it;
}

template<class T, class NodeComparator>
typename Node<T, NodeComparator>::AvlTreeIterator::reference Node<T, NodeComparator>::AvlTreeIterator::operator*() const {
    return m_current->value;
}

template<class T, class NodeComparator>
typename Node<T, NodeComparator>::AvlTreeIterator::pointer Node<T, NodeComparator>::AvlTreeIterator::operator->() const {
    return &m_current->value;
}

template<class T, class NodeComparator>
bool Node<T, NodeComparator>::AvlTreeIterator::operator==(AvlTreeIterator other) const {
    return other.m_current == m_current;
}

template<class T, class NodeComparator>
bool Node<T, NodeComparator>::AvlTreeIterator::operator!=(AvlTreeIterator other) const {
    return other.m_current != m_current;
}
