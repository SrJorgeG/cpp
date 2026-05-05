#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain*		_brain;
public:
	Cat();
	Cat(std::string type);
	Cat(const Cat &other);
	Cat& operator=(const Cat &other);
	~Cat();

	void makeSound() const;

	const std::string	getBrainIdea(int index) const;
	void	setBrainIdea(const std::string idea, int index);

};
