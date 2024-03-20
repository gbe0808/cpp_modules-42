#pragma once

#include <exception>

template <typename T>
class Array {
private:
    T* _array;
    unsigned int _size;

public:
    Array() {
        _size = 0;
        _array = new T[0];
    };
    Array(const unsigned int n) {
        _size = n;
        _array = new T[n];
    };

    Array(const Array &ref) {
        _size = ref._size;
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = ref._array[i];
    };

    Array &operator=(const Array &ref) {
        delete[] this;
        _size = ref.size();
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = ref[i];
        return *this;
    };

    ~Array() {
        delete[] _array;
    };

    T &operator[](const unsigned int idx) {
        if (idx >= _size)
            throw std::exception();
        return _array[idx];
    };

    const T &operator[](const unsigned int idx) const {
        if (idx >= _size)
            throw std::exception();
        return _array[idx];
    };

    unsigned int size() const {
        return _size;
    };
};