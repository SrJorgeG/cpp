#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"	
#include "WrongCat.hpp"	
#include "Dog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	const WrongAnimal* metaWrong = new WrongAnimal();
	const WrongAnimal* iWrong = new WrongCat();
	std::cout << iWrong->getType() << " " << std::endl;
	iWrong->makeSound(); //will output the cat sound!
	metaWrong->makeSound();

	return 0;
}
