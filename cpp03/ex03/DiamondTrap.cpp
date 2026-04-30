#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default"), ScavTrap(), FragTrap()
{
	std::cout << "Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(), FragTrap()
{
	std::cout << "Name constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap&  other) :  ClapTrap(other), ScavTrap(), FragTrap()
{
	std::cout << "Copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Default destructor called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap&  other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		setName(other.getName());
		std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	}
	return	*this;
}

void	DiamondTrap::showStatus() const
{
	std::cout << "DiamondTrap: " << getName() 
	<< "\nHitpoints remaining: " << getHitPoints()
	<< "\nEnergy points remaining: " << getEnergyPoints()
	<< "\nAttack damage: " << getAd() << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}