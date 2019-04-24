#include "ObjectsGenerator.hpp"
#include "RetroWindow.hpp"

ObjectsGenerator::ObjectsGenerator() :  _size(0), _enemies(NULL)
{
}

CosmoObject *ObjectsGenerator::generateStar()
{
	std::string		star[] = {"*", ""};

	return new CosmoObject(RetroWindow::getColumns() - 1,
							   rand() % (RetroWindow::getRows() -1), star, "star");
}

CosmoObject *ObjectsGenerator::generateBullet(CosmoObject const &ship)
{
	int maxX = 0;
	int minX = 1000;
	int y = 0;
	std::string	bullet[][3] = {{"=>", "", ""}, {"/", "\\" ""}};
	std::string type;
	int **cords = ship.getCords();

	for (int i = 0; cords[i]; ++i)
	{
		if (cords[i][X] > maxX)
			maxX = cords[i][X];
		if (cords[i][X] < minX)
			minX = cords[i][X];
		if (cords[i][Y] > y)
			y = cords[i][Y];
	}
	maxX++;
	minX--;
	y -= ship.getMaxHeight() / 2;
	type = ship.getType() == "player" ? "bullet" : "reverse bullet";
	return new CosmoObject(type == "bullet" ? maxX : minX, y, bullet[type != "bullet"], type);
}

ObjectsGenerator::ObjectsGenerator(ObjectsGenerator const &x) : _size(x._size), _enemies(new CosmoObject *[_size])
{
	for (int i = 0; i < _size; i++)
		_enemies[i] = new CosmoObject(*x._enemies[i]);
}

ObjectsGenerator &ObjectsGenerator::operator=(ObjectsGenerator const &x)
{
	if (&x == this)
		return *this;
	this->~ObjectsGenerator();
	_size = x._size;
	if (x._size > 0)
	{
		_enemies = new CosmoObject *[x._size];
		for (int i = 0; i < _size; i++)
			_enemies[i] = new CosmoObject(*x._enemies[i]);
	}
	else
		_enemies = NULL;
	return *this;
}

ObjectsGenerator::~ObjectsGenerator()
{
	for (int i = 0; i < _size; i++)
		delete _enemies[i];
	delete [] _enemies;
}

void ObjectsGenerator::push(CosmoObject const &x)
{
	CosmoObject **tmp = new CosmoObject *[++_size];

	for (int i = 0; i < _size - 1; i++)
		tmp[i] = _enemies[i];
	delete [] _enemies;
	_enemies = tmp;
	tmp[_size - 1] = new CosmoObject(x);
}

CosmoObject *ObjectsGenerator::generate()
{
	CosmoObject	*x = _enemies[rand() % _size];
	return new CosmoObject(RetroWindow::getColumns() - x->getMaxWidth(),
			rand() % (RetroWindow::getRows() - x->getMaxHeight()), x->getCosmo(), x->getType());
}

