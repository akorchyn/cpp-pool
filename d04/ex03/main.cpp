#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"

void	memory()
{
	IMateriaSource *src = new MateriaSource;
	src->learnMateria(new Ice() );
	src->learnMateria(new Cure());

	ICharacter *zaz = new Character("zaz");
	AMateria *tmp;

	tmp = src->createMateria("ice");
	zaz->equip(tmp);
	tmp = src->createMateria("cure");
	zaz->equip(tmp);

	ICharacter *bob = new Character("bob");
	AMateria			*x = src->createMateria("ice");

	zaz->use(0, *bob);
	zaz->use(1, *bob);
	zaz->use(3, *bob);
	zaz->equip(x);
	zaz->use(100, *bob);
	zaz->use(2, *bob);
	zaz->use(0, *bob);
	zaz->unequip(2);
	zaz->use(2, *bob);
	delete x;
	delete bob;
	delete zaz;
	delete src;
}

int main()
{
	memory();
	system("leaks a.out");
}