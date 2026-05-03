#include "Animal.hpp"

Animal::Animal() : _type("Default")
{

}

Animal::Animal(std::string type) : _type(type)
{

}

Animal::Animal(const Animal &other) : _type(other._type)
{
}

Animal::~Animal()
{
}

Animal& Animal::operator=(const Animal &other)
{
	if (this != &other)
		_type = other._type;
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
