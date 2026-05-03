#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap("CL4P-TP");

	clap.showStatus();

	clap.attack("Enemy1");
	clap.showStatus();

	clap.attack("Enemy2");
	clap.showStatus();

	clap.takeDamage(5);
	clap.showStatus();

	clap.beRepaired(3);
	clap.showStatus();

	clap.takeDamage(8);
	clap.showStatus();

	clap.beRepaired(10);
	clap.showStatus();

	for (int i = 0; i < 8; i++)
		clap.attack("Target");
	clap.showStatus();

	clap.beRepaired(5);
	clap.showStatus();

	ClapTrap clap2(clap);
	clap2.showStatus();

	ClapTrap clap3;
	clap3 = clap2;
	clap3.showStatus();

	return 0;
}