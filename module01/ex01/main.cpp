#include "Zombie.hpp"

int main() {

	int N = 42;

	Zombie	*zombies = zombieHorde(N, "glenn");

    for (int i = 0; i < N; i++) {
        zombies[i].announce();
    }

	delete [] zombies;

	return 0;
}