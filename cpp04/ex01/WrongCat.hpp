#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class WrongCat : public Animal
{
public:
	WrongCat();
	WrongCat(std::string type);
	WrongCat(const WrongCat &other);
	WrongCat& operator=(const WrongCat &other);
	~WrongCat();

	void makeSound() const;
};
