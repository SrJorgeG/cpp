#include "Brain.hpp"

Brain::Brain() 
{
	for (size_t i = 0; i < 100; i++)
		_ideas[i] = "idea";
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(std::string ideas[], int size)
{
	for (int i = 0; i < 100; i++)
		(i < size) ? _ideas[i] = ideas[i] : _ideas[i] = "idea";
	std::cout << "Brain parameterised constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	for (size_t i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain()
{
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	std::cout << "Brain copy assignment operator called" << std::endl;
	return *this;
}

const std::string			Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
		return "Invalid index";
	return _ideas[index];
}

const std::string*	Brain::getIdeas() const
{
	return _ideas;
}

void				Brain::setIdeas(std::string ideas[], int size)
{
	for (int i = 0; i < 100; i++)
		(i < size) ? _ideas[i] = ideas[i] : _ideas[i] = "idea";
}

void				Brain::setIdea(int index, const std::string& idea)
{
	if (index < 0 || index >= 100)
		return;
	_ideas[index] = idea;
}
