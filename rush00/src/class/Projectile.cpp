#include "Projectile.hpp"

/**
 * Constructors & Destructor
 */

Projectile::Projectile( void ) :
    IEntity('|', 1, 10),
    damage(0),
    owner(0)
{}

Projectile::Projectile( int _damage, char symbol, int moveSpeed ) :
    IEntity(symbol, 1, moveSpeed),
    damage(_damage),
    owner(0)
{}

Projectile::Projectile( Projectile const & origin ) :
    IEntity(origin),
    damage(origin.damage),
    owner(origin.owner)
{}

Projectile::~Projectile( void ) {}

/**
 * Operators
 */

Projectile  &Projectile::operator = ( Projectile const & value )
{
    IEntity::operator=(value);
    this->damage = value.damage;
    return *this;
}

/**
 * Public Methods
 */

Projectile  Projectile::clone( void )
{
    return Projectile(*this);
}

/**
 * Getters
 */

int const   &Projectile::getDamage( void ) const
{
    return this->damage;
}

char const  &Projectile::getOwner( void ) const
{
    return this->owner;
}

/**
 * Setters
 */

void        Projectile::setOwner( char owner )
{
    this->owner = owner;
}
