#include "Victim.hpp"
#include "Sorcerer.hpp"
#include "Peon.hpp"

void memory()
{
	Sorcerer volanDeMort("volanDeMort", "the Magnificent");

	Victim		jim("Jimmy");
	Peon		joe("Joe");
	Peon		joe2(joe);
	Victim		jimmy(jim);

	std::cout << volanDeMort << jim << joe << joe2 << jimmy;

	volanDeMort.polymorph(jim);
	volanDeMort.polymorph(joe);
	volanDeMort.polymorph(jimmy);
	volanDeMort.polymorph(joe2);
}

int main()
{
	system("leaks a.out");

	return (0);
}