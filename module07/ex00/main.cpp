#include "whatever.hpp"

int	main(void)
{
    std::cout << "int:" << std::endl;
    int a = 5, b = 10;
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    swap(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    std::cout << "min_result = " << min<int>(a, b) << std::endl;
    std::cout << "max_result = " << max<int>(a, b) << std::endl;


    std::cout << std::endl << "-----------------" << std::endl << std::endl;


    std::cout << "flaot:" << std::endl;
    float c = 42.42f, d = 32.99f;
    std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;
    swap(c, d);
    std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;

    std::cout << "min_result = " << min<float>(c, d) << std::endl;
    std::cout << "max_result = " << max<float>(c, d) << std::endl;


    std::cout << std::endl << "-----------------" << std::endl << std::endl;


    std::cout << "char:" << std::endl;
    char e = 'a', f = 'z';
    std::cout << "Before swap: e = " << e << ", f = " << f << std::endl;
    swap(e, f);
    std::cout << "Before swap: e = " << e << ", f = " << f << std::endl;

    std::cout << "min_result = " << min<char>(e, f) << std::endl;
    std::cout << "max_result = " << max<char>(e, f) << std::endl;

    return 0;
}