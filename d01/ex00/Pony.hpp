#ifndef CPP_POOL_PONY_H
#define CPP_POOL_PONY_H

class Pony
{
private:
	int		_tail;
	int		_teeth;
	int		_eyes;

public:
	int		get_teeth() const;
	void	set_teeth(int _teeth);
	int		get_tail() const;
	void	set_tail(int _tail);
	int		getEyes() const;
	void	set_eyes(int _eyes);
};


#endif
