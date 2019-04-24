#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"
#include "Squad.hpp"

void	memoryLeak()
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;

	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);

	for (int i = 0; i < vlc->getCount(); i++)
	{
		ISpaceMarine *cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	std::cout << vlc->getCount() << std::endl;
	vlc->push(bob);
	std::cout << vlc->getCount() << std::endl;
	for (int i = 0; i < 5; i++)
	{
		vlc->push(bob->clone());
		vlc->push(jim->clone());
	}
	ISquad	*x = new Squad(*dynamic_cast<Squad *>(vlc));
	x->push(bob->clone());
	std::cout << vlc->getCount() << std::endl;
	delete x;
	delete vlc;
}

int main()
{
	memoryLeak();
	system("leaks a.out");
}
