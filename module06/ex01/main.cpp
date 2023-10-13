#include "Serializer.hpp"

class Serializer;

int	main(void)
{
    Data data;
    data.s1 = "Hello";
    data.n = 42;
    data.s2 = "World";

// Here's a breakdown of what the function does:

// reinterpret_cast<uintptr_t>(ptr):

// It uses the reinterpret_cast operator to convert the pointer ptr to a uintptr_t. This conversion does not modify the underlying data; it just changes the type of the pointer.
// uintptr_t is an unsigned integer type that can represent the memory address of the object pointed to by ptr.
// return (reinterpret_cast<uintptr_t>(ptr)):

// The function returns the uintptr_t value obtained from the pointer ptr.
// In essence, the serialize function effectively converts the pointer to a uintptr_t integer, which can be useful for saving and transmitting the memory address of the Data object or for other purposes like serialization and deserialization. However, it's important to note that this function does not actually serialize the content of the Data object itself; it only provides a way to represent the memory location of the object in the form of an integer.

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialization: " << raw << std::endl;

    Data *data2 = Serializer::deserialize(raw);

    std::cout << "Deserialization: ";
    std::cout << data2->s1 << " ";
    std::cout << data2->n << " ";
    std::cout << data2->s2 << std::endl;

    return (0);
}