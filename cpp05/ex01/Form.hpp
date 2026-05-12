#pragma once

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;
public:
	Form();
	Form(const std::string name, const int gradeToSign, const int gradeToExecute);
	Form(const Form &other);
	Form &operator=(const Form &other);	

	const std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	bool beSigned(const class Bureaucrat &bureaucrat);
	void setIsSigned(bool isSigned);

	class GradeTooHighException : public std::exception
	{
	public:		virtual const char* what() const throw()
		{
			return "Grade is too high.";
		}	
	};		

	class GradeTooLowException : public std::exception
	{	public:		virtual const char* what() const throw()
		{
			return "Grade is too low.";
		}	
	};	
	~Form();
};

std::ostream &operator<<(std::ostream &out, const Form &form);