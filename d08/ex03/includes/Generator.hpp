#ifndef HELPER_GENERATOR_HPP
#define HELPER_GENERATOR_HPP

#include "EndCycle.hpp"
#include "Ignore.hpp"
#include "Minus.hpp"
#include "NextElement.hpp"
#include "Plus.hpp"
#include "PrevElement.hpp"
#include "Print.hpp"
#include "StartCycle.hpp"
#include <string>
#include "Input.hpp"
#include <map>

class Generator
{
public:
	static const char plus = '&';
	static const char minus = '|';
	static const char nextElement = ')';
	static const char prevElement = '(';
	static const char startLoop = '{';
	static const char endLoop = '}';
	static const char print = '*';
	static const char input = ':';

	Generator();
	Generator(Generator const &x);
	Generator &operator=(Generator const &x);
	~Generator();

	IOperation *getOperation(char c);

private:
	IOperation	*createPlus();
	IOperation	*createMinus();
	IOperation	*createNextEleme();
	IOperation	*createPrevEleme();
	IOperation	*createStartLoop();
	IOperation	*createEndLoop();
	IOperation	*createPrint();
	IOperation	*createInput();

	std::map <char, IOperation *(Generator::*)()> _func;
};


#endif
