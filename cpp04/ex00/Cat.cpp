#include "Cat.hpp"

Cat::Cat() : _type("Cat")
{
}

Cat::Cat(const std::string& type) : _type(type)
{
}

Cat::Cat(const Cat& other) : _type(other._type)
{
}

Cat& Cat::operator=(const Cat &other)
{
	if (this != &other)
		_type = other._type;
	return *this;
}

Cat::~Cat()
{
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}

std::string Cat::getType() const
{
	return _type;
}

void Cat::setType(const std::string& type)
{
	_type = type;
}
