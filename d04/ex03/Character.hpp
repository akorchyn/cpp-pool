#ifndef HELPER_CHARACTER_HPP
#define HELPER_CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
	AMateria	*_inventory[4];
	int			_size;
	std::string _name;

public:
	Character(std::string const &name);
	Character(Character const &x);
	Character &operator=(Character const &x);
	~Character();


	std::string const	&getName() const;
	void				equip(AMateria *m);
	void				unequip(int idx);
	void				use(int id, ICharacter& target);


};


#endif
