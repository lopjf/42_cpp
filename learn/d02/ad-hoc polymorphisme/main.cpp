#include "Sample.class.hpp"

// g++ -Wall -Wextra -Wno-unused -Werror Sample.class.cpp main.cpp

int main() {
    Sample instance;

	instance.bar('a');
	instance.bar(42);
	instance.bar(3.14f);
	instance.bar(instance);

    return 0;
}