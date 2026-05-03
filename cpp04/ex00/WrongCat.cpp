#include "WrongCat.hpp"

WrongCat::WrongCat() : _type("WrongCat")
{
}

WrongCat::WrongCat(const std::string& type) : _type(type)
{
}

WrongCat::WrongCat(const WrongCat& other) : _type(other._type)
{
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		_type = other._type;
	return *this;
}

WrongCat::~WrongCat()
{
}

void WrongCat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}

std::string WrongCat::getType() const
{
	return _type;
}

void WrongCat::setType(const std::string& type)
{
	_type = type;
}
