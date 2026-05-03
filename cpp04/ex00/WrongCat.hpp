#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
	std::string _type;
public:
	WrongCat();
	WrongCat(const std::string &type);
	WrongCat(const WrongCat &other);
	WrongCat& operator=(const WrongCat &other);
	~WrongCat();

	std::string getType() const;
	void setType(const std::string& type);

	void makeSound() const;
};
