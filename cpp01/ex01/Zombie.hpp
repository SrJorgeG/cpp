#pragma once

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string	_name;
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	std::string getName(void) const;
	void		setName(std::string newName);
	void announce( void ); 
};

Zombie* zombieHorde(int N, std::string name);