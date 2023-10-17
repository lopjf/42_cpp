#include <iostream>
#include <algorithm>
#include <list>

void displayInt(int i)
{
	std::cout << i << std::endl;
}

int main()
{
	std::list<int> lst;

	lst.push_back(10);
	lst.push_back(23);
	lst.push_back(42);
	lst.push_back(3);
	lst.push_back(17);
	lst.push_back(20);

	// applies a function to each element between 2 iterators
	for_each(lst.begin(), lst.end(), displayInt);
}