

#include "map.hpp"

Map::Map()
{
	return ;
}

Map::Map(int col, int line): cmax(col), lmax(line)
{
	return ;
}

Map::~Map()
{
	return ;
}

Map::Map(const Map& m)
{
	*this = m;
}

Map	&Map::operator=(const Map& m)
{
	this->cmax = m.cmax;
	this->lmax = m.lmax;
	return (*this);
}

