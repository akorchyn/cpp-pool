#ifndef MUTANT_STACK
#define MUTANT_STACK

#include <iterator>
#include <vector>
#include <stack>

template <class T>
class MutantStack
{
public:
	typedef T												value_type;
	typedef T&												reference;
	typedef const T&										const_reference;
	typedef size_t											size_type;
	typedef typename std::vector<T>::reverse_iterator		iterator;
	typedef typename std::vector<T>::const_reverse_iterator	const_iterator;
	typedef typename std::vector<T>::iterator				reverse_iterator;
	typedef typename std::vector<T>::const_iterator			const_reverse_iterator;


	MutantStack();
	MutantStack(MutantStack const &x);
	MutantStack &operator=(MutantStack const &x);
	~MutantStack();

	operator std::stack<T>();

	bool		empty();
	size_type	size();
	reference	top();
	void		push(const_reference g);
	void		pop();

	iterator				begin();
	const_iterator			cbegin() const;
	iterator				end();
	const_iterator			cend() const;
	reverse_iterator		rbegin();
	const_reverse_iterator	crbegin() const;
	reverse_iterator		rend();
	const_reverse_iterator	crend() const;

private:
	std::vector <T>	_stack;
};

#endif