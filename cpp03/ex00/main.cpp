#include "ClapTrap.hpp"

int main( void ) 
{
	ClapTrap a("A");
	ClapTrap* b = &a;
	b->attack("target");

	a.showStatus();
	return 0;
}
