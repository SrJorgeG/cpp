#pragma once

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string	_name;
public:
	Zombie(std::string name);
	~Zombie();
	std::string getName(void) const;
	void		setName(std::string newName);
	void announce( void ); 
};


Zombie* newZombie( std::string name );
void randomChump( std::string name );


