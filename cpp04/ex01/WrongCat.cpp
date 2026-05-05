#include "WrongCat.hpp"

WrongCat::WrongCat() : Animal("WrongCat")
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type) : Animal(type)
{
	std::cout << "WrongCat parameterised constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : Animal(other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		Animal::operator=(other);
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
