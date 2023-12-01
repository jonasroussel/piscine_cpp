#ifndef HYENABOMBER_HPP
# define HYENABOMBER_HPP

# include "Enemy.hpp"
# include "ArmedEntity.hpp"
# include "Rocket.hpp"

class HyenaBomber : public Enemy
{
public:
    HyenaBomber( void );
    HyenaBomber( HyenaBomber const & origin );
    ~HyenaBomber( void );

    HyenaBomber &operator = ( HyenaBomber const & value );
};

#endif
