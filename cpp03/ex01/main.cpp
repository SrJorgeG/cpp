#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap clap("CL4P-TP");

	clap.showStatus();
	clap.attack("Enemy");
	clap.showStatus();

	std::cout << "\n=== Creating ScavTrap ===" << std::endl;
	ScavTrap scav("SC4V-TP");

	scav.showStatus();

	scav.attack("Target1");
	scav.showStatus();

	scav.guardGate();
	scav.showStatus();

	scav.takeDamage(30);
	scav.showStatus();

	scav.beRepaired(20);
	scav.showStatus();

	std::cout << "\n=== Copy Constructor ===" << std::endl;
	ScavTrap scav2(scav);
	scav2.showStatus();

	std::cout << "\n=== Assignment Operator ===" << std::endl;
	ScavTrap scav3;
	scav3 = scav2;
	scav3.showStatus();

	std::cout << "\n=== Testing limits ===" << std::endl;
	for (int i = 0; i < 50; i++)
		scav.attack("ManyTargets");

	for (int i = 0; i < 5; i++)
	{
		ScavTrap s("Test");
		s.showStatus();
	}

	return 0;
}