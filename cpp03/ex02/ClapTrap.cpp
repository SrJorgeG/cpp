#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _ad(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _ad(0)
{
	std::cout << "Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap&  other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _ad(other._ad)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Default destructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap&  other)
{
	if (this != &other)
	{
		setName(other.getName());
		setHitPoints(other.getHitPoints());
		setEnergyPoints(other.getEnergyPoints());
		setAd(other.getAd());
	}
	return	*this;
}

std::string		ClapTrap::getName() const
{
	return _name;
}

unsigned int	ClapTrap::getHitPoints() const
{
	return _hitPoints;
}

unsigned int	ClapTrap::getEnergyPoints() const
{
	return _energyPoints;
}

unsigned int	ClapTrap::getAd() const
{
	return _ad;
}

void	ClapTrap::setName(std::string name)
{
	_name = name;
}

void	ClapTrap::setHitPoints(unsigned int hitPoints)
{
	_hitPoints = hitPoints;
}

void	ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
	_energyPoints = energyPoints;
}

void	ClapTrap::setAd(unsigned int ad)
{
	_ad = ad;
}

void	ClapTrap::attack(const std::string& target)
{
	if (!_hitPoints)
	{
		std::cout << "ClapTrap " << _name << " is already dead. " << std::endl;
		return;
	}	
	if (!_energyPoints)
	{
		std::cout << "ClapTrap " << _name << " is run out of energy. " << std::endl;
		return;
	}
	--_energyPoints;
	std::cout << "ClapTrap " << _name << " attacks " << target
	<< ", causing " << _ad << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!_hitPoints)
	{
		std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
		return;
	}
	if (amount > _hitPoints)
	{
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " got attacked, recieving " << amount
		<< " points of damage!, and unfortunaly died on duty." << std::endl;
	}
	else
	{
		_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " got attacked, recieving " << amount
		<< " points of damage!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!_hitPoints)
	{
		std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
		return;
	}	
	if (!_energyPoints)
	{
		std::cout << "ClapTrap " << _name << " is run out of energy." << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " repaired " << amount
	<< " points of damage!" << std::endl;
	_hitPoints += amount;
	--_energyPoints;
}

void	ClapTrap::showStatus() const
{
	std::cout << "ClapTrap: " << _name
	<< "\nHitpoints remaining: " << _hitPoints
	<< "\nEnergy points remaining: " << _energyPoints
	<<"\nAttack damage: " << _ad << std::endl;
}
