#include "ArmedEntity.hpp"

/**
 * Private Methods
 */

bool    ArmedEntity::canShoot( void )
{
    return this->shootDelay == 0 && this->attackSpeed > -1;
}

/**
 * Constructors & Destructor
 */

ArmedEntity::ArmedEntity( void ) :
    IEntity(),
    shootDelay(0),
    projectile(Projectile()),
    attackSpeed(0)
{}

ArmedEntity::ArmedEntity(
    char symbol,
    int hp,
    int speed
):
    IEntity(symbol, hp, speed),
    shootDelay(0),
    projectile(Projectile()),
    attackSpeed(0)
{}

ArmedEntity::ArmedEntity( ArmedEntity const & origin ) :
    IEntity(origin),
    shootDelay(origin.shootDelay),
    projectile(origin.projectile),
    attackSpeed(origin.attackSpeed)
{}

ArmedEntity::~ArmedEntity( void ) {}

/**
 * Operators
 */

ArmedEntity &ArmedEntity::operator = ( ArmedEntity const & value )
{
    IEntity::operator=(value);
    this->shootDelay = value.shootDelay;
    this->projectile = value.projectile;
    this->attackSpeed = value.attackSpeed;
    return *this;
}

/**
 * Public Methods
 */

void    ArmedEntity::clock( void )
{
    IEntity::clock();
    if (!canShoot() && this->shootDelay > 0)
        this->shootDelay--;
}

bool    ArmedEntity::shoot( void )
{
    if (!canShoot())
        return false;
    this->shootDelay = MAX_ATCK_SPPED - this->attackSpeed;
    return true;
}

/**
 * Getters
 */

Projectile const    &ArmedEntity::getProjectile( void ) const
{
    return this->projectile;
}

int const           &ArmedEntity::getAttackSpeed( void ) const
{
    return this->attackSpeed;
}

/**
 * Setters
 */

void    ArmedEntity::setProjectile( Projectile & value )
{
    this->projectile = value;
}

void    ArmedEntity::setAttackSpeed( int value )
{
    this->attackSpeed = value;
}
