#pragma once

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class AForm
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;

protected:
	virtual void action() const = 0;

public:
	AForm();
	AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();

	const std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	bool beSigned(const Bureaucrat &bureaucrat);
	void execute(Bureaucrat const &executor) const;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Grade is too high.";
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Grade is too low.";
			}
	};

	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Form is not signed.";
			}
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &form);