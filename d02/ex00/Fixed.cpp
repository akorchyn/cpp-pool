#include "Fixed.hpp"

Fixed::Fixed() : _fixPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &x)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this == &x)
		return (*this);
	_fixPointValue = x.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixPointValue);
}

void Fixed::setRawBits(const int &x)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fixPointValue = x;
}


