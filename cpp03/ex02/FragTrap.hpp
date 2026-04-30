#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	
public:
	
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap&  other);
	~FragTrap();
	FragTrap&	operator=(const FragTrap&  other);

	void highFivesGuys(void);

	void	attack(const std::string& target);
};
