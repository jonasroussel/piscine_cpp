#include "Player.hpp"

/**
 * Constructors & Destructor
 */

Player::Player( void ) :
    ArmedEntity('^', 100, MAX_MOVE_SPEED),
    score(0)
{
    setAttackSpeed(10);
}

Player::Player( Player const & origin ) :
    ArmedEntity(origin),
    score(origin.score)
{
    setAttackSpeed(10);
}

Player::~Player( void ) {}

/**
 * Operators
 */

Player  &Player::operator = ( Player const & value )
{
    ArmedEntity::operator=(value);
    this->score = value.score;
    return *this;
}

/**
 * Getters
 */

int const   &Player::getScore( void ) const
{
    return this->score;
}

/**
 * Setters
 */

void        Player::addScore( int amount )
{
    this->score += amount;
}
