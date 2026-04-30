#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
private:
	std::string 	_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_ad;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap&  other);
	virtual ~ClapTrap();
	ClapTrap&	operator=(const ClapTrap&  other);
	
	std::string		getName() const;
	unsigned int	getHitPoints() const;
	unsigned int	getEnergyPoints() const;
	unsigned int	getAd() const;

	void	setName(std::string name);
	void	setHitPoints(unsigned int hitPoints);
	void	setEnergyPoints(unsigned int energyPoints);
	void	setAd(unsigned int ad);
	
	virtual void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	showStatus() const;
};
