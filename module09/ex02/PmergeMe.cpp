#include "PmergeMe.hpp"

// Constructors
PmergeMe::PmergeMe()
{
	std::cout << "\e[0;33mDefault Constructor called of PmergeMe\e[0m" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of PmergeMe\e[0m" << std::endl;
}


// Destructor
PmergeMe::~PmergeMe()
{
	std::cout << "\e[0;31mDestructor called of PmergeMe\e[0m" << std::endl;
}


// Operators
PmergeMe & PmergeMe::operator=(const PmergeMe &assign)
{
	(void) assign;
	return *this;
}

// Methods
void PmergeMe::sort(int ac, char *av[])
{
	// init sequence int array
	char * pEnd;
	errno = 0;
	long int sequence[ac];
	for (int i = 0; i < ac - 1; i++) {
		sequence[i] = strtol(av[i + 1], &pEnd, 10);
		if (sequence[i] < 0 || sequence[i] > INT_MAX || errno != 0 || pEnd[0] != '\0') {
			std::cout << "Error." << std::endl;
			return;
		}
	}
	std::list<int> lst(sequence, sequence + ac - 1);
	std::vector<int> vec(sequence, sequence + ac - 1);

	std::cout << "Before: ";
	printList(lst);

	// init the time structs
	struct timeval start, end;

	gettimeofday(&start, NULL);	// start the timer
	std::list<int> sortedLst = mergeInsertSort(lst);
	gettimeofday(&end, NULL);	// stops the timer
	double listTime = ((end.tv_sec - start.tv_sec) * 1e6) + (end.tv_usec - start.tv_usec) * 1e-6;

	gettimeofday(&start, NULL);
	std::vector<int> sortedVec = mergeInsertSort(vec);
	gettimeofday(&end, NULL);
	double vectorTime = ((end.tv_sec - start.tv_sec) * 1e6) + (end.tv_usec - start.tv_usec) * 1e-6;

	std::cout << "After: ";
	printList(sortedLst);

    std::cout << "Time to process a range of " << lst.size() <<  " elements with std::list : " << std::fixed << listTime << " us" << std::endl;
    std::cout << "Time to process a range of " << lst.size() <<  " elements with std::vector : " << std::fixed << vectorTime << " us" << std::endl;
}


void PmergeMe::printList(std::list<int> & lst)
{
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}

std::list<int> PmergeMe::mergeInsertSort(std::list<int> & lst)
{
	// sorting algorithm
	// https://github.com/decidedlyso/merge-insertion-sort/blob/master/README.md
	// https://codereview.stackexchange.com/questions/116367/ford-johnson-merge-insertion-sort
	// https://github.com/Morwenn/cpp-sort/blob/1.x.y-stable/include/cpp-sort/detail/merge_insertion_sort.h
	return lst;
}
std::vector<int> PmergeMe::mergeInsertSort(std::vector<int> & vec)
{
	// sorting algorithm

	return vec;
}