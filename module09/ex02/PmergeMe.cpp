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
	printContainer(dque);

	// init the time structs
	struct timeval start, end;

	gettimeofday(&start, NULL);	// start the timer
	std::deque<int> sortedDque = mergeInsertSort(dque);
	gettimeofday(&end, NULL);	// stops the timer
	double dequeTime = ((end.tv_sec - start.tv_sec) * 1e6) + (end.tv_usec - start.tv_usec) * 1e-6;

	gettimeofday(&start, NULL);
	std::vector<int> sortedVec = mergeInsertSort(vec);
	gettimeofday(&end, NULL);
	double vectorTime = ((end.tv_sec - start.tv_sec) * 1e6) + (end.tv_usec - start.tv_usec) * 1e-6;

	std::cout << "After: ";
	printContainer(sortedDque);

    std::cout << "Time to process a range of " << dque.size() <<  " elements with std::deque : " << std::fixed << dequeTime << " us" << std::endl;
    std::cout << "Time to process a range of " << dque.size() <<  " elements with std::vector : " << std::fixed << vectorTime << " us" << std::endl;
}

template <typename T>
void printContainer(T & cont)
{
	for (typename T::iterator it = cont.begin(); it != cont.end(); it++) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}

uint PmergeMe::getJacobsthalNumber(uint index)
{
	if (index == 0)
		return 0;
	if (index == 1)
		return 1;

	uint prev = 0;
	uint current = 1;

    for (uint i = 2; i <= index; i++) {
        uint tmp = current;
        current += 2 * prev;
        prev = tmp;
    }

	return current;
}

bool PmergeMe::isJacobsthalNumber(uint num) {
    uint i = 0;
    while (true) {
        uint jacobs = getJacobsthalNumber(i);
        if (jacobs == num) return true;
        if (jacobs > num) return false;
        i++;
    }
}

uint PmergeMe::getCorrectIndex(uint index)
{
	uint jacobs = 2;
	std::queue<uint> tmp;
	tmp.push(1);

	while (tmp.size() <= index) {
		uint toAdd = getJacobsthalNumber(jacobs + 1) - getJacobsthalNumber(jacobs) - 1;
		// insert until next jacob number
		for (uint i = 0; i <= toAdd; i++) {
			if (tmp.size() > index)
				break;
			tmp.push(getJacobsthalNumber(jacobs + 1) - i);
		}
		jacobs++;
	}
	return tmp.back() - 1;
}

// sorting algorithms
// https://github.com/decidedlyso/merge-insertion-sort/blob/master/README.md
// https://codereview.stackexchange.com/questions/116367/ford-johnson-merge-insertion-sort
// https://github.com/Morwenn/cpp-sort/blob/1.x.y-stable/include/cpp-sort/detail/merge_insertion_sort.h

std::deque<int> PmergeMe::mergeInsertSort(std::deque<int> & dque)
{
	// 1st: Create an array of pairs
	int dque_size = dque.size();
	int arr_size = dque_size / 2;
	std::deque<int> pairs[arr_size];
	
	for (int i = 0; i < arr_size; ++i) {
		for (int j = 0; j < 2; ++j) {
			pairs[i].push_back(dque.front());
			dque.pop_front();
		}
		std::sort(pairs[i].begin(), pairs[i].end());
	}

	// Store the last one into the var last if odd sequence
	std::deque<int> last;
	if (dque_size % 2 != 0) {
		last.push_back(dque.front());
		dque.pop_front();
	}

	// dispatch the sorted pairs into a and b. Put in a the smallest numbers, and b the highest.
	std::deque<int> a;
	std::deque<int> b;

	for (int i = 0; i < arr_size; ++i) {
		a.push_back(pairs[i].front());
		pairs[i].pop_front();
		b.push_back(pairs[i].front());
		pairs[i].pop_front();
	}
	std::sort(a.begin(), a.end(), std::greater<int>());
	std::sort(b.begin(), b.end(), std::greater<int>());

	// add last to b if odd sequence
	if (dque_size % 2 != 0) {
		b.push_back(last.front());
		last.pop_front();
	}

	// place b into a. Use Jacobsthal Numbers to minimize comparison cost.
	uint i = 0;
	uint b_size = b.size();
	for (std::deque<int>::iterator it = b.begin(); it != b.end(); ++it) {
		while (getCorrectIndex(i) >= b_size) {
			i++;
		}
		uint j = 0;
		while (b[getCorrectIndex(i)] <= a[j]) {
			j++;
		}
		a.insert(a.begin() + j, b[getCorrectIndex(i)]);
		i++;
	}

	reverse(a.begin(), a.end());
	return a;
}
std::vector<int> PmergeMe::mergeInsertSort(std::vector<int> & vec)
{
	// 1st: Create an array of pairs
	int vec_size = vec.size();
	int arr_size = vec_size / 2;
	std::vector<int> pairs[arr_size];
	
	for (int i = 0; i < arr_size; ++i) {
		for (int j = 0; j < 2; ++j) {
			pairs[i].push_back(vec.front());
			vec.erase(vec.begin());

		}
		std::sort(pairs[i].begin(), pairs[i].end());
	}

	// Store the last one into the var last if odd sequence
	std::vector<int> last;
	if (vec_size % 2 != 0) {
		last.push_back(vec.front());
		vec.erase(vec.begin());
	}

	// dispatch the sorted pairs into a and b. Put in a the smallest numbers, and b the highest.
	std::vector<int> a;
	std::vector<int> b;

	for (int i = 0; i < arr_size; ++i) {
		a.push_back(pairs[i].front());
		pairs[i].erase(pairs[i].begin());
		b.push_back(pairs[i].front());
		pairs[i].erase(pairs[i].begin());
	}
	std::sort(a.begin(), a.end(), std::greater<int>());
	std::sort(b.begin(), b.end(), std::greater<int>());

	// add last to b if odd sequence
	if (vec_size % 2 != 0) {
		b.push_back(last.front());
		last.erase(last.begin());
	}

	// place b into a. Use Jacobsthal Numbers to minimize comparison cost.
	uint i = 0;
	uint b_size = b.size();
	for (std::vector<int>::iterator it = b.begin(); it != b.end(); ++it) {
		while (getCorrectIndex(i) >= b_size) {
			i++;
		}
		uint j = 0;
		while (b[getCorrectIndex(i)] <= a[j]) {
			j++;
		}
		a.insert(a.begin() + j, b[getCorrectIndex(i)]);
		i++;
	}

	reverse(a.begin(), a.end());
	return a;
}