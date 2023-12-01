# include "Enemy.hpp"

/**
 * Constructors & Destructor
 */

Enemy::Enemy( void ) : ArmedEntity('V', 10, 5)
{
    setDY(1);
    setAttackSpeed(-1);
}

Enemy::Enemy( char symbol, int hp, int speed ) : ArmedEntity(symbol, hp, speed)
{
    setDY(1);
    setAttackSpeed(-1);
}

Enemy::Enemy( Enemy const & origin ) : ArmedEntity(origin) {}

Enemy::~Enemy( void ) {}

/**
 * Operators
 */

Enemy   &Enemy::operator = ( Enemy const & value )
{
    ArmedEntity::operator=(value);
    return *this;
}
