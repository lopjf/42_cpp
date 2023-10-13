# include <iostream>
# include <string>
# include <cstdlib> 
# include <ctime>

class Base
{
    public:
        virtual ~Base() {};
};
class A : public Base {};
class B : public Base {};
class C : public Base {};

int getRamdom(int min, int max) {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    // Generate a random number between 1 and 2
    int randomValue = (std::rand() % max) + min;

    return randomValue;
}

Base * generate(void) {
    // This function upcast. It's done implicitly.
    Base * ret;

    int ran = getRamdom(1, 3);
    if (ran == 1)
        ret = new A;
    else if (ran == 2)
        ret = new B;
    else
        ret =  new C;
    return ret;
}

void identify(Base* p) {
    A *a = dynamic_cast<A *>(p);
    B *b = dynamic_cast<B *>(p);
    C *c = dynamic_cast<C *>(p);
    if (a != NULL) {
        std::cout << "p points to the A object type." << std::endl;
    } else if (b != NULL) {
        std::cout << "p points to the B object type." << std::endl;
    } else if (c != NULL) {
        std::cout << "p points to the C object type." << std::endl;
    }
}

void identify(Base& p) {
    // Since references can't be NULL, it'll run a bad_cast exception if it fails
    // catch (...) catch any exceptions.
    try {
        dynamic_cast<A &>(p);
        std::cout << "p points to the A object type." << std::endl;
    } catch (...) {}
    try {
        dynamic_cast<B &>(p);
        std::cout << "p points to the B object type." << std::endl;
    } catch (...) {}
    try {
        dynamic_cast<C &>(p);
        std::cout << "p points to the C object type." << std::endl;
    } catch (...) {}
}


int	main(void)
{
    Base *base = generate();

    std::cout << "Explict downcast (with pointer)" << std::endl;
    identify(base);

    std::cout << "Explict downcast (with reference)" << std::endl;
    identify(*base);

    delete base;
    return (0);
}