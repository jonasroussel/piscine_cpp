#ifndef LASER_HPP
# define LASER_HPP

# include "Projectile.hpp"

class Laser : public Projectile
{
public:
    Laser( void );
    Laser( Laser const & origin );
    ~Laser( void );

    Laser   &operator = ( Laser const & value );

    Projectile  clone( void );
};

#endif
