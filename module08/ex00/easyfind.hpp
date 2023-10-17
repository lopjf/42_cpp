#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>


template <typename T>
void easyfind(T & t, int i) {
    typename T::iterator find = std::find(t.begin(), t.end(), i) ;
    if (find != t.end()) {
        int index = std::distance(t.begin(), find);
        std::cout << "The first occurence of " << i << " was found at index " << index << "." << std::endl;
        return ;
    }
    std::cout << "There is no occurence of " << i << "." << std::endl;
}


// I keep this because it says don't use iterators for finding it. BUT I choosed to be more specific in my easyfind by provind the index. I need to know how to remove it so I don't use iterator just in case someone asks during the evaluation.
// template <typename T>
// void easyfind(T & t, int i) {
//     if (std::find(t.begin(), t.end(), i) != t.end()) {
//         std::cout << "The first occurence of " << i << " was found." << std::endl;
//         return ;
//     }
//     std::cout << "There is no occurence of " << i << "." << std::endl;
// }

#endif