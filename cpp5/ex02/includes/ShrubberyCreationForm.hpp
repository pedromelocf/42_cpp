#ifndef SHRUBBERYCREATIONFORM
#define SHRUBBERYCREATIONFORM

#include <iostream>
#include <string>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& s);
		ShrubberyCreationForm& operator= (const ShrubberyCreationForm& s);
		~ShrubberyCreationForm();

		const std::string& getTarget() const;
		void setTarget(const std::string& target);
		void execute(Bureaucrat const & executor) const;
};

#endif