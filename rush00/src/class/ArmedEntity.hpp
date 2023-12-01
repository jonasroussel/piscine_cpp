#ifndef ARMEDENTITY_HPP
# define ARMEDENTITY_HPP

# include <string>

# include "IEntity.hpp"
# include "Projectile.hpp"

class ArmedEntity : public IEntity
{
private:
    int shootDelay;

    bool    canShoot( void );

protected:
    Projectile  projectile;
    int         attackSpeed;

public:
    ArmedEntity( void );
    ArmedEntity( char symbol, int hp, int speed );
    ArmedEntity( ArmedEntity const & origin );
    virtual ~ArmedEntity( void );

    ArmedEntity &operator = ( ArmedEntity const & value );

    void    clock( void );
    bool    shoot( void );

    Projectile const    &getProjectile( void ) const;
    int const           &getAttackSpeed( void ) const;

    void    setProjectile( Projectile & value );
    void    setAttackSpeed( int value );
};

#endif
