#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"


class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string 	_name;
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap&  other);
	~DiamondTrap();
	DiamondTrap&	operator=(const DiamondTrap&  other);

	std::string		getName() const;
	void			setName(std::string name);

	void	showStatus() const;
	void	attack(const std::string& target);
	void	whoAmI();
};
