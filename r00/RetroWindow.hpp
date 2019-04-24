#ifndef RUSH00_RETROWINDOW_HPP
#define RUSH00_RETROWINDOW_HPP

#include <ncurses.h>
#include <iostream>
#include "CosmoObject.hpp"
#include "List.hpp"

class RetroWindow
{
public:
	RetroWindow();
	~RetroWindow();
	void			start();
	static int		getRows();
	static int		getColumns();
	void			render(List *x, bool isMoveShips);

private:
	RetroWindow &operator=(RetroWindow const &x);
	RetroWindow(RetroWindow const &x);

	void _refresh();
	List *_checkEnemiesDeath(List *bullet);
	void _drawScore();
	void _drawMenu();
	void _drawGameOver();
	void _gameStart();
	void _setCosmoObject(CosmoObject const &x);

	WINDOW		*score;
	WINDOW		*game;

	int 			_rows;
	int 			_columns;
	int 			_score;
	static int		_playRows;
	static int 		_playColumns;
};


#endif
