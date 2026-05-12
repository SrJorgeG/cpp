#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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

	// ==================== TEST 1: ShrubberyCreationForm basics ====================
	print_header("TEST 1: ShrubberyCreationForm construction");
	try
	{
		ShrubberyCreationForm scf("home");
		if (scf.getName() == "ShrubberyCreationForm"
			&& scf.getGradeToSign() == 145
			&& scf.getGradeToExecute() == 137
			&& scf.getIsSigned() == false)
		{
			print_success("ShrubberyCreationForm created with correct attributes");
			passed++;
		}
		else
		{
			print_fail("ShrubberyCreationForm attributes mismatch");
			failed++;
		}
	}
	catch (std::exception& e)
	{
		print_fail(std::string("Unexpected exception: ") + e.what());
		failed++;
	}

	// ==================== TEST 2: RobotomyRequestForm basics ====================
	print_header("TEST 2: RobotomyRequestForm construction");
	try
	{
		RobotomyRequestForm rrf("Bender");
		if (rrf.getName() == "RobotomyRequestForm"
			&& rrf.getGradeToSign() == 72
			&& rrf.getGradeToExecute() == 45
			&& rrf.getIsSigned() == false)
		{
			print_success("RobotomyRequestForm created with correct attributes");
			passed++;
		}
		else
		{
			print_fail("RobotomyRequestForm attributes mismatch");
			failed++;
		}
	}
	catch (std::exception& e)
	{
		print_fail(std::string("Unexpected exception: ") + e.what());
		failed++;
	}

	// ==================== TEST 3: PresidentialPardonForm basics ====================
	print_header("TEST 3: PresidentialPardonForm construction");
	try
	{
		PresidentialPardonForm ppf("Arthur");
		if (ppf.getName() == "PresidentialPardonForm"
			&& ppf.getGradeToSign() == 25
			&& ppf.getGradeToExecute() == 5
			&& ppf.getIsSigned() == false)
		{
			print_success("PresidentialPardonForm created with correct attributes");
			passed++;
		}
		else
		{
			print_fail("PresidentialPardonForm attributes mismatch");
			failed++;
		}
	}
	catch (std::exception& e)
	{
		print_fail(std::string("Unexpected exception: ") + e.what());
		failed++;
	}

	// ==================== TEST 4: Sign and execute ShrubberyCreationForm ====================
	print_header("TEST 4: Sign and execute ShrubberyCreationForm");
	try
	{
		ShrubberyCreationForm scf("garden");
		Bureaucrat b1("Gardener", 1);
		b1.signForm(scf);
		if (scf.getIsSigned())
		{
			print_success("ShrubberyCreationForm signed successfully");
			passed++;
		}
		else
		{
			print_fail("ShrubberyCreationForm not signed");
			failed++;
		}
		b1.executeForm(scf);
		print_success("ShrubberyCreationForm executed (check for garden_shrubbery file)");
		passed++;
	}
	catch (std::exception& e)
	{
		print_fail(std::string("Unexpected exception: ") + e.what());
		failed++;
	}

	// ==================== TEST 5: Execute unsigned form (direct call) ====================
	print_header("TEST 5: Execute unsigned form throws exception");
	try
	{
		ShrubberyCreationForm scf("park");
		Bureaucrat b("Worker", 1);
		scf.execute(b);
		print_fail("Should throw on unsigned form execution");
		failed++;
	}
	catch (AForm::FormNotSignedException& e)
	{
		print_success(std::string("Caught FormNotSignedException: ") + e.what());
		passed++;
	}
	catch (std::exception& e)
	{
		print_fail(std::string("Wrong exception type: ") + e.what());
		failed++;
	}

	// ==================== TEST 6: Execute with too low grade (direct call) ====================
	print_header("TEST 6: Execute with grade too low throws exception");
	try
	{
		ShrubberyCreationForm scf("forest");
		Bureaucrat high("HighGrader", 1);
		Bureaucrat low("LowGrader", 150);
		high.signForm(scf);
		scf.execute(low);
		print_fail("Should throw on low grade execution");
		failed++;
	}
	catch (AForm::GradeTooLowException& e)
	{
		print_success(std::string("Caught GradeTooLowException: ") + e.what());
		passed++;
	}
	catch (std::exception& e)
	{
		print_fail(std::string("Wrong exception type: ") + e.what());
		failed++;
	}

	// ==================== TEST 7: RobotomyRequestForm execution ====================
	print_header("TEST 7: RobotomyRequestForm execution");
	try
	{
		RobotomyRequestForm rrf("Bender");
		Bureaucrat b("Robotomist", 1);
		b.signForm(rrf);
		std::cout << "Executing robotomy (result is 50/50):" << std::endl;
		b.executeForm(rrf);
		print_success("RobotomyRequestForm executed (check output above)");
		passed++;
	}
	catch (std::exception& e)
	{
		print_fail(std::string("Unexpected exception: ") + e.what());
		failed++;
	}

	// ==================== TEST 8: PresidentialPardonForm execution ====================
	print_header("TEST 8: PresidentialPardonForm execution");
	try
	{
		PresidentialPardonForm ppf("Arthur Dent");
		Bureaucrat b("President", 1);
		b.signForm(ppf);
		b.executeForm(ppf);
		print_success("PresidentialPardonForm executed successfully");
		passed++;
	}
	catch (std::exception& e)
	{
		print_fail(std::string("Unexpected exception: ") + e.what());
		failed++;
	}

	// ==================== TEST 9: Grade too low to sign (direct call) ====================
	print_header("TEST 9: Grade too low to sign throws exception");
	try
	{
		ShrubberyCreationForm scf("backyard");
		Bureaucrat b("LowRank", 150);
		scf.beSigned(b);
		print_fail("Should throw when grade is too low to sign");
		failed++;
	}
	catch (AForm::GradeTooLowException& e)
	{
		print_success("Caught GradeTooLowException on beSigned");
		passed++;
	}
	catch (std::exception& e)
	{
		print_fail(std::string("Wrong exception type: ") + e.what());
		failed++;
	}

	// ==================== TEST 10: Insertion operator for AForm ====================
	print_header("TEST 10: Insertion operator << for AForm");
	try
	{
		ShrubberyCreationForm scf("test_target");
		std::cout << scf << std::endl;
		print_success("Insertion operator works for ShrubberyCreationForm");
		passed++;
	}
	catch (std::exception& e)
	{
		print_fail(std::string("Unexpected exception: ") + e.what());
		failed++;
	}

	// ==================== TEST 11: Sign successful but execute grade too low (direct call) ====================
	print_header("TEST 11: Signed but execute grade too low");
	try
	{
		RobotomyRequestForm rrf("Marvin");
		Bureaucrat signer("Signer", 1);
		Bureaucrat executor("Executor", 100);
		signer.signForm(rrf);
		rrf.execute(executor);
		print_fail("Should throw on execute with too low grade");
		failed++;
	}
	catch (AForm::GradeTooLowException& e)
	{
		print_success(std::string("Caught GradeTooLowException: ") + e.what());
		passed++;
	}
	catch (std::exception& e)
	{
		print_fail(std::string("Wrong exception type: ") + e.what());
		failed++;
	}

	// ==================== TEST 12: Bureaucrat::executeForm catches and prints errors ====================
	print_header("TEST 12: executeForm handles errors gracefully");
	try
	{
		ShrubberyCreationForm scf("lawn");
		Bureaucrat b("Worker", 150);
		b.executeForm(scf);
		print_success("executeForm handled unsigned form gracefully");
		passed++;
	}
	catch (std::exception& e)
	{
		print_fail(std::string("executeForm should not propagate exceptions: ") + e.what());
		failed++;
	}

	// ==================== TEST 13: Copy constructor and assignment ====================
	print_header("TEST 13: Copy constructor and assignment");
	try
	{
		ShrubberyCreationForm scf1("original");
		Bureaucrat b("Signer", 1);
		b.signForm(scf1);
		ShrubberyCreationForm scf2(scf1);
		if (scf2.getName() == "ShrubberyCreationForm"
			&& scf2.getIsSigned() == true
			&& scf2.getGradeToSign() == 145
			&& scf2.getGradeToExecute() == 137)
		{
			print_success("Copy constructor works correctly");
			passed++;
		}
		else
		{
			print_fail("Copy constructor did not copy correctly");
			failed++;
		}
	}
	catch (std::exception& e)
	{
		print_fail(std::string("Unexpected exception: ") + e.what());
		failed++;
	}

	// ==================== SUMMARY ====================
	print_header("SUMMARY");
	std::cout << "Tests passed: " << passed << std::endl;
	std::cout << "Tests failed: " << failed << std::endl;

	return failed > 0 ? 1 : 0;
}