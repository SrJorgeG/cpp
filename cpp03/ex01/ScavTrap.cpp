#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), _guardGateFlag(false)
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAd(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _guardGateFlag(false)
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAd(20);
}

ScavTrap::ScavTrap(const ScavTrap&  other) : ClapTrap(other), _guardGateFlag(other._guardGateFlag)
{
	setHitPoints(other.getHitPoints());
	setAd(other.getAd());
	setEnergyPoints(other.getEnergyPoints());
}

ScavTrap::~ScavTrap()
{
}


ScavTrap&	ScavTrap::operator=(const ScavTrap&  other)
{
	if (this  !=  &other)
	{
		ClapTrap::operator=(other);
		setGuardGateFlag(other.getGuardGateFlag());
		setHitPoints(other.getHitPoints());
		setEnergyPoints(other.getEnergyPoints());
		setAd(other.getAd());
	}
	return *this;
}

bool	ScavTrap::getGuardGateFlag() const
{
	return _guardGateFlag;
}

void	ScavTrap::setGuardGateFlag(bool flag)
{
	_guardGateFlag = flag;
}

void	ScavTrap::attack(const std::string& target)
{
	if (!getHitPoints())
	{
		std::cout << "ScavTrap " << getName() << " is already dead. " << std::endl;
		return;
	}	
	if (!getEnergyPoints())
	{
		std::cout << "ScavTrap " << getName() << " is run out of energy. " << std::endl;
		return;
	}
	setEnergyPoints(getEnergyPoints() - 1);
	std::cout << "ScavTrap " << getName() << " attacks " << target
	<< ", causing " << getAd() << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	if (getGuardGateFlag())
	{		
		std::cout << "ScavTrap " << getName() << " is already in guard mode." << std::endl;
		return ;
	}
	setGuardGateFlag(true);
	std::cout << "ScavTrap " << getName() << " is now on guard mode." << std::endl;
}
