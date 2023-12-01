#ifndef IENTITY_HPP
# define IENTITY_HPP

# include "../consts.hpp"

class IEntity
{
private:
    int moveDelay;

    bool    canMove( void );

protected:
    int     x;
    int     y;
    int     dy;

    char    symbol;
    int     hp;
    int     moveSpeed;

public:
    IEntity( void );
    IEntity( char _symbol, int _hp, int _moveSpeed );
    IEntity( IEntity const & origin );
    ~IEntity( void );

    IEntity &operator = ( IEntity const & value );

    void    clock( void );
    bool    takeDamage( int amount );
    bool    move( int dx = 0 );

    int const   &getX( void ) const;
    int const   &getY( void ) const;
    int const   &getDY( void ) const;
    char const  &getSymbol( void ) const;
    int const   &getHP( void ) const;
    int const   &getMoveSpeed( void ) const;

    void        setX( int value );
    void        setY( int value );
    void        setXY( int _x, int _y );
    void        setDY( int value );
};

#endif
