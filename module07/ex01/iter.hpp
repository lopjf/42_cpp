#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T, typename Func>
void iter(T *addr, int len, Func f) {
    if (len <= 0)
        return ;
    for (int i = 0; i < len; i++) {
        f(addr[i]);
    }
}

#endif