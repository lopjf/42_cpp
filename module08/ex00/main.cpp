#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include "easyfind.hpp"

int main(void)
{
	// Test with std::list
	std::list<int> lst1;

	lst1.push_back(1);
	lst1.push_back(17);
	lst1.push_back(42);
	lst1.push_back(1);

	easyfind(lst1, 1);
	easyfind(lst1, 42);
	easyfind(lst1, 18);


	// Test with std::vector
    std::vector<int> vec1;
    vec1.push_back(2);
    vec1.push_back(5);
    vec1.push_back(8);
    vec1.push_back(2);

    easyfind(vec1, 5);
    easyfind(vec1, 8);
    easyfind(vec1, 9);

    // Test with std::deque
    std::deque<int> deq1;
    deq1.push_back(1);
    deq1.push_back(2);
    deq1.push_back(3);
    deq1.push_back(4);
    deq1.push_back(5);
    easyfind(deq1, 4);
    easyfind(deq1, 6);


    return 0;
}
