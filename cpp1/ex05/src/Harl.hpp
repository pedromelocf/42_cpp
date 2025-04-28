#ifndef HARL_HPP
# define HARL_HPP

#include "iostream"

class Harl {

	public :
		Harl ();
		~Harl ();
		void	complain ( const std::string& level );
		void	(Harl::*ptrToMemberFunc)();

	private:
		void	debug();
		void	info ();
		void	warning ();
		void	error ();
		void	invalid ();

};

struct levels {

	std::string	s_level;
	void		( Harl::*ptrToMemberFunc )();

};

#endif 