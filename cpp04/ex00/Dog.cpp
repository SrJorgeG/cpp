#include "Dog.hpp"

Dog::Dog() : _type("Dog")
{
}

Dog::Dog(const std::string& type) : _type(type)
{
}

Dog::Dog(const Dog& other) : _type(other._type)
{
}

Dog& Dog::operator=(const Dog &other)
{
	if (this != &other)
		_type = other._type;
	return *this;
}

Dog::~Dog()
{
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

std::string Dog::getType() const
{
	return _type;
}

void Dog::setType(const std::string& type)
{
	_type = type;
}