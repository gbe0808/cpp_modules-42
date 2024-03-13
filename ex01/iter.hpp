#pragma once

template <typename T>
void iter(T *array, const unsigned int length, void (*f)(T &))
{
    for (unsigned int i = 0; i < length; i++)
        f(array[i]);
}

// template <typename T>
// void iter(const T *array, const unsigned int length, void (*f)(const T &))
// {
//     for (unsigned int i = 0; i < length; i++)
//         f(array[i]);
// }
