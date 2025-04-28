#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExec;

	public:
		Form();
		Form(const std::string& name, int gradeToSign, int _gradeToExec);
		Form(const Form& f);
		Form& operator= (const Form& f);
		~Form();

		const std::string& getName() const;
		bool boolCheckSign() const;
		int reqGradeToSign() const;
		int reqGradeToExec() const;
		void beSigned(Bureaucrat& b);
};

std::ostream& operator<< ( std::ostream& os, const Form& f);

#endif