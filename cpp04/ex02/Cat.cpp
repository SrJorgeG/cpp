#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	_brain = new Brain();
	std::cout << "Cat parameterised constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	_brain = new Brain(*other._brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		if (_brain)
			delete _brain;
		_brain = new Brain(*other._brain);
	}
	std::cout << "Cat copy assignment operator called" << std::endl;
	return *this;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}

const std::string	Cat::getBrainIdea(int index) const
{
	return _brain->getIdea(index);
}

void	Cat::setBrainIdea(const std::string idea, int index)
{
	_brain->setIdea(index, idea);
}

