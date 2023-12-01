#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "../consts.hpp"
# include "ArmedEntity.hpp"

class Player : public ArmedEntity
{
private:
    int score;

public:
    Player( void );
    Player( Player const & origin );
    ~Player( void );

    Player  &operator = ( Player const & value );

    int const   &getScore( void ) const;

    void        addScore( int amount );
};

#endif
