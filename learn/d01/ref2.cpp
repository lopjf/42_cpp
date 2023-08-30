#include <iostream>
#include <string>

// une reference c'est un peu comme un pointer constant. La reference va toujours pointer sur la meme chose
// une reference ne peut pas pointer sur rien. Elle est obligatoirement initialise
// C'est comme si la reference est un pointer deja dereferencer. Il fait deja reference a lui meme
// en gros c'est: Non null, constant, dereference
// Si ca doit toujours exister et ne jamais changer --> reference
// Si ca doit changer et/ou ne plus exister --> pointer

void byPtr(std::string* str) {
	*str += " and ponies";
}

void byConstPtr(std::string const * str) {
	std::cout << *str << std::endl;
}

void byRef(std::string& str) {
	str += " and ponies";
}

void byConstRef(std::string const & str) {
	std::cout << str << std::endl;
}

int main() {
	std::string str = "i like butterflies";

	std::cout << str << std::endl;
	byPtr(&str);
	byConstPtr(&str);

	str = "i like otters";

	std::cout << str << std::endl;
	byRef(str);
	byConstRef(str);

	return 0;
};