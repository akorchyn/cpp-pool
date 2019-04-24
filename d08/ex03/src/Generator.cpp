#include "Generator.hpp"

const char Generator::plus;
const char Generator::minus;
const char Generator::nextElement;
const char Generator::prevElement;
const char Generator::startLoop;
const char Generator::endLoop;
const char Generator::print;
const char Generator::input;

Generator::Generator()
{
	_func[plus] = &Generator::createPlus;
	_func[minus] = &Generator::createMinus;
	_func[nextElement] = &Generator::createNextEleme;
	_func[prevElement] = &Generator::createPrevEleme;
	_func[startLoop] = &Generator::createStartLoop;
	_func[endLoop] = &Generator::createEndLoop;
	_func[print] = &Generator::createPrint;
	_func[input] = &Generator::createInput;
}


Generator::Generator(Generator const &x)
{
	*this = x;
}

Generator &Generator::operator=(Generator const __attribute__((unused)) &x)
{
	if (&x == this)
		return *this;
	_func = x._func;
	return *this;
}

Generator::~Generator()
{
}

IOperation *Generator::createPlus()
{
	return new Plus();
}

IOperation *Generator::createMinus()
{
	return new Minus;
}

IOperation *Generator::createNextEleme()
{
	return new NextElement;
}

IOperation *Generator::createPrevEleme()
{
	return new PrevElement;
}

IOperation *Generator::createStartLoop()
{
	return new StartCycle;
}

IOperation *Generator::createEndLoop()
{
	return new EndCycle;
}

IOperation *Generator::createPrint()
{
	return new Print;
}

IOperation *Generator::createInput()
{
	return new Input;
}

IOperation *Generator::getOperation(char c)
{
	IOperation	*(Generator::*create)() = _func[c];
	if (create == NULL)
		return new Ignore;
	return (this->*create)();
}
