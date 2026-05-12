#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

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
	int passed = 0;
	int failed = 0;

	// ==================== TEST 1: Valid construction ====================
	print_header("TEST 1: Valid construction");
	try
	{
		Bureaucrat b1("Alice", 1);
		if (b1.getName() == "Alice" && b1.getGrade() == 1)
		{
			print_success("Bureaucrat with grade 1 created correctly");
			passed++;
		}
		else
		{
			print_fail("Bureaucrat attributes mismatch");
			failed++;
		}
	}
	catch (std::exception& e)
	{
		print_fail(std::string("Unexpected exception: ") + e.what());
		failed++;
	}

	try
	{
		Bureaucrat b2("Bob", 150);
		if (b2.getName() == "Bob" && b2.getGrade() == 150)
		{
			print_success("Bureaucrat with grade 150 created correctly");
			passed++;
		}
		else
		{
			print_fail("Bureaucrat attributes mismatch");
			failed++;
		}
	}
	catch (std::exception& e)
	{
		print_fail(std::string("Unexpected exception: ") + e.what());
		failed++;
	}

	try
	{
		Bureaucrat b3("Charlie", 75);
		if (b3.getGrade() == 75)
		{
			print_success("Bureaucrat with grade 75 created correctly");
			passed++;
		}
		else
		{
			print_fail("Grade mismatch");
			failed++;
		}
	}
	catch (std::exception& e)
	{
		print_fail(std::string("Unexpected exception: ") + e.what());
		failed++;
	}

	// ==================== TEST 2: Invalid construction (too high) ====================
	print_header("TEST 2: Invalid construction - grade too high");
	try
	{
		Bureaucrat b("High", 0);
		print_fail("No exception thrown for grade 0");
		failed++;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		print_success(std::string("Caught GradeTooHighException for grade 0: ") + e.what());
		passed++;
	}
	catch (std::exception& e)
	{
		print_fail(std::string("Wrong exception type: ") + e.what());
		failed++;
	}

	try
	{
		Bureaucrat b("High2", -42);
		print_fail("No exception thrown for grade -42");
		failed++;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		print_success(std::string("Caught GradeTooHighException for negative grade: ") + e.what());
		passed++;
	}
	catch (std::exception& e)
	{
		print_fail(std::string("Wrong exception type: ") + e.what());
		failed++;
	}

	// ==================== TEST 3: Invalid construction (too low) ====================
	print_header("TEST 3: Invalid construction - grade too low");
	try
	{
		Bureaucrat b("Low", 151);
		print_fail("No exception thrown for grade 151");
		failed++;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		print_success(std::string("Caught GradeTooLowException for grade 151: ") + e.what());
		passed++;
	}
	catch (std::exception& e)
	{
		print_fail(std::string("Wrong exception type: ") + e.what());
		failed++;
	}

	try
	{
		Bureaucrat b("Low2", 999);
		print_fail("No exception thrown for grade 999");
		failed++;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		print_success(std::string("Caught GradeTooLowException for very high grade: ") + e.what());
		passed++;
	}
	catch (std::exception& e)
	{
		print_fail(std::string("Wrong exception type: ") + e.what());
		failed++;
	}

	// ==================== TEST 4: Increment grade ====================
	print_header("TEST 4: Increment grade (higher rank = lower number)");
	try
	{
		Bureaucrat b("Incr", 3);
		b.incrementGrade();
		if (b.getGrade() == 2)
		{
			print_success("Grade incremented from 3 to 2");
			passed++;
		}
		else
		{
			print_fail("Grade did not increment correctly");
			failed++;
		}

		b.incrementGrade();
		if (b.getGrade() == 1)
		{
			print_success("Grade incremented from 2 to 1");
			passed++;
		}
		else
		{
			print_fail("Grade did not increment correctly");
			failed++;
		}
	}
	catch (std::exception& e)
	{
		print_fail(std::string("Unexpected exception: ") + e.what());
		failed++;
	}

	// ==================== TEST 5: Increment too high ====================
	print_header("TEST 5: Increment grade beyond limit");
	try
	{
		Bureaucrat b("IncrLimit", 1);
		b.incrementGrade();
		print_fail("No exception thrown when incrementing grade 1");
		failed++;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		print_success(std::string("Caught GradeTooHighException on increment: ") + e.what());
		passed++;
	}
	catch (std::exception& e)
	{
		print_fail(std::string("Wrong exception type: ") + e.what());
		failed++;
	}

	// ==================== TEST 6: Decrement grade ====================
	print_header("TEST 6: Decrement grade (lower rank = higher number)");
	try
	{
		Bureaucrat b("Decr", 148);
		b.decrementGrade();
		if (b.getGrade() == 149)
		{
			print_success("Grade decremented from 148 to 149");
			passed++;
		}
		else
		{
			print_fail("Grade did not decrement correctly");
			failed++;
		}

		b.decrementGrade();
		if (b.getGrade() == 150)
		{
			print_success("Grade decremented from 149 to 150");
			passed++;
		}
		else
		{
			print_fail("Grade did not decrement correctly");
			failed++;
		}
	}
	catch (std::exception& e)
	{
		print_fail(std::string("Unexpected exception: ") + e.what());
		failed++;
	}

	// ==================== TEST 7: Decrement too low ====================
	print_header("TEST 7: Decrement grade beyond limit");
	try
	{
		Bureaucrat b("DecrLimit", 150);
		b.decrementGrade();
		print_fail("No exception thrown when decrementing grade 150");
		failed++;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		print_success(std::string("Caught GradeTooLowException on decrement: ") + e.what());
		passed++;
	}
	catch (std::exception& e)
	{
		print_fail(std::string("Wrong exception type: ") + e.what());
		failed++;
	}

	// ==================== TEST 8: Insertion operator ====================
	print_header("TEST 8: Insertion operator <<");
	try
	{
		Bureaucrat b("Diana", 42);
		std::cout << "Output: " << b << std::endl;
		print_success("Insertion operator works (verify output manually)");
		passed++;
	}
	catch (std::exception& e)
	{
		print_fail(std::string("Unexpected exception: ") + e.what());
		failed++;
	}

	// ==================== TEST 9: Copy constructor ====================
	print_header("TEST 9: Copy constructor");
	try
	{
		Bureaucrat b1("Original", 10);
		Bureaucrat b2(b1);
		if (b2.getName() == "Original" && b2.getGrade() == 10)
		{
			print_success("Copy constructor copies attributes correctly");
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

	// ==================== TEST 10: Copy assignment ====================
	print_header("TEST 10: Copy assignment operator");
	try
	{
		Bureaucrat b1("Source", 20);
		Bureaucrat b2("Target", 100);
		b2 = b1;
		if (b2.getGrade() == 20)
		{
			print_success("Copy assignment operator copies grade correctly");
			passed++;
		}
		else
		{
			print_fail("Copy assignment did not copy grade correctly");
			failed++;
		}
		// Name is const, cannot change, but assignment should still work for grade
	}
	catch (std::exception& e)
	{
		print_fail(std::string("Unexpected exception: ") + e.what());
		failed++;
	}

	// ==================== TEST 11: Default constructor ====================
	print_header("TEST 11: Default constructor");
	try
	{
		Bureaucrat b;
		if (b.getName() == "Default" && b.getGrade() == 150)
		{
			print_success("Default constructor creates Bureaucrat with correct defaults");
			passed++;
		}
		else
		{
			print_fail("Default constructor defaults are wrong");
			failed++;
		}
	}
	catch (std::exception& e)
	{
		print_fail(std::string("Unexpected exception: ") + e.what());
		failed++;
	}

	// ==================== TEST 12: setGrade valid and invalid ====================
	print_header("TEST 12: setGrade");
	try
	{
		Bureaucrat b("Setter", 50);
		b.setGrade(25);
		if (b.getGrade() == 25)
		{
			print_success("setGrade works with valid grade");
			passed++;
		}
		else
		{
			print_fail("setGrade did not set grade correctly");
			failed++;
		}
	}
	catch (std::exception& e)
	{
		print_fail(std::string("Unexpected exception on valid setGrade: ") + e.what());
		failed++;
	}

	try
	{
		Bureaucrat b("Setter2", 50);
		b.setGrade(0);
		print_fail("No exception thrown for setGrade(0)");
		failed++;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		print_success("Caught GradeTooHighException on setGrade(0)");
		passed++;
	}
	catch (std::exception& e)
	{
		print_fail(std::string("Wrong exception type: ") + e.what());
		failed++;
	}

	try
	{
		Bureaucrat b("Setter3", 50);
		b.setGrade(151);
		print_fail("No exception thrown for setGrade(151)");
		failed++;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		print_success("Caught GradeTooLowException on setGrade(151)");
		passed++;
	}
	catch (std::exception& e)
	{
		print_fail(std::string("Wrong exception type: ") + e.what());
		failed++;
	}

	// ==================== TEST 13: Boundary increment/decrement ====================
	print_header("TEST 13: Boundary increment/decrement");
	try
	{
		Bureaucrat b("Boundary", 2);
		b.incrementGrade();
		if (b.getGrade() == 1)
		{
			print_success("Increment from 2 to 1 works");
			passed++;
		}
		else
		{
			print_fail("Increment boundary failed");
			failed++;
		}
	}
	catch (std::exception& e)
	{
		print_fail(std::string("Unexpected exception: ") + e.what());
		failed++;
	}

	try
	{
		Bureaucrat b("Boundary2", 149);
		b.decrementGrade();
		if (b.getGrade() == 150)
		{
			print_success("Decrement from 149 to 150 works");
			passed++;
		}
		else
		{
			print_fail("Decrement boundary failed");
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
