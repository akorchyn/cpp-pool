//
// Created by Yevhenii OCHEREDKO on 2019-04-06.
//

#include "List.hpp"

List	*List::head = NULL;

List::List()
{}

List::List(CosmoObject *obj)
: obj(obj), prev(NULL), next(NULL)
{}

List::List(List const &src)
{
	*this = src;
}

List::~List()
{}

List	&List::operator=(List const &src)
{
	this->obj = src.obj;
	this->prev = src.prev;
	this->next = src.next;
	return (*this);
}

void	List::push(List *elem)
{
	List *tmp = this;

	if (!tmp->next && !tmp->prev)
		List::head = tmp;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
	elem->prev = tmp;
}

void	List::push_front(List *elem)
{
	List *tmp = this;

	while (tmp && tmp->prev)
		tmp = tmp->prev;
	tmp->prev = elem;
	elem->next = this;
}
