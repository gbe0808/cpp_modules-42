#pragma once

template <typename T>
void iter(T *array, const unsigned int length, void (*f)(T &))
{
    for (unsigned int i = 0; i < length; i++)
        f(array[i]);
}
