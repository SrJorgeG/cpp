#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap&  other);
	virtual ~FragTrap();
	FragTrap&	operator=(const FragTrap&  other);

	void highFivesGuys(void);

	void	attack(const std::string& target);
};
