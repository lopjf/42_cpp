#ifndef EASYFIND_H
# define EASYFIND_H

#include <algorithm>

template<typename T>
int easyfind(T & t,int i) {
    if (std::find(t.begin(), t.end(), i) != t.end()) {
        std::cout << "The first occurence of " << i << " was found." << std::endl;
        return 0;
    }
    std::cout << "There is no occurence of " << i << "." << std::endl;
    return 1;
}

#endif