#pragma once

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack();
    MutantStack(const MutantStack &ref);
    MutantStack &operator=(const MutantStack &ref);
    ~MutantStack();

    typedef typename std::deque<T>::iterator iterator;

    iterator begin();
    iterator end();
};

#include "MutantStack.tpp"
