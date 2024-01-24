#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cerrno>
# include <climits>
# include <list>
# include <vector>
# include <sys/time.h>
# include <iomanip>

class PmergeMe
{
	public:
		// Constructors
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		
		// Destructor
		~PmergeMe();
		
		// Operators
		PmergeMe & operator=(const PmergeMe &assign);

		// Methods
		static void sort(int ac, char *av[]);
		
	private:
		static void printList(std::list<int> & lst);
		static std::list<int> mergeInsertSort(std::list<int> & lst);
		static std::vector<int> mergeInsertSort(std::vector<int> & vec);
};

#endif