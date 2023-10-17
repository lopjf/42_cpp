#include <iostream>
#include <map>
#include <vector>
#include <list>

int main()
{
	std::list<int> lst1;
	std::vector<int> v1;
	// creates a vector of 42 elements, all equal to 100
	std::vector<int> v2(42, 100);

	// map is an hashtable (dictionary) but we don't have to use string as values
	std::map<std::string, int> map1;

	lst1.push_back(1);
	lst1.push_back(17);
	lst1.push_back(42);

	map1["num1"] = 1;
	map1["num2"] = 2;

	// iterators are the stl's container equivalent of pointer
	std::list<int>::const_iterator it;
	// lst1.end() is not the last element, it's a pointer to the element after the last
	std::list<int>::const_iterator ite = lst1.end();

	// loop through each element until the end of the list
	// iterator can be incremented like a pointer
	for (it = lst1.begin(); it != ite; ++it)
	{
		// iterators can be dereferenced like pointers
		std::cout << *it << std::endl;
	}

	std::cout << map1["num1"]<< std::endl;
}