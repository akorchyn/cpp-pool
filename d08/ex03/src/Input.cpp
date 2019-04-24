#include "../includes/Input.hpp"

Input::Input()
{
}

Input::Input(Input const &x)
{
	*this = x;
}

Input &Input::operator=(Input const __attribute__((unused)) &x)
{
	return *this;
}

Input::~Input()
{
}

void Input::execute(std::vector<char>::iterator &x,
					__attribute__((unused)) std::list<IOperation *>::iterator &queue) const
{
	if (std::cin.eof())
	{
		std::cout << "EOF" << std::endl;
		exit(0);
	}
	*x = std::cin.get();
}

IOperation * Input::clone()
{
	return new Input;
}
