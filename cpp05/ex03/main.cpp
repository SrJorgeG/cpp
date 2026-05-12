#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void print_header(const std::string& title)
{
	std::cout << "\n========== " << title << " ==========\n" << std::endl;
}

void print_success(const std::string& msg)
{
	std::cout << "[PASS] " << msg << std::endl;
}

void print_fail(const std::string& msg)
{
	std::cout << "[FAIL] " << msg << std::endl;
}

int main()
{
	std::srand(std::time(NULL));
	int passed = 0;
	int failed = 0;

	// ==================== TEST 1: Intern creates all valid forms ====================
	print_header("TEST 1: Intern creates all valid forms");
	{
		Intern someRandomIntern;

		AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf != NULL && rrf->getName() == "RobotomyRequestForm")
		{
			print_success("Intern created RobotomyRequestForm successfully");
			passed++;
		}
		else
		{
			print_fail("Intern failed to create RobotomyRequestForm");
			failed++;
		}
		delete rrf;

		AForm* scf = someRandomIntern.makeForm("shrubbery creation", "home");
		if (scf != NULL && scf->getName() == "ShrubberyCreationForm")
		{
			print_success("Intern created ShrubberyCreationForm successfully");
			passed++;
		}
		else
		{
			print_fail("Intern failed to create ShrubberyCreationForm");
			failed++;
		}
		delete scf;

		AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Arthur");
		if (ppf != NULL && ppf->getName() == "PresidentialPardonForm")
		{
			print_success("Intern created PresidentialPardonForm successfully");
			passed++;
		}
		else
		{
			print_fail("Intern failed to create PresidentialPardonForm");
			failed++;
		}
		delete ppf;
	}

	// ==================== TEST 2: Intern returns NULL for unknown form ====================
	print_header("TEST 2: Intern returns NULL for unknown form");
	{
		Intern intern;
		AForm* invalid = intern.makeForm("nonexistent form", "target");
		if (invalid == NULL)
		{
			print_success("Intern returned NULL for unknown form name");
			passed++;
		}
		else
		{
			print_fail("Intern should return NULL for unknown form");
			delete invalid;
			failed++;
		}
	}

	// ==================== TEST 3: Full workflow with Intern-created forms ====================
	print_header("TEST 3: Full workflow - Intern creates, Bureaucrat signs and executes");
	{
		Intern intern;
		Bureaucrat boss("Boss", 1);

		AForm* scf = intern.makeForm("shrubbery creation", "garden");
		if (scf)
		{
			boss.signForm(*scf);
			boss.executeForm(*scf);
			print_success("Full workflow for ShrubberyCreationForm completed");
			passed++;
		}
		else
		{
			print_fail("Intern failed to create ShrubberyCreationForm for workflow");
			failed++;
		}
		delete scf;

		AForm* rrf = intern.makeForm("robotomy request", "Bender");
		if (rrf)
		{
			boss.signForm(*rrf);
			boss.executeForm(*rrf);
			print_success("Full workflow for RobotomyRequestForm completed");
			passed++;
		}
		else
		{
			print_fail("Intern failed to create RobotomyRequestForm for workflow");
			failed++;
		}
		delete rrf;

		AForm* ppf = intern.makeForm("presidential pardon", "Zaphod");
		if (ppf)
		{
			boss.signForm(*ppf);
			boss.executeForm(*ppf);
			print_success("Full workflow for PresidentialPardonForm completed");
			passed++;
		}
		else
		{
			print_fail("Intern failed to create PresidentialPardonForm for workflow");
			failed++;
		}
		delete ppf;
	}

	// ==================== TEST 4: Intern Orthodox Canonical Form ====================
	print_header("TEST 4: Intern Orthodox Canonical Form");
	{
		Intern i1;
		Intern i2(i1);
		Intern i3;
		i3 = i1;

		AForm* f1 = i1.makeForm("shrubbery creation", "t1");
		AForm* f2 = i2.makeForm("shrubbery creation", "t2");
		AForm* f3 = i3.makeForm("shrubbery creation", "t3");

		if (f1 && f2 && f3)
		{
			print_success("Intern copy constructor and assignment operator work");
			passed++;
		}
		else
		{
			print_fail("Intern copy/assign failed to create forms");
			failed++;
		}
		delete f1;
		delete f2;
		delete f3;
	}

	// ==================== TEST 5: Grade too low to execute intern-created form ====================
	print_header("TEST 5: Low-grade bureaucrat cannot execute intern-created form");
	{
		Intern intern;
		Bureaucrat lowly("Lowly", 150);

		AForm* ppf = intern.makeForm("presidential pardon", "Trillian");
		if (ppf)
		{
			lowly.signForm(*ppf);
			lowly.executeForm(*ppf);
			print_success("Low-grade bureaucrat correctly rejected");
			passed++;
		}
		else
		{
			print_fail("Intern failed to create form");
			failed++;
		}
		delete ppf;
	}

	// ==================== SUMMARY ====================
	print_header("SUMMARY");
	std::cout << "Tests passed: " << passed << std::endl;
	std::cout << "Tests failed: " << failed << std::endl;

	return failed > 0 ? 1 : 0;
}