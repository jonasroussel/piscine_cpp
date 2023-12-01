#include "Rocket.hpp"

/**
 * Constructors & Destructor
 */

Rocket::Rocket( void ) : Projectile(30, '$', 8) {}

Rocket::Rocket( Rocket const & origin ) : Projectile(origin) {}

Rocket::~Rocket( void ) {}

/**
 * Operators
 */

Rocket   &Rocket::operator = ( Rocket const & value )
{
    Projectile::operator=(value);
    return *this;
}

/**
 * Public Methods
 */

Projectile  Rocket::clone( void )
{
    return Rocket(*this);
}
