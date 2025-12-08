#ifndef ARRAY_TPP
# define ARRAY_TPP

// Default constructor - empty array
template <typename T>
Array<T>::Array(void) : _array(NULL), _size(0)
{
}

// Parametric constructor - array of n elements initialized by default
template <typename T>
Array<T>::Array(unsigned int n) : _array(NULL), _size(n)
{
    if (n > 0)
        _array = new T[n]();
}

// Copy constructor - deep copy
template <typename T>
Array<T>::Array(Array const &src) : _array(NULL), _size(0)
{
    *this = src;
}

// Destructor
template <typename T>
Array<T>::~Array(void)
{
    if (_array)
        delete[] _array;
}

// Assignment operator - deep copy
template <typename T>
Array<T> &Array<T>::operator=(Array const &rhs)
{
    if (this != &rhs)
    {
        if (_array)
            delete[] _array;
        _size = rhs._size;
        if (_size > 0)
        {
            _array = new T[_size]();
            for (unsigned int i = 0; i < _size; i++)
                _array[i] = rhs._array[i];
        }
        else
            _array = NULL;
    }
    return *this;
}

// Subscript operator (non-const) - allows modification
template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw OutOfBoundsException();
    return _array[index];
}

// Subscript operator (const) - read only
template <typename T>
T const &Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw OutOfBoundsException();
    return _array[index];
}

// Size getter
template <typename T>
unsigned int Array<T>::size(void) const
{
    return _size;
}

#endif