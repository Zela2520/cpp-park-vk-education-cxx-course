#pragma once  // pragma once

template<typename T>
Node<T>::AvlTreeIterator::AvlTreeIterator(Node<T> *ptr, Node<T> *prev) : m_current{ptr}, m_prev{prev} {}


template<typename T>
Node<T>::AvlTreeIterator::AvlTreeIterator(const AvlTreeIterator &other) : m_current{other.m_current}, m_prev{other.m_prev} {}


template<class T>
typename Node<T>::AvlTreeIterator &Node<T>::AvlTreeIterator::operator=(const AvlTreeIterator &other) {
    if (*this != other) {
        m_current = other.m_current;
        m_prev = other.m_prev;
    }
    return *this;
}

template<class T>
typename Node<T>::AvlTreeIterator &Node<T>::AvlTreeIterator::operator++() {
    m_prev = m_current;
    m_current = m_current->next;
    return *this;
}

template<class T>
typename Node<T>::AvlTreeIterator Node<T>::AvlTreeIterator::operator++(int) {
    auto tmp = m_current;
    auto prev = m_prev;
    AvlTreeIterator it(tmp, prev);
    m_prev = m_current;
    m_current = m_current->next;
    return it;
}

template<class T>
typename Node<T>::AvlTreeIterator &Node<T>::AvlTreeIterator::operator--() {
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

template<class T>
typename Node<T>::AvlTreeIterator Node<T>::AvlTreeIterator::operator--(int) {
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

template<class T>
typename Node<T>::AvlTreeIterator::reference Node<T>::AvlTreeIterator::operator*() const {
    return m_current->value;
}

template<class T>
typename Node<T>::AvlTreeIterator::pointer Node<T>::AvlTreeIterator::operator->() const {
    return &m_current->value;
}

template<class T>
bool Node<T>::AvlTreeIterator::operator==(AvlTreeIterator other) const {
    return other.m_current == m_current;
}

template<class T>
bool Node<T>::AvlTreeIterator::operator!=(AvlTreeIterator other) const {
    return other.m_current != m_current;
}
