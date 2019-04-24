#include "MutantStack.cpp"
#include <iostream>
#include <stack>
int main()
{
	MutantStack<int>	mstack;

	std::cout << std::boolalpha << mstack.empty() << std::endl;


	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(7006);
	mstack.push(11);
	mstack.push(99);
	mstack.push(25);
	std::cout << std::endl;
	{
		std::cout << "ITERATOR" << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << '\t';
			++it;
		}
		std::cout << std::endl;
		std::cout << std::endl;

	}
	{
		std::cout << "ORIGINAL STACK AFTER CONSTRUCTING BY TOP AND POP" << std::endl;
		std::stack<int> n(mstack);

		while (!n.empty())
		{
			std::cout << n.top() << '\t';
			n.pop();
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "REVERSE ITERATOR" << std::endl;
		MutantStack<int>::reverse_iterator it = mstack.rbegin();
		MutantStack<int>::reverse_iterator ite = mstack.rend();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << '\t';
			++it;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << "CURRENT SIZE : " << mstack.size() << std::endl;
}