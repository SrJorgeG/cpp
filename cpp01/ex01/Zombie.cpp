#include "Zombie.hpp"

Zombie::Zombie() : _name("Default")
{
}

Zombie::Zombie(std::string name) : _name(name)
{
}

Zombie::~Zombie()
{
}

std::string Zombie::getName(void) const
{
	return (_name);
}

void Zombie::setName(std::string newName)
{
	_name = newName;
}

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
