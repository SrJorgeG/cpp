#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::FormType Intern::formTypes[] =
{
	{"shrubbery creation", &Intern::createShrubberyCreationForm},
	{"robotomy request", &Intern::createRobotomyRequestForm},
	{"presidential pardon", &Intern::createPresidentialPardonForm}
};

const int Intern::numFormTypes = 3;

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{
}

AForm* Intern::createShrubberyCreationForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	for (int i = 0; i < numFormTypes; i++)
	{
		if (formTypes[i].name == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return formTypes[i].creator(target);
		}
	}
	std::cout << "Intern could not find form \"" << name << "\"" << std::endl;
	return NULL;
}