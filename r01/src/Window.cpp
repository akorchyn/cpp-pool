#include "../includes/Window.hpp"


Window::Window()
{
}

void Window::_initCursesWins()
{
	for (size_t i = 0; i < windows.size(); i++)
		delwin(windows.at(i));
	windows.clear();
	maxModules = 0;
	getmaxyx(stdscr, maxY, maxX);
	maxX -= 30;
	noecho();
	curs_set(0);
	timeout(0);
	keypad(stdscr, true);
	erase();
	for (int rows = maxY / 15, i = 0; i < rows; i++)
		for (int cols = maxX / 30, j = 0; j < cols; j++)
		{
			maxModules++;
			windows.push_back(newwin(15, 30, i * 15, j * 30));
		}
	menu = newwin(maxY, 30, 0, maxX);
	wtimeout(menu, 10000);
}

Window::Window(bool isCurses) : isCurses(isCurses), isClosed(false), maxModules(0)
{
	if (isCurses)
	{
		initscr();
		start_color();
		init_pair(1, COLOR_YELLOW, COLOR_BLACK);
		init_pair(2, COLOR_GREEN, COLOR_BLACK);
		init_pair(3, COLOR_YELLOW, COLOR_BLACK);
		init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
		raw();
		_initCursesWins();
	}
}

Window::Window(__attribute__((unused))Window const &x)
{
}

Window &Window::operator=(__attribute__((unused))Window const &x)
{
	return *this;
}

void Window::delMonitor(size_t index)
{
	if (index >= modules.size())
		return ;
	if (isCurses)
		werase(windows.at(index));
	delete *(modules.begin() + index);
	modules.erase(modules.begin() + index);
}

void Window::setMonitor(IMonitorDisplay *monitor)
{
	if (!monitor)
		return ;
	if (modules.size() >= maxModules)
	{
		delete monitor;
		return;
	}
	modules.push_back(monitor);
}

void Window::clearWins()
{
	if (isCurses)
	{
		for (std::vector<WINDOW *>::iterator it = windows.begin(); it != windows.end(); it++)
			werase(*it);
		werase(menu);
	}
}

void Window::refreshWins()
{
	if (isCurses)
	{
		for (std::vector<WINDOW *>::iterator it = windows.begin(); it != windows.end(); it++)
			wrefresh(*it);
		wrefresh(menu);
	}
}

int Window::_getIndex()
{
	int index;

	echo();
	mvwprintw(menu, 1, 6, "Enter index: ");
	wrefresh(menu);
	mvwscanw(menu, 1, 20, const_cast<char *>("%d"), &index);
	noecho();
	return index - 1;
}

void Window::delAll()
{
	for (std::vector<IMonitorDisplay *>::iterator it = modules.begin(); it != modules.end(); it++)
		delete *it;
	modules.clear();
}

void Window::_handleButtonCurses()
{
	MonitorGenerator	gen;
	int c = getch();

	if (isClosed)
		return ;
	try
	{
		if (c == KEY_RESIZE)
		{
			delwin(menu);
			_initCursesWins();
		}
		else if (c == 'f' || c == 'F')
			delAll();
		else if (c == 'a' || c == 'A')
			setMonitor(gen.getDisplay(_getIndex()));
		else if (c == 'D' || c == 'd')
			delMonitor(_getIndex());
		else if (c == 'q' || c == 'Q')
			isClosed = true;
	}
	catch (std::exception &x)
	{
	}
}

void Window::_drawMenu()
{
	mvwprintw(menu, 6, 9, "Buttons: ");
	mvwprintw(menu, 7, 2, "Q       - Quit");
	mvwprintw(menu, 8, 2, "A [id]  - Add monitor");
	mvwprintw(menu, 9, 2, "D [num] - Del monitor");
	mvwprintw(menu, 10, 2, "F       - Delete all");
	mvwprintw(menu, 12, 9, "Monitors id: ");
	mvwprintw(menu, 13, 2, "1 - Log Host Monitor");
	mvwprintw(menu, 14, 2, "2 - Os Info Monitor");
	mvwprintw(menu, 15, 2, "3 - Date Monitor");
	mvwprintw(menu, 16, 2, "4 - Cpu Load Monitor");
	mvwprintw(menu, 17, 2, "5 - Ram Load Monitor");
	mvwprintw(menu, 18, 2, "6 - Net Throughput Monitor");
	mvwprintw(menu, 19, 2, "7 - Pretty Catty Monitor");
	mvwprintw(menu, 20, 2, "8 - Motivation Monitor");
	mvwprintw(menu, 21, 2, "Max number modules : %u", maxModules);

	int y = getmaxy(menu);
	mvwprintw(menu, y - 3, 10, "©akorchyn");
	mvwprintw(menu, y - 2, 10, "©atikhono");
}

void Window::handleButton()
{
	if (isCurses)
		_handleButtonCurses();
}

bool Window::update()
{
	if (isClosed)
		return false;
	if (isCurses)
	{
		clearWins();
		_drawMenu();
		box(menu, 0, 0);
		for (size_t i = 0; i < windows.size() && i < maxModules && i < modules.size(); i++)
				try
				{
					modules.at(i)->drawCurses(windows.at(i), i + 1);
				}
				catch(...)
				{
				}
		refreshWins();
	}
	return true;
}

Window::~Window()
{
	for (size_t i = 0; isCurses && i < windows.size(); i++)
		delwin(windows.at(i));
	for (std::vector<IMonitorDisplay *>::iterator it = modules.begin(); it != modules.end(); it++)
		delete *it;
	delwin(menu);
	endwin();
}
