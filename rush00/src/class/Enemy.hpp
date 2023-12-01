#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "ArmedEntity.hpp"

class Enemy : public ArmedEntity
{
public:
    Enemy( void );
    Enemy( char symbol, int hp, int speed );
    Enemy( Enemy const & origin );
    ~Enemy( void );

    Enemy   &operator = ( Enemy const & value );
};

#endif
