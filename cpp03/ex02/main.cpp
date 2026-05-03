#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap clap("CL4P-TP");

	clap.showStatus();
	clap.attack("Enemy");
	clap.showStatus();

	std::cout << "\n=== Creating ScavTrap ===" << std::endl;
	ScavTrap scav("SC4V-TP");

	scav.showStatus();
	scav.guardGate();
	scav.showStatus();

	std::cout << "\n=== Creating FragTrap ===" << std::endl;
	FragTrap frag("FR4G-TP");

	frag.showStatus();

	frag.attack("Target1");
	frag.showStatus();

	frag.highFivesGuys();

	frag.takeDamage(50);
	frag.showStatus();

	frag.beRepaired(30);
	frag.showStatus();

	std::cout << "\n=== Copy Constructor ===" << std::endl;
	FragTrap frag2(frag);
	frag2.showStatus();

	std::cout << "\n=== Assignment Operator ===" << std::endl;
	FragTrap frag3;
	frag3 = frag2;
	frag3.showStatus();

	std::cout << "\n=== Testing limits ===" << std::endl;
	FragTrap f("TestFrag");
	for (int i = 0; i < 100; i++)
		f.attack("ManyTargets");

	std::cout << "\n=== Destruction chain ===" << std::endl;
	{
		ClapTrap c("c1");
		ScavTrap s("s1");
		FragTrap f("f1");
	}

	return 0;
}