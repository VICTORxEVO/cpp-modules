#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

// For non-const arrays (can modify elements)
template <typename T>
void iter(T *array, size_t const length, void (*func)(T &))
{
    if (! array || ! func)
        return;
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}

// For const arrays (read-only)
template <typename T>
void iter(T const *array, size_t const length, void (*func)(T const &))
{
    if (!array || !func)
        return;
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}

#endif