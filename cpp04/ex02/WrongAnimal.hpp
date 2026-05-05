#pragma once

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
	std::string _type;
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal &other);
	virtual ~WrongAnimal();

	void makeSound() const;

	std::string getType() const;
	void setType(const std::string& type);
		
	WrongAnimal& operator=(const WrongAnimal &other);
};
