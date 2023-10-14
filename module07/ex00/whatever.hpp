#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>


template <typename T>
void swap(T & x, T & y) {
    T tmp = x;
    x = y;
    y = tmp;
}
// to use a class on this. the <= and >= operators need to be overloaded.
template <typename T>
T const & min(T const & x, T const & y) {
    return (y <= x ? y : x);
}
template <typename T>
T const & max(T const & x, T const & y) {
    return (y >= x ? y : x);
}

#endif