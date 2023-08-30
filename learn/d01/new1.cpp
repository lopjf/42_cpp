#include <iostream>
#include <string>

class Student {
	private:
		std::string _login;

	public:
		Student(std::string login) : _login(login) {
			std::cout << "student" << this->_login << " is born" << std::endl;
		}
		~Student() {
			std::cout << "student" << this->_login << " died" << std::endl;
		}
};

int main() {
	Student		bob = Student("bfubar");		// allouer sur la pile, sur la stack
	Student*	jim = new Student("jbufar");	// allocation dynamique (on voit que c'est un pointer) allouer sur la heap

	//Do some stuff here

	delete jim;	// jim is destroyed

	return (0); // bob is destroyed
}