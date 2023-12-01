#ifndef ROCKET_HPP
# define ROCKET_HPP

# include "Projectile.hpp"

class Rocket : public Projectile
{
public:
    Rocket( void );
    Rocket( Rocket const & origin );
    ~Rocket( void );

    Rocket   &operator = ( Rocket const & value );

    Projectile  clone( void );
};

#endif
