#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	/* data */
public:
	
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap&  other);
	~ScavTrap();
	ScavTrap&	operator=(const ScavTrap&  other);
};

ScavTrap::ScavTrap(/* args */)
{
}

ScavTrap::~ScavTrap()
{
}
