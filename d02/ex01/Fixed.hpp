#ifndef HELPER_FIXED_HPP
#define HELPER_FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int 				_fixPointValue;
	static const int 	_nBits = 8;

public:
	Fixed();
	Fixed(const int x);
	Fixed(const float x);
	float toFloat(void) const;
	int	  toInt(void) const;
	~Fixed();
	Fixed(const Fixed &f);
	Fixed	&operator=(const Fixed &x);
	int 	getRawBits(void) const;
	void	setRawBits(const int &x);
};

std::ostream& operator<<(std::ostream &os, const Fixed& n);

#endif
