#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "\n=== Creating ClapTrap ===" << std::endl;
	ClapTrap clap("CL4P-TP");
	clap.showStatus();
	clap.attack("Enemy");
	clap.showStatus();

	std::cout << "\n=== Creating ScavTrap ===" << std::endl;
	ScavTrap scav("SC4V-TP");
	scav.showStatus();
	scav.guardGate();

	std::cout << "\n=== Creating FragTrap ===" << std::endl;
	FragTrap frag("FR4G-TP");
	frag.showStatus();
	frag.highFivesGuys();

	std::cout << "\n=== Creating DiamondTrap ===" << std::endl;
	DiamondTrap diamond("DT-01");

	diamond.showStatus();

	std::cout << "\n=== DiamondTrap attacks (ScavTrap) ===" << std::endl;
	diamond.attack("Target1");
	diamond.showStatus();

	std::cout << "\n=== DiamondTrap whoAmI ===" << std::endl;
	diamond.whoAmI();
	diamond.showStatus();

	std::cout << "\n=== DiamondTrap guardGate (ScavTrap) ===" << std::endl;
	diamond.guardGate();
	diamond.showStatus();

	std::cout << "\n=== DiamondTrap highFivesGuys (FragTrap) ===" << std::endl;
	diamond.highFivesGuys();

	diamond.takeDamage(50);
	diamond.showStatus();

	diamond.beRepaired(25);
	diamond.showStatus();

	std::cout << "\n=== Copy Constructor ===" << std::endl;
	DiamondTrap diamond2(diamond);
	diamond2.showStatus();
	diamond2.whoAmI();

	std::cout << "\n=== Assignment Operator ===" << std::endl;
	DiamondTrap diamond3;
	diamond3 = diamond;
	diamond3.showStatus();
	diamond3.whoAmI();

	std::cout << "\n=== Testing attributes ===" << std::endl;
	DiamondTrap d("TestDiamond");
	std::cout << "Name: " << d.getName() << std::endl;

	std::cout << "\n=== Destruction chain ===" << std::endl;
	{
		DiamondTrap d("dt");
	}
	
	return 0;
}