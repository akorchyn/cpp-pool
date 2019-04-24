#ifndef HELPER_TOKENGENERATOR_HPP
#define HELPER_TOKENGENERATOR_HPP

#include "Number.hpp"
#include "Division.hpp"
#include "Multiply.hpp"
#include "Plus.hpp"
#include "Minus.hpp"
#include "ParClose.hpp"
#include "ParOpen.hpp"
#include <map>

class TokenGenerator
{
public:
	TokenGenerator();
	TokenGenerator(TokenGenerator const &x);
	TokenGenerator &operator=(TokenGenerator const &x);
	~TokenGenerator();

	IToken	*generatateToken(std::string::const_iterator &x);

private:
	IToken	*_parseNum(std::string::const_iterator &x, bool isNegative) const;
	IToken	*_parseOp(std::string::const_iterator &x);

	IToken	*createPlus();
	IToken	*createMinus();
	IToken	*createDivision();
	IToken	*createMultiply();
	IToken	*createParOpen();
	IToken	*createParClose();

	std::map <char, IToken *(TokenGenerator::*)()>	_func;
};


#endif
