#include "IEntity.hpp"

/**
 * Private Methods
 */

bool    IEntity::canMove( void )
{
    return this->moveDelay == 0;
}

/**
 * Constructors & Destructor
 */

IEntity::IEntity( void ) :
    moveDelay(0),
    x(0),
    y(0),
    dy(0),
    symbol('*'),
    hp(1),
    moveSpeed(0)
{}

IEntity::IEntity(
    char _symbol,
    int _hp,
    int _moveSpeed
):
    moveDelay(0),
    x(0),
    y(0),
    dy(0),
    symbol(_symbol),
    hp(_hp),
    moveSpeed(_moveSpeed)
{}

IEntity::IEntity( IEntity const & origin ) :
    moveDelay(origin.moveDelay),
    x(origin.x),
    y(origin.y),
    dy(origin.dy),
    symbol(origin.symbol),
    hp(origin.hp),
    moveSpeed(origin.moveSpeed)
{}

IEntity::~IEntity( void ) {}

/**
 * Operators
 */

IEntity &IEntity::operator = ( IEntity const & value )
{
    this->moveDelay = value.moveDelay;
    
    this->x = value.x;
    this->y = value.y;
    this->dy = value.dy;

    this->symbol = value.symbol;
    this->hp = value.hp;
    this->moveSpeed = value.moveSpeed;

    return *this;
}

/**
 * Public Methods
 */

void    IEntity::clock( void )
{
    if (!canMove() && this->moveDelay > 0)
        this->moveDelay--;
}

bool    IEntity::takeDamage( int amount )
{
    if (this->hp - amount <= 0)
    {
        this->hp = 0;
        return true;
    }
    else
    {
        this->hp -= amount;
        return false;
    }
}

bool    IEntity::move( int dx )
{
    bool    moved = false;

    if (!canMove())
        return moved;

    if (this->moveSpeed <= 0)
        this->moveDelay = -1;
    else if (this->moveSpeed > MAX_MOVE_SPEED)
        this->moveDelay = 0;
    else
        this->moveDelay = MAX_MOVE_SPEED - this->moveSpeed;
    
    if (this->dy != 0)
    {
        this->y += (this->dy < 0 ? -1 : 1);
        moved = true;
    }
    
    if (dx != 0)
    {
        this->x += (dx < 0 ? -1 : 1);
        moved = true;
    }

    return moved;
}

/**
 * Getters
 */

int const   &IEntity::getX( void ) const
{
    return this->x;   
}

int const   &IEntity::getY( void ) const
{
    return this->y;
}

int const   &IEntity::getDY( void ) const
{
    return this->dy;
}

char const  &IEntity::getSymbol( void ) const
{
    return this->symbol;
}

int const   &IEntity::getHP( void ) const
{
    return this->hp;
}

int const   &IEntity::getMoveSpeed( void ) const
{
    return this->moveSpeed;
}

/**
 * Setters
 */

void        IEntity::setX( int value )
{
    this->x = value;
}

void        IEntity::setY( int value )
{
    this->y = value;
}

void        IEntity::setXY( int _x, int _y )
{
    this->x = _x;
    this->y = _y;
}

void        IEntity::setDY( int value )
{
    this->dy = value;
}
