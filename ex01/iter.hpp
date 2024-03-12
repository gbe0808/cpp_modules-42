#pragma once

#include <utility>

template <typename T>
void iter(T *array, size_t length, void (*f)(T &))
{
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}
