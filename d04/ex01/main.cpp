#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "Character.hpp"

void	memory()
{
	Character	*zaz = new Character("zaz");
	std::cout << *zaz;
	Enemy *b = new RadScorpion();

	AWeapon *pr = new PlasmaRifle();
	AWeapon *pf = new PowerFist();

	zaz->equip(pr);
	std::cout << *zaz;
	zaz->equip(pf);

	zaz->attack(b);
	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;

	b = new SuperMutant();
	zaz->attack(b);
	zaz->recoverAP();
	zaz->attack(b);
	zaz->recoverAP();
	zaz->attack(b);
	zaz->recoverAP();
	zaz->attack(b);
	zaz->recoverAP();
	zaz->attack(b);
	zaz->recoverAP();
	zaz->attack(b);
	zaz->recoverAP();
	zaz->attack(b);
	zaz->recoverAP();
	zaz->attack(b);
	zaz->recoverAP();
	zaz->attack(b);
	zaz->recoverAP();
	zaz->attack(b);
	zaz->recoverAP();
	std::cout << *zaz;
	delete zaz;
	delete pr;
	delete pf;
}

int main()
{
	memory();
	system("leaks a.out");
}