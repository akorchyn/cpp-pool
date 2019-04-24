#ifndef HELPER_FIXED_HPP
#define HELPER_FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int 				_fixPointValue;
	static const int 	_nBits = 8;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &f);
	Fixed	&operator=(const Fixed &x);
	int 	getRawBits(void) const;
	void	setRawBits(const int &x);
};


#endif
