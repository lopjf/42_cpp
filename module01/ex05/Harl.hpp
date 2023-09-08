#include <iostream>

#ifndef HARL_H
# define HARL_H

class Harl {
	private:

		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

	public:

		Harl();
		~Harl(void);

		void complain( std::string level );
};

typedef	void (Harl::*t_func)(void);

#endif