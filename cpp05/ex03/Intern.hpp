#pragma once

#include <string>
#include "AForm.hpp"

class Intern
{
private:
	typedef AForm* (*FormCreator)(const std::string& target);

	struct FormType
	{
		std::string	name;
		FormCreator	creator;
	};

	static FormType	formTypes[];
	static const int	numFormTypes;

	static AForm*	createShrubberyCreationForm(const std::string& target);
	static AForm*	createRobotomyRequestForm(const std::string& target);
	static AForm*	createPresidentialPardonForm(const std::string& target);

public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();

	AForm*	makeForm(const std::string& name, const std::string& target);
};