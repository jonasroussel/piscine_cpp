#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

# include "IEntity.hpp"

class Projectile : public IEntity
{
protected:
    int     damage;
    char    owner;

public:
    Projectile( void );
    Projectile( int _damage, char symbol, int moveSpeed );
    Projectile( Projectile const & origin );
    virtual ~Projectile( void );

    Projectile  &operator = ( Projectile const & value );

    virtual Projectile  clone( void );

    int const   &getDamage( void ) const;
    char const  &getOwner( void ) const;

    void        setOwner( char owner );
};

#endif
