#include "Fixed.hpp"

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::Fixed() : _fixPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
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
	_fixPointValue = x._fixPointValue;
	return (*this);
}

Fixed::Fixed(const int x) : _fixPointValue(x << _nBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float x)
{
	std::cout << "Float constructor called" << std::endl;
	_fixPointValue = roundf(x * (1 << _nBits));
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(_fixPointValue) / (1 << _nBits);
}

int Fixed::toInt(void) const
{
	return _fixPointValue >> _nBits;
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

std::ostream &operator<<(std::ostream &out, const Fixed &x)
{
	out << x.toFloat();
	return out;
}





