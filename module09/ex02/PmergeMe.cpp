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
	std::deque<int> dque(sequence, sequence + ac - 1);
	std::vector<int> vec(sequence, sequence + ac - 1);

	std::cout << "Before: ";
	printDeque(dque);

	// init the time structs
	struct timeval start, end;

	gettimeofday(&start, NULL);	// start the timer
	std::deque<int> sortedLst = mergeInsertSort(dque);
	gettimeofday(&end, NULL);	// stops the timer
	double dequeTime = ((end.tv_sec - start.tv_sec) * 1e6) + (end.tv_usec - start.tv_usec) * 1e-6;

	gettimeofday(&start, NULL);
	std::vector<int> sortedVec = mergeInsertSort(vec);
	gettimeofday(&end, NULL);
	double vectorTime = ((end.tv_sec - start.tv_sec) * 1e6) + (end.tv_usec - start.tv_usec) * 1e-6;

	std::cout << "After: ";
	printDeque(sortedLst);

    std::cout << "Time to process a range of " << dque.size() <<  " elements with std::deque : " << std::fixed << dequeTime << " us" << std::endl;
    std::cout << "Time to process a range of " << dque.size() <<  " elements with std::vector : " << std::fixed << vectorTime << " us" << std::endl;
}


void PmergeMe::printDeque(std::deque<int> & dque)
{
	for (std::deque<int>::iterator it = dque.begin(); it != dque.end(); it++) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}

std::deque<int> PmergeMe::mergeInsertSort(std::deque<int> & dque)
{
	// sorting algorithm
	// https://github.com/decidedlyso/merge-insertion-sort/blob/master/README.md
	// https://codereview.stackexchange.com/questions/116367/ford-johnson-merge-insertion-sort
	// https://github.com/Morwenn/cpp-sort/blob/1.x.y-stable/include/cpp-sort/detail/merge_insertion_sort.h


	// 1st: Create an array of pairs
	int dque_size = dque.size();
	int arr_size = dque_size / 2;


	std::deque<int> pairs[arr_size];
	
	for (int i = 0; i < arr_size; ++i) {
		for (int j = 0; j < 2; ++j) {
			pairs[i].push_back(dque.front());
			dque.pop_front();
		}
		// sort the pairs
		std::sort(pairs[i].begin(), pairs[i].end());
	}

	// Store the last one into last if odd sequence
	std::deque<int> last;
	if (dque_size % 2 != 0) {
		last.push_back(dque.front());
		dque.pop_front();
	}

	// dispatch the sorted pairs into a and b. Put in a the smallest numbers, and b get the highest.
	
	std::deque<int> a;
	std::deque<int> b;

	for (int i = 0; i < arr_size; ++i) {
		a.push_back(pairs[i].front());
		pairs[i].pop_front();
		b.push_back(pairs[i].front());
		pairs[i].pop_front();
	}

	// sort a and b
	std::sort(a.begin(), a.end(), std::greater<int>());
	std::sort(b.begin(), b.end(), std::greater<int>());

	// add last to b if odd sequence
	if (dque_size % 2 != 0) {
		b.push_back(last.front());
		last.pop_front();
	}

	printDeque(a);
	printDeque(b);

	// place b into a. Use Jacobsthal Numbers to minimize comparison cost.
	// uint index = 1;
	while (b.size() > 0) {
		a.push_back(b.front());
		b.pop_front();
	}

	printDeque(a);
	printDeque(b);

	return dque;
}
std::vector<int> PmergeMe::mergeInsertSort(std::vector<int> & vec)
{
	// sorting algorithm

	return vec;
}