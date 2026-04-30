#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	bool	_guardGateFlag;
public:
	
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap&  other);
	~ScavTrap();
	ScavTrap&	operator=(const ScavTrap&  other);

	void guardGate();

	bool	getGuardGateFlag() const;
	void	setGuardGateFlag(const bool flag);

	void	attack(const std::string& target);
};
