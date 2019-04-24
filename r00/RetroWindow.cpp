#include "RetroWindow.hpp"
#include "Menu.hpp"
#include "ObjectsGenerator.hpp"

int 	RetroWindow::_playRows = 0;
int 	RetroWindow::_playColumns = 0;

RetroWindow::RetroWindow() : score(NULL), _score(0)
{
	initscr();
	start_color();
	curs_set(0);
	timeout(1);
	noecho();
	getmaxyx(stdscr, _rows, _columns);
	game = newwin(_rows - 2, _columns - 31, 1, 1);
	keypad(stdscr, true);
	getmaxyx(game, _playRows, _playColumns);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	init_pair(6, COLOR_GREEN, COLOR_BLACK);
	_refresh();
}

RetroWindow::RetroWindow(RetroWindow const &x)
{
	*this = x;
}

RetroWindow &RetroWindow::operator=(RetroWindow const &x)
{
	(void)x;
	throw std::runtime_error("Copying forbidden");
	return *this;
}

RetroWindow::~RetroWindow()
{
	_drawGameOver();
	delwin(score);
	delwin(game);
	endwin();
	exit(0);
}

void RetroWindow::start()
{
	_drawMenu();
}

void RetroWindow::_refresh()
{
	wrefresh(game);
	wrefresh(score);
	refresh();
}

void RetroWindow::_drawGameOver()
{
	int ch;

	erase();
	attron(COLOR_PAIR(1));
	mvprintw(_rows / 2 - 5, _columns / 2 - 37, "%ls",     L"  ▄████  ▄▄▄       ███▄ ▄███▓▓█████     ▒█████   ██▒   █▓▓█████  ██▀███");
	mvprintw(_rows / 2 - 5 + 1, _columns / 2 - 37, "%ls", L" ██▒ ▀█▒▒████▄    ▓██▒▀█▀ ██▒▓█   ▀    ▒██▒  ██▒▓██░   █▒▓█   ▀ ▓██ ▒ ██▒");
	mvprintw(_rows / 2 - 5 + 2, _columns / 2 - 37, "%ls", L"▒██░▄▄▄░▒██  ▀█▄  ▓██    ▓██░▒███      ▒██░  ██▒ ▓██  █▒░▒███   ▓██ ░▄█ ▒");
	mvprintw(_rows / 2 - 5 + 3, _columns / 2 - 37, "%ls", L"░▓█  ██▓░██▄▄▄▄██ ▒██    ▒██ ▒▓█  ▄    ▒██   ██░  ▒██ █░░▒▓█  ▄ ▒██▀▀█▄");
	mvprintw(_rows / 2 - 5 + 4, _columns / 2 - 37, "%ls", L"░▒▓███▀▒ ▓█   ▓██▒▒██▒   ░██▒░▒████▒   ░ ████▓▒░   ▒▀█░  ░▒████▒░██▓ ▒██▒");
	mvprintw(_rows / 2 - 5 + 5, _columns / 2 - 37, "%ls", L"░▒   ▒  ▒▒   ▓▒█░░ ▒░   ░  ░░░ ▒░ ░   ░ ▒░▒░▒░    ░ ▐░  ░░ ▒░ ░░ ▒▓ ░▒▓░");
	mvprintw(_rows / 2 - 5 + 6, _columns / 2 - 37, "%ls", L"░   ░   ▒   ▒▒ ░░  ░      ░ ░ ░  ░     ░ ▒ ▒░    ░ ░░   ░ ░  ░  ░▒ ░ ▒░");
	mvprintw(_rows / 2 - 5 + 7, _columns / 2 - 37, "%ls", L"░ ░   ░   ░   ▒   ░      ░      ░      ░ ░ ░ ▒       ░░     ░     ░░   ░");
	mvprintw(_rows / 2 - 5 + 8, _columns / 2 - 37, "%ls", L"░       ░  ░       ░      ░  ░       ░ ░        ░     ░  ░   ░");
	mvprintw(_rows / 2 - 5 + 9, _columns / 2 - 37, "%ls", L"░");
	_refresh();
	while ((ch = getch()) != 'q' && ch != 'Q')
		;
}

