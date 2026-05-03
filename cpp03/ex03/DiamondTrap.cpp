#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default"), ScavTrap("Default"), FragTrap("Default")
{
	std::cout << "Default constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAd(30);
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	std::cout << "Name constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap&  other) :  ClapTrap(other), ScavTrap(other), FragTrap(other)
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

std::string		DiamondTrap::getName() const
{
	return _name;
}

void	DiamondTrap::setName(std::string name)
{
	_name = name;
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

void DiamondTrap::whoAmI()
{
	
	std::cout << "Name:" << _name 
	<< "\nClapTrap name:" << ClapTrap::_name << "_clap_name" << std::endl;
}
