#include <iostream>
#include <stdlib.h>
#include "Array.tpp"


#define MAX_VAL 750
int	main(void)
{
	int* a = new int();
	std::cout << *a << std::endl;
	delete a;

	// initialize array of 5 integers
	Array<int> a1(5);
	a1[0] = 2;
	a1[1] = 4242;
	a1[2] = 42;
	a1[3] = 24;
	a1[4] = 4;

	// initialize array of 3 strings
	Array<std::string> a2(3);
	a2[0] = "Hello";
	a2[1] = "Friend";
	a2[2] = "Good Bye";

	// try to access out of bound
	try {
		a2[3] = "WRONG...";
	}catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
		a2[-1] = "WRONG...";
	}catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	// print size of arrays
	std::cout << "size a1: " << a1.size() << ". size a2: " << a2.size() << std::endl;

	// print content of arrays
	std::cout << a1[0] << ", " << a1[1] << ", " << a1[2] << ", " << a1[3] << ", " << a1[4] << std::endl;
	try {
		std::cout << a1[5] << std::endl;
	}catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << a2[0] << ", " << a2[1] << ", " << a2[2] << std::endl;
	try {
		std::cout << a2[3] << std::endl;
	}catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	// test copy constructor
	Array<int> a3(a1);
	std::cout << "size a3: " << a3.size() << std::endl;
	// modify a1
	a1[0] = 42;
	std::cout << "a1[0] = " << a1[0] << std::endl;
	std::cout << "a3[0] = " << a3[0] << std::endl;

	// test assigment operator =
	a3 = a1;
	std::cout << "size a3: " << a3.size() << std::endl;
	// modify a1
	a1[0] = 4242;
	std::cout << "a1[0] = " << a1[0] << std::endl;
	std::cout << "a3[0] = " << a3[0] << std::endl;

	// print new line
	std::cout << std::endl;

	{
	    Array<int> numbers(MAX_VAL);
	    int* mirror = new int[MAX_VAL];
	    srand(time(NULL));
	    for (int i = 0; i < MAX_VAL; i++)
	    {
	        const int value = rand();
	        numbers[i] = value;
	        mirror[i] = value;
	    }
	    //SCOPE
	    {
	        Array<int> tmp = numbers;
	        Array<int> test(tmp);
	    }

	    for (int i = 0; i < MAX_VAL; i++)
	    {
	        if (mirror[i] != numbers[i])
	        {
	            std::cerr << "didn't save the same value!!" << std::endl;
	            delete [] mirror;
	            return 1;
	        }
	    }

	    try
	    {
	        numbers[-2] = 0;
	    }
	    catch(const std::exception& e)
	    {
	        std::cerr << e.what() << '\n';
	    }

	    try
	    {
	        numbers[MAX_VAL] = 0;
	    }
	    catch(const std::exception& e)
	    {
	        std::cerr << e.what() << '\n';
	    }

	    for (int i = 0; i < MAX_VAL; i++)
	    {
	        numbers[i] = rand();
	    }
	    delete [] mirror;
	}
	return (0);
}
