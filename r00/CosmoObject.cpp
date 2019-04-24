#include "CosmoObject.hpp"
#include "RetroWindow.hpp"

CosmoObject::CosmoObject()
{
}

CosmoObject::CosmoObject(int x, int y, std::string const *cosmo, std::string const &type)
: _type(type), _maxHeight(0), _cords(NULL)
{
	setCosmo(cosmo);
	move(x, y);
}

CosmoObject::CosmoObject(CosmoObject const &x)
{
	*this = x;
}

bool CosmoObject::checkIntersect(CosmoObject const &x) const
{
	for (int i = 0; _cords[i]; i++)
		for (int j = 0; x._cords[j]; j++)
			if (_cords[i][X] == x._cords[j][X] && _cords[i][Y] == x._cords[j][Y])
				return true;
	return false;
}

CosmoObject &CosmoObject::operator=(CosmoObject const &x)
{
	if (&x == this)
		return *this;
	_maxHeight = x._maxHeight;
	_maxWidth = x._maxWidth;
	_type = x._type;
	for (int i = 0; i < _maxHeight; i++)
		_cosmo[i] = x._cosmo[i];
	initCords();
	for (int i = 0; x._cords[i]; ++i)
	{
		_cords[i][X] = x._cords[i][X];
		_cords[i][Y] = x._cords[i][Y];
	}
	return *this;
}

CosmoObject::~CosmoObject()
{
	for (int i = 0; _cords[i]; ++i)
		delete [] _cords[i];
	delete [] _cords;
}

bool	CosmoObject::move(int shiftX, int shiftY)
{
	for (int i = 0; _cords[i]; ++i)
	{
		if (_cords[i][X] + shiftX >= RetroWindow::getColumns() || _cords[i][X]  + shiftX < 0)
			return false;
		if (_cords[i][Y]  + shiftY >= RetroWindow::getRows() || _cords[i][Y]  + shiftY < 0)
			return false;
	}
	for (int i = 0; _cords[i]; ++i)
	{
		_cords[i][X] += shiftX;
		_cords[i][Y] += shiftY;
	}
	return true;
}

void CosmoObject::getHeightWidth()
{
	if (_cosmo[0].empty())
	{
		_maxWidth = 0;
		_maxHeight = 0;
		return ;
	}
	size_t	maxWidth = _cosmo[0].size();
	int		maxHeigth = 1;
	while (!_cosmo[maxHeigth].empty())
	{
		if (maxWidth < _cosmo[maxHeigth].size())
			maxWidth = _cosmo[maxHeigth].size();
		maxHeigth++;
	}
	_maxWidth = maxWidth;
	_maxHeight = maxHeigth;
}

void	CosmoObject::initCords()
{
	int res = 0;
	int k = -1;

	for (int i = 0; i < _maxHeight; ++i)
		for (int j = 0; _cosmo[i][j]; ++j)
			if (_cosmo[i][j] != ' ')
				res++;
	_cords = new int*[res + 1];
	_cords[res] = NULL;
	for (int i = 0; i < _maxHeight; ++i)
		for (size_t j = 0; j < _cosmo[i].size(); ++j)
			if (_cosmo[i][j] != ' ')
			{
				_cords[++k] = new int[2];
				_cords[k][X] = j;
				_cords[k][Y] = i;
			}
}

const std::string *CosmoObject::getCosmo() const
{
	return _cosmo;
}

void CosmoObject::setCosmo(std::string const *cosmo)
{
	for (int i = 0; i < _maxHeight; i++)
		delete _cords[i];
	delete [] _cords;
	for (int i = 0; !cosmo[i].empty(); i++)
		if (i > 10)
			throw std::runtime_error("Object is too big");
		else
			_cosmo[i] = cosmo[i];
	getHeightWidth();
	initCords();
}

const std::string &CosmoObject::getType() const
{
	return _type;
}

int **CosmoObject::getCords() const
{
	return _cords;
}

int CosmoObject::getMaxWidth() const
{
	return _maxWidth;
}

int CosmoObject::getMaxHeight() const
{
	return _maxHeight;
}
