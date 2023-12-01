#ifndef STARFIGHTER_HPP
# define STARFIGHTER_HPP

# include "Enemy.hpp"
# include "ArmedEntity.hpp"
# include "Laser.hpp"

class StarFighter : public Enemy
{
public:
    StarFighter( void );
    StarFighter( StarFighter const & origin );
    ~StarFighter( void );

    StarFighter &operator = ( StarFighter const & value );
};

#endif
