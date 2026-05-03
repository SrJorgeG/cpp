#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Default")
{

}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{

}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type)
{
}

WrongAnimal::~WrongAnimal()
{
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		_type = other._type;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound!" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return _type;
}

void WrongAnimal::setType(const std::string& type)
{
	_type = type;
}

