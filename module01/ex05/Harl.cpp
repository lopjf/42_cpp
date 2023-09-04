#include "Harl.hpp"

Harl::Harl() {
	return;
}

Harl::~Harl(void) {
	return;
}

void Harl::debug( void ) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;

}

void Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;

}

void Harl::error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;

}

void Harl::complain( std::string level ) {

	void (Harl::*d)(void);
	void (Harl::*i)(void);
	void (Harl::*w)(void);
	void (Harl::*e)(void);

	std::map<std::string, void (Harl::*)(void)> mapping;
	mapping["debug"] = d = &Harl::debug;
	mapping["info"] = i = &Harl::info;
	mapping["warning"] = w = &Harl::warning;
	mapping["error"] = e = &Harl::error;

	if (mapping.find(level) == mapping.end()) {
		std::cout << "Invalid level: " << level << std::endl;
		return;
    }
	(this->*mapping[level])();
}
