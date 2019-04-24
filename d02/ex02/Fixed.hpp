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
	Fixed(const Fixed &f);
	~Fixed();

	Fixed	&operator=(const Fixed &x);
	bool	operator>(const Fixed &rht) const;
	bool	operator<(const Fixed &rht) const;
	bool	operator==(const Fixed &rht) const;
	bool	operator!=(const Fixed &rht) const;
	bool	operator>=(const Fixed &rht) const;
	bool	operator<=(const Fixed &rht) const;
	Fixed   operator+(const Fixed &rht) const;
	Fixed   operator-(const Fixed &rht) const;
	Fixed   operator*(const Fixed &rht) const;
	Fixed   operator/(const Fixed &rht) const;
	Fixed   operator++();
	Fixed   operator++(int);
	Fixed 	operator--();
	Fixed   operator--(int);

	float		toFloat(void) const;
	int			toInt(void) const;
	int			getRawBits(void) const;
	void		setRawBits(const int &x);

	static Fixed			&min(Fixed &a, Fixed &b);
	static const Fixed		&min(const Fixed &a, const Fixed &b);
	static Fixed			&max(Fixed &a, Fixed &b);
	static const Fixed		&max(const Fixed &a, const Fixed &b);
};

std::ostream& operator<<(std::ostream &os, const Fixed& n);


#endif
