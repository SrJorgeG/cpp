#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain*		_brain;
public:
	Dog();
	Dog(std::string type);
	Dog(const Dog &other);
	Dog& operator=(const Dog &other);
	~Dog();

	void makeSound() const;

	const std::string	getBrainIdea(int index) const;
	void	setBrainIdea(const std::string idea, int index);

};
