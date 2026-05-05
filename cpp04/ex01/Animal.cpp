#include "Animal.hpp"

Animal::Animal() : _type("Default")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal parameterised constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type)
{
	std::cout << "Animal copy constructor called" << std::endl;	
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &other)
{
	if (this != &other)
		_type = other._type;
	std::cout << "Animal copy assignment operator called" << std::endl;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "Animal sound!" << std::endl;
}

std::string Animal::getType() const
{
	return _type;
}

void Animal::setType(const std::string& type)
{
	_type = type;
}
