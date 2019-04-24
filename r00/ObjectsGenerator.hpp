#ifndef RUSH00_ENEMYGENERATOR_HPP
#define RUSH00_ENEMYGENERATOR_HPP

#include "CosmoObject.hpp"

class ObjectsGenerator
{
public:
	ObjectsGenerator();
	ObjectsGenerator(ObjectsGenerator const &x);
	ObjectsGenerator &operator=(ObjectsGenerator const &x);
	~ObjectsGenerator();

	void				push(CosmoObject const &x);
	CosmoObject			*generate();
	static CosmoObject	*generateStar();
	static CosmoObject	*generateBullet(CosmoObject const &ship);

private:
	int 			_size;
	CosmoObject		**_enemies;
};


#endif
