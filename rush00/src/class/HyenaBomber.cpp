#include "HyenaBomber.hpp"

/**
 * Constructors & Destructor
 */

HyenaBomber::HyenaBomber( void ) : Enemy('U', 20, 1)
{
    Rocket rocket = Rocket();

    setAttackSpeed(1);
    setProjectile(rocket);
}

HyenaBomber::HyenaBomber( HyenaBomber const & origin ) : Enemy(origin) {}

HyenaBomber::~HyenaBomber( void ) {}

/**
 * Operators
 */

HyenaBomber &HyenaBomber::operator = ( HyenaBomber const & value )
{
    Enemy::operator=(value);
    return *this;
}
