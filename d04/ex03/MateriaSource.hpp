#ifndef HELPER_MATERIASOURCE_HPP
#define HELPER_MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <string>

class MateriaSource : public IMateriaSource
{
private:
	AMateria	*_store[4];
	int 		_size;

public:
	MateriaSource();
	MateriaSource(MateriaSource const &x);
	MateriaSource &operator=(MateriaSource const &x);
	~MateriaSource();

	virtual void learnMateria(AMateria *);
	virtual AMateria *createMateria(std::string const &type);
};


#endif
