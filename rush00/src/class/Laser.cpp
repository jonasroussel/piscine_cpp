#include "Laser.hpp"

/**
 * Constructors & Destructor
 */

Laser::Laser( void ) : Projectile(10, '|', 40) {}

Laser::Laser( Laser const & origin ) : Projectile(origin) {}

Laser::~Laser( void ) {}

/**
 * Operators
 */

Laser   &Laser::operator = ( Laser const & value )
{
    Projectile::operator=(value);
    return *this;
}

/**
 * Public Methods
 */

Projectile  Laser::clone( void )
{
    return Laser(*this);
}
