#include <iostream>
#include <string>

// une reference c'est un peu comme un pointer constant. La reference va toujours pointer sur la meme chose
// une reference ne peut pas pointer sur rien. Elle est obligatoirement initialise
// C'est comme si la reference est un pointer deja dereferencer. Il fait deja reference a lui meme
// en gros c'est: Non null, constant, dereference
// Si ca doit toujours exister et ne jamais changer --> reference
// Si ca doit changer et/ou ne plus exister --> pointer

class Student {
	private:
		std::string _login;

	public:
		Student(std::string const & login) : _login(login) {
		}

		std::string&	getLoginRef() {
			return this->_login;
		}

		std::string const & getLoginRefConst() const {
			return this->_login;
		}

		std::string*	getLoginPtr() {
			return &(this->_login);
		}

		std::string const * getLoginPtrConst() const {
			return &(this->_login);
		}
};

int main() {
	Student			bob = Student("bfubar");
	Student const	jim = Student("jbufar");

	std::cout << bob.getLoginRefConst() << " " << jim.getLoginRefConst() << std::endl;
	std::cout << *(bob.getLoginPtrConst()) << " " << *(jim.getLoginPtrConst()) << std::endl;

	bob.getLoginRef() = "bobfubar";
	std::cout << bob.getLoginRefConst() << std::endl;

	*(bob.getLoginPtr()) = "bobbyfubar";
	std::cout << bob.getLoginRefConst() << std::endl;

	return 0;
};