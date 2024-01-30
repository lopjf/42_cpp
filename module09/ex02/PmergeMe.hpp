#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cerrno>
# include <climits>
# include <deque>
# include <vector>
# include <sys/time.h>
# include <iomanip>
# include <algorithm>

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
		static void printDeque(std::deque<int> & dque);
		static std::deque<int> mergeInsertSort(std::deque<int> & dque);
		static std::vector<int> mergeInsertSort(std::vector<int> & vec);
};

#endif