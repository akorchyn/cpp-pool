#include "Fixed.hpp"

bool	Fixed::verbose = true;

//Constructors and Destructor

Fixed::Fixed() : _fixPointValue(0)
{
	if (verbose)
		std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int x) : _fixPointValue(x << _nBits)
{
	if (verbose)
		std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float x)
{
	if (verbose)
		std::cout << "Float constructor called" << std::endl;
	_fixPointValue = roundf(x * (1 << _nBits));
}

Fixed::Fixed(const Fixed &f)
{
	if (verbose)
		std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::~Fixed()
{
	if (verbose)
		std::cout << "Destructor called" << std::endl;
}

// Operators

Fixed &Fixed::operator=(const Fixed &x)
{
	if (verbose)
		std::cout << "Assignation operator called" << std::endl;
	if (this == &x)
		return (*this);
	_fixPointValue = x._fixPointValue;
	return (*this);
}

bool	Fixed::operator>(const Fixed &rht) const
{
	return this->_fixPointValue > rht._fixPointValue;
}

bool	Fixed::operator<(const Fixed &rht) const
{
	return this->_fixPointValue < rht._fixPointValue;
}

bool	Fixed::operator==(const Fixed &rht) const
{
	return this->_fixPointValue == rht._fixPointValue;
}

bool	Fixed::operator!=(const Fixed &rht) const
{
	return this->_fixPointValue == rht._fixPointValue;
}

bool	Fixed::operator>=(const Fixed &rht) const
{
	return this->_fixPointValue >= rht._fixPointValue;
}

bool	Fixed::operator<=(const Fixed &rht) const
{
	return this->_fixPointValue <= rht._fixPointValue;
}

Fixed Fixed::operator+(const Fixed &rht) const
{
	Fixed	x = *this;

	x._fixPointValue += rht._fixPointValue;
	return x;
}

Fixed Fixed::operator-(const Fixed &rht) const
{
	Fixed	x = *this;

	x._fixPointValue -= rht._fixPointValue;
	return x;
}

Fixed Fixed::operator*(const Fixed &rht) const
{
	Fixed	x = *this;
	x._fixPointValue = (x._fixPointValue * rht._fixPointValue) >> _nBits;

	return Fixed(x);
}

Fixed Fixed::operator/(const Fixed &rht) const
{
	Fixed	x = *this;

	x._fixPointValue = ((x._fixPointValue << _nBits) / rht._fixPointValue);
	return x;
}

Fixed Fixed::operator++()
{
	this->_fixPointValue++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	tmp(*this);
	this->_fixPointValue++;
	return (tmp);
}

Fixed Fixed::operator--()
{
	this->_fixPointValue--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	tmp(*this);
	this->_fixPointValue--;
	return (tmp);
}

// Function

float Fixed::toFloat(void) const
{
	return static_cast<float>(_fixPointValue) / (1 << 8);
}

int Fixed::toInt(void) const
{
	return _fixPointValue >> 8;
}

int Fixed::getRawBits(void) const
{
	if (verbose)
		std::cout << "getRawBits member function called" << std::endl;
	return (_fixPointValue);
}

void Fixed::setRawBits(const int &x)
{
	if (verbose)
		std::cout << "setRawBits member function called" << std::endl;
	_fixPointValue = x;
}

std::ostream &operator<<(std::ostream &out, const Fixed &x)
{
	out << x.toFloat();
	return out;
}

// Non members function

Fixed			&Fixed::min(Fixed &a, Fixed &b)
{
	return (a > b ? b : a);
}

const Fixed		&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a > b ? b : a);
}

Fixed			&Fixed::max(Fixed &a, Fixed &b)
{
	return (a < b ? b : a);
}

const Fixed		&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a < b ? b : a);
}
