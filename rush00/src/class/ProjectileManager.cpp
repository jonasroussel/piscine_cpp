#include "ProjectileManager.hpp"

/**
 * Constructors & Destructor
 */

ProjectileManager::ProjectileManager( void ) {}

ProjectileManager::ProjectileManager( ProjectileManager const & origin ) : projectiles(origin.projectiles) {}

ProjectileManager::~ProjectileManager( void ) {}

/**
 * Operators
 */

ProjectileManager   &ProjectileManager::operator = ( ProjectileManager const & value )
{
    this->projectiles = value.projectiles;
    return *this;
}

/**
 * Public Methods
 */

bool    hit( int * index, Enemy ** enn, Player * player, std::vector<Projectile>::iterator it, int x, int y )
{
    for (int i = 0; i < *index; i++)
    {
        if ((*enn)[i].getX() == x && (*enn)[i].getY() == y)
        {
            bool dead = (*enn)[i].takeDamage(it->getDamage());

            if (dead)
            {
                mvprintw((*enn)[i].getY(), (*enn)[i].getX(), " ");
                (*enn)[i] = (*enn)[*index - 1];
                (*enn)[(*index)--].~Enemy();

                player->addScore(10);
            }

            return true;
        }
    }

    return false;
}

void    ProjectileManager::update( int * index, Enemy ** enn, Player * player )
{
    for (std::vector<Projectile>::iterator it = projectiles.begin(); it != projectiles.end();)
    {
        int lx = it->getX();
        int ly = it->getY();

        if (hit(index, enn, player, it, lx, ly))
        {
            mvprintw(ly, lx, " ");
            it = projectiles.erase(it);
            continue;
        }

        if (it->getX() == player->getX() && it->getY() == player->getY())
        {
            player->takeDamage(it->getDamage());

            mvprintw(ly, lx, " ");
            it = projectiles.erase(it);
            continue;
        }

        it->clock();
        bool moved = it->move();

        if (moved)
        {
            int nx = it->getX();
            int ny = it->getY();

            if (hit(index, enn, player, it, nx, ny) || (ny > HEIGHT - 3 || ny < 1))
            {
                mvprintw(ly, lx, " ");
                it = projectiles.erase(it);
                continue;
            }

            if (it->getX() == player->getX() && it->getY() == player->getY())
            {
                player->takeDamage(it->getDamage());

                mvprintw(ly, lx, " ");
                it = projectiles.erase(it);
                continue;
            }

            attron(COLOR_PAIR(LASER));
            move(ly, lx);
            addch(' ');
            move(ny, nx);
            addch(it->getSymbol());
		    attroff(COLOR_PAIR(LASER));
        }
        
        it++;
    }
}

void    ProjectileManager::shoot( ArmedEntity * shooter, int x, int y, int dy, char owner )
{
    if (!shooter->shoot())
        return;

    Projectile  projectile = shooter->getProjectile();
    Projectile  newProjectile = projectile.clone();

    newProjectile.setXY(x, y + dy);
    newProjectile.setDY(dy);
    newProjectile.setOwner(owner);

    projectiles.push_back(newProjectile);
}


