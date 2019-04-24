#include "../includes/TokenGenerator.hpp"

TokenGenerator::TokenGenerator()
{
	_func['+'] = &TokenGenerator::createPlus;
	_func['-'] = &TokenGenerator::createMinus;
	_func['/'] = &TokenGenerator::createDivision;
	_func['*'] = &TokenGenerator::createMultiply;
	_func['('] = &TokenGenerator::createParOpen;
	_func[')'] = &TokenGenerator::createParClose;
}

TokenGenerator::TokenGenerator(TokenGenerator const &x)
{
	*this = x;
}

TokenGenerator &TokenGenerator::operator=(TokenGenerator const &x)
{
	if (&x == this)
		return *this;
	_func = x._func;
	return *this;
}

TokenGenerator::~TokenGenerator()
{
}

IToken *TokenGenerator::_parseNum(std::string::const_iterator &x, bool isNegative) const
{
	long num = 0;

	if (isNegative && !std::isdigit(*(++x)))
		throw std::runtime_error("Sign error");
	while (std::isdigit(*x))
	{
		num = num * 10 + (*x - 48);
		x++;
	}
	if (num > INT_MAX || (isNegative && -num < INT_MIN))
		throw std::runtime_error("Overflow");
	return new Number(isNegative ? -num : num);
}

IToken *TokenGenerator::createPlus()
{
	return new Plus;
}

IToken *TokenGenerator::createMinus()
{
	return new Minus;
}

IToken *TokenGenerator::createDivision()
{
	return new Division;
}

IToken *TokenGenerator::createMultiply()
{
	return new Multiply;
}

IToken *TokenGenerator::createParOpen()
{
	return new ParOpen;
}

IToken *TokenGenerator::createParClose()
{
	return new ParClose;
}

IToken *TokenGenerator::_parseOp(std::string::const_iterator &x)
{
	IToken	*(TokenGenerator::*create)() = _func[*x];

	if (create)
	{
		x++;
		return (this->*create)();
	}
	throw std::runtime_error(std::string("Bad symbol : ") + *x);
}

IToken *TokenGenerator::generatateToken(std::string::const_iterator &x)
{
	static bool isPreviousToken = true;

	if (std::isdigit(*x) || (isPreviousToken && *x == '-'))
	{
		isPreviousToken = false;
		return _parseNum(x, *x == '-');
	}
	else if (*x != ')')
		isPreviousToken = true;
	return  _parseOp(x);
}
