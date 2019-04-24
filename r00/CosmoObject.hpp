#ifndef RUSH00_COSMOOBJECT_HPP
#define RUSH00_COSMOOBJECT_HPP
#define X 0
#define Y 1
#include <string>

class CosmoObject
{

public:
	CosmoObject(int x, int y, std::string const *cosmo, std::string const &type);
	CosmoObject(CosmoObject const &x);
	CosmoObject &operator=(CosmoObject const &x);
	~CosmoObject();

	bool				move(int shiftX, int shiftY);
	bool				checkIntersect(CosmoObject const &x) const;
	void				setCosmo(std::string const *cosmo);
	int					**getCords() const;
	const std::string 	&getType() const;
	int getMaxWidth() const;
	int getMaxHeight() const;
	const std::string *getCosmo() const;

private:
	CosmoObject();
	void	getHeightWidth();
	void	initCords();

	std::string _type;
	int			_maxWidth;
	int 		_maxHeight;
	int 		**_cords;
	std::string _cosmo[10];

};


#endif
