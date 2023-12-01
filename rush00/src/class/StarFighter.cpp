#include "StarFighter.hpp"

/**
 * Constructors & Destructor
 */

StarFighter::StarFighter( void ) : Enemy('W', 10, 3)
{
    Laser laser = Laser();    

    setAttackSpeed(5);
    setProjectile(laser);
}

StarFighter::StarFighter( StarFighter const & origin ) : Enemy(origin) {}

StarFighter::~StarFighter( void ) {}

/**
 * Operators
 */

StarFighter &StarFighter::operator = ( StarFighter const & value )
{
    Enemy::operator=(value);
    return *this;
}
