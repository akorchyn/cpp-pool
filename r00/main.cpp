#include "RetroWindow.hpp"
#include "CosmoObject.hpp"
#include <zconf.h>
#include "ObjectsGenerator.hpp"
# define L1 "[=>> }"
# define L2 "}}    }"
# define L3 "}}}====>"
# define L4 "}}    }"
# define L5 "[=>> }"

void		initEnemy(ObjectsGenerator	&generator)
{
	srand(time(NULL));
	std::string enemy[] = {" /", "<|", " \\", ""};
	std::string enemy2[] = {"        /", "<======---", "        \\", ""};
	std::string enemy3[] = {"  {==3", "<<<=", "  {==3", ""};

	generator.push(CosmoObject(0, 0, enemy2, "enemy"));
	generator.push(CosmoObject(0, 0, enemy3, "enemy"));
	generator.push(CosmoObject(0, 0, enemy, "static"));
}
int main()
{
	setlocale(LC_ALL, "");
	std::string 		ship[] = {L1, L2, L3, L4, L5, ""};
	ObjectsGenerator	generator;
	RetroWindow			x;
	CosmoObject			player(1, RetroWindow::getRows() / 2, ship, "player");
	List				*objects = new List(&player);

	player.move(0, -player.getMaxHeight() / 2);
	initEnemy(generator);
	x.start();
	for (int i = 0, c; (c = getch()) != 'q' && c != 'Q'; i++)
	{
		usleep(10000);
		objects->push(new List(ObjectsGenerator::generateStar()));
		if (i == 20)
			objects->push(new List(generator.generate()));
		x.render(objects, !(i % 5));
		i == 20 ? i = 0 : 0;
		if (c == KEY_LEFT)
			player.move(-1, 0);
		else if (c == KEY_RIGHT)
			player.move(1, 0);
		else if (c == KEY_UP)
			player.move(0, -1);
		else if (c == KEY_DOWN)
			player.move(0, 1);
		else if (c == ' ')
			objects->push(new List(ObjectsGenerator::generateBullet(player)));
		else if (c == 10)
			x.start();
	}
	return 0;
}