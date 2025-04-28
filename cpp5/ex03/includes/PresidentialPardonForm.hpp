#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

	private:
		std::string _target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& p);
		PresidentialPardonForm& operator= (const PresidentialPardonForm& p);
		~PresidentialPardonForm();

		const std::string& getTarget() const;
		void setTarget(const std::string& target);
		void execute(Bureaucrat const & executor) const;
};

#endif