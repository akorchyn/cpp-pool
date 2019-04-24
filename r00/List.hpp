//
// Created by Yevhenii OCHEREDKO on 2019-04-06.
//

#ifndef RUSH00_LIST_HPP
#define RUSH00_LIST_HPP
#include <cstdlib>
#include "CosmoObject.hpp"

class List
{

private:
	List();

public:
	CosmoObject *obj;
	List		*prev;
	List		*next;
	static List	*head;

	List(List const &src);
	List(CosmoObject *_obj);
	~List();

	List	&operator=(List const &src);
	void	push(List *elem);
	void	push_front(List *elem);

};


#endif //RUSH00_LIST_HPP
