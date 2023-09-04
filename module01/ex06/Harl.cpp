#include "Harl.hpp"

Harl::Harl() {
	return;
}

Harl::~Harl(void) {
	return;
}

void Harl::debug( void ) {
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!\n" << std::endl;
}

void Harl::info( void ) {
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning( void ) {
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error( void ) {
	std::cout << "[ ERROR ]\nThis is unacceptable, I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain( std::string level ) {

	void (Harl::*d)(void);
	void (Harl::*i)(void);
	void (Harl::*w)(void);
	void (Harl::*e)(void);

	std::map<std::string, void (Harl::*)(void)> mapping;
	mapping["DEBUG"] = d = &Harl::debug;
	mapping["INFO"] = i = &Harl::info;
	mapping["WARNING"] = w = &Harl::warning;
	mapping["ERROR"] = e = &Harl::error;

	if (mapping.find(level) == mapping.end()) {
		std::cout << "[ Probably complaining about insignificant problems ]\n" << std::endl;
		return;
    }
	(this->*mapping[level])();
}
