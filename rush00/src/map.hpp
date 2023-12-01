
#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>

# define MAX_EN 420
# define HEIGHT 40
# define WIDTH 50

class Map
{
	public:
	int				cmax;
	int				lmax;
	std::string		map;
	Map();
	Map(int, int);
	~Map();
	Map(const Map&);
	Map &operator=(const Map&);

	private:

};


#endif
