#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExec;

	protected:
		void checkRequirementsToExecute(Bureaucrat const & executor) const; 
	
	public:
		AForm();
		AForm(const std::string& name, int gradeToSign, int _gradeToExec);
		AForm(const AForm& f);
		AForm& operator= (const AForm& f); 
		virtual ~AForm();

		const std::string& getName() const;
		bool boolCheckSign() const;
		int reqGradeToSign() const;
		int reqGradeToExec() const;
		void setSigned(bool isSigned);
		void beSigned(Bureaucrat& b);
		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				const char *what() const throw();
		};
};  

std::ostream& operator<< ( std::ostream& os, const AForm& f);

#endif