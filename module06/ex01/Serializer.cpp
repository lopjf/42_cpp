#include "Serializer.hpp"

// Constructors
Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &copy)
{
	(void) copy;
}


// Destructor
Serializer::~Serializer()
{
}


// In C++, reinterpret_cast is a type of casting operator that allows you to convert a pointer or reference of one data type into a pointer or reference of another data type. It is the most powerful and dangerous of all the C++ casting operators because it can convert any pointer type to any other pointer type, and it can even reinterpret the binary representation of the data, which can lead to undefined behavior if not used carefully.

// Methods
uintptr_t Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}

// Operators
Serializer & Serializer::operator=(const Serializer &assign)
{
	(void) assign;
	return *this;
}