void RetroWindow::_drawMenu()
{
	Menu	x(_columns, _rows);

	box(stdscr, 0, 0);
	wrefresh(stdscr);
	if (x.isStartGame())
		_gameStart();
	else
		this->~RetroWindow();
}

void RetroWindow::_gameStart()
{
	if (!score)
		score = newwin(_rows, 30, 0, _columns - 30);
	wclear(score);
	box(score, 0, 0);
	_refresh();
}

void RetroWindow::_setCosmoObject(CosmoObject const &x)
{
	int k = -1;

	for (int i = 0; i < x.getMaxHeight(); ++i)
		for (size_t j = 0; j < x.getCosmo()[i].size(); ++j)
			if (x.getCosmo()[i][j] != ' ' && ++k != -1)
			{
				if (x.getType() == "reverse bullet")
					wattron(game, COLOR_PAIR(6) | A_BOLD);
				else if (x.getType() == "player")
					wattron(game, COLOR_PAIR(5) | A_BOLD);
				else if (x.getType() == "enemy")
					wattron(game, COLOR_PAIR(4) | A_BOLD);
				else if (x.getType() == "bullet")
					wattron(game, COLOR_PAIR(6) | A_BOLD);
				else if (x.getType() == "static")
					wattron(game, COLOR_PAIR(2) | A_BOLD);
				mvwprintw(game, x.getCords()[k][Y], x.getCords()[k][X], "%c", x.getCosmo()[i][j]);
				wattrset(game, A_NORMAL);
			}
}

List	*RetroWindow::_checkEnemiesDeath(List *bullet)
{
	List *next_ptr = bullet->next;
	for (List *tmp = List::head->next; tmp; tmp = tmp->next)
	{
		if ((tmp->obj->getType() == "enemy" || tmp->obj->getType() == "static") && bullet->obj->checkIntersect(*tmp->obj))
		{
			if (tmp == next_ptr)
				next_ptr = tmp->next;
			if (tmp->prev)
				tmp->prev->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = tmp->prev;
			delete tmp->obj;
			delete tmp;
			if (bullet->prev)
				bullet->prev->next = bullet->next;
			if (bullet->next)
				bullet->next->prev = bullet->prev;
			delete bullet->obj;
			delete bullet;
			return (next_ptr);
		}
	}
	return (next_ptr);
}

void RetroWindow::render(List *x, bool isRenderShips)
{
	werase(game);
	_score++;
	while (x)
	{
		List *tmp = x->next;
		_setCosmoObject(*x->obj);
		if (x->obj->getType() == "static" && !(rand() % 500))
			x->push(new List(ObjectsGenerator::generateBullet(*x->obj)));
		if (x->obj->getType() != "static" && x->obj->getType() != "player" && (x->obj->getType() != "enemy" || isRenderShips))
		{
			if (!x->obj->move(x->obj->getType() == "bullet" ? 1 : -1, 0))
			{
				if (x->prev)
					x->prev->next = x->next;
				if (x->next)
					x->next->prev = x->prev;
				delete x->obj;
				delete x;
			}
			else if ((x->obj->getType() == "reverse bullet" || x->obj->getType() == "enemy") && List::head->obj->checkIntersect(*x->obj))
				this->~RetroWindow();
			else if (x->obj->getType() == "bullet")
				tmp = this->_checkEnemiesDeath(x);
		}
		x = tmp;
	}
	_drawScore();
	_refresh();
}

void RetroWindow::_drawScore()
{
	wattron(score, COLOR_PAIR(2));
	mvwprintw(score, 5, 10, "Score : %d", _score);
	mvwprintw(score, _rows - 3, 5, "Pause : Enter");
	mvwprintw(score, _rows - 4, 5, "Left : Left Arrow");
	mvwprintw(score, _rows - 5, 5, "Right : Right Arrow");
	mvwprintw(score, _rows - 6, 5, "Up : Up Arrow");
	mvwprintw(score, _rows - 7, 5, "Down : Down Arrow");
	mvwprintw(score, _rows - 8, 5, "Fire : Space");
	wrefresh(score);
	wattroff(score, COLOR_PAIR(2));
}

int RetroWindow::getRows()
{
	return _playRows;
}

int RetroWindow::getColumns()
{
	return _playColumns;
}
