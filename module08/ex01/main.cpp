#include <iostream>
#include "Span.hpp"
#include <ctime>
#include <limits>

int getRamdom() {

    // // Generate a random number between int min and int max
    int randomValue = (std::rand() % std::numeric_limits<int>::max()) + std::numeric_limits<int>::min();

    return randomValue;
}

int main(void)
{
    std::cout << "test 1:" << std::endl;
    {
        Span sp = Span(5);
        int ints[] = {6, 3, 17};
		std::vector<int> nums (ints, ints+3); 
        sp.addNumbers(nums);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    std::cout << std::endl << "test 2:" << std::endl;
    {
        Span sp = Span(1);

        try {
            sp.shortestSpan();
        } catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
        try {
            sp.longestSpan();
        } catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
        sp.addNumber(6);
        try {
            sp.shortestSpan();
        } catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
        try {
            sp.longestSpan();
        } catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
        try {
            sp.addNumber(42);
        } catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl << "test 3:" << std::endl;
    {
		Span sp(10000);
        
		std::vector<int> nums (10000);

        // Seed the random number generator with the current time Once
        std::srand(static_cast<unsigned int>(std::time(NULL)));
        std::generate (nums.begin(), nums.end(), getRamdom);
        sp.addNumbers(nums);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    return 0;
}
