#ifndef HELPER_PEON_HPP
#define HELPER_PEON_HPP

#include "Victim.hpp"
#include <string>

class Peon : public Victim
{
public:
	Peon(const std::string &name);
	Peon(const Peon &x);
	Peon &operator=(const Peon &x);
	~Peon();
	void	getPolymorphed() const;
};

#endif
