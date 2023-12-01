#ifndef PROJECTILEMANAGER_HPP
# define PROJECTILEMANAGER_HPP

# include <iostream>
# include <ncurses.h>
# include <vector>

# include "../map.hpp"
# include "Enemy.hpp"
# include "Projectile.hpp"
# include "ArmedEntity.hpp"
# include "Player.hpp"
# include "../consts.hpp"

class ProjectileManager
{
private:
    std::vector<Projectile> projectiles;

public:
    ProjectileManager( void );
    ProjectileManager( ProjectileManager const & origin );
    ~ProjectileManager( void );

    ProjectileManager   &operator = ( ProjectileManager const & value );

    void    update( int * index, Enemy ** enn, Player * player );
    void    shoot( ArmedEntity * shooter, int x, int y, int dy, char owner );
};

# endif
