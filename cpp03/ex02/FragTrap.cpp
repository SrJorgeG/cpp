#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAd(30);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAd(30);
}

FragTrap::FragTrap(const FragTrap&  other) : ClapTrap(other) 
{
	setHitPoints(other.getHitPoints());
	setEnergyPoints(other.getEnergyPoints());
	setAd(other.getAd());
}

FragTrap::~FragTrap()
{
}


FragTrap&	FragTrap::operator=(const FragTrap&  other)
{
	if (this  !=  &other)
	{
		ClapTrap::operator=(other);
		setHitPoints(other.getHitPoints());
		setEnergyPoints(other.getEnergyPoints());
		setAd(other.getAd());
	}
	return *this;
}


void	FragTrap::attack(const std::string& target)
{
	if (!getHitPoints())
	{
		std::cout << "FragTrap " << getName() << " is already dead. " << std::endl;
		return;
	}	
	if (!getEnergyPoints())
	{
		std::cout << "FragTrap " << getName() << " is run out of energy. " << std::endl;
		return;
	}
	setEnergyPoints(getEnergyPoints() - 1);
	std::cout << "FragTrap " << getName() << " attacks " << target
	<< ", causing " << getAd() << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << getName() << "High five browski!" << std::endl;
}
