#include <iostream>

// une reference c'est un peu comme un pointer constant. La reference va toujours pointer sur la meme chose
// une reference ne peut pas pointer sur rien. Elle est obligatoirement initialise
// C'est comme si la reference est un pointer deja dereferencer. Il fait deja reference a lui meme
// en gros c'est: Non null, constant, dereference
// Si ca doit toujours exister et ne jamais changer --> reference
// Si ca doit changer et/ou ne plus exister --> pointer

int main() {
	int		numberOfBalls = 42;

	int*	ballsPtr = &numberOfBalls;
	int&	ballsRef = numberOfBalls;

	std::cout << numberOfBalls << " " << *ballsPtr << " " << ballsRef << std::endl;

	*ballsPtr = 21;
	std::cout << numberOfBalls << std::endl;
	ballsRef = 84;
	std::cout << numberOfBalls << std::endl;

	return 0;
};