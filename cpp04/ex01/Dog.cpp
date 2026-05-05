#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	_brain = new Brain();
	std::cout << "Dog parameterised constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	_brain = new Brain(*other._brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		if (_brain)
			delete _brain;
		_brain = new Brain(*other._brain);
	}
	std::cout << "Dog copy assignment operator called" << std::endl;
	return *this;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

const std::string	Dog::getBrainIdea(int index) const
{
	return _brain->getIdea(index);
}

void	Dog::setBrainIdea(const std::string idea, int index)
{
	_brain->setIdea(index, idea);
}
