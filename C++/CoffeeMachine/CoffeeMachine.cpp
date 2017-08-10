#include "CoffeeMachine.h"

//check range
//if value out of range, resets _state
bool _Coffee::CoffeeMachine::_hasFlag(const int& flag = 0)
{
    if (flag <= _Coffee::CoffeeMachine::Flag::FAILED || flag > _Coffee::CoffeeMachine::Flag::MAX)
    {
        std::cout << "Error 0: brew failed. Value: " << flag << std::endl;
        this->_setFlag(_Coffee::CoffeeMachine::Flag::FAILED);
        std::cout << "Value Reset" << std::endl;

            return false;
    }

    if (!flag)
        return (_state ? true : false);


    return (_state & flag ? true : false);
} 

void _Coffee::CoffeeMachine::_removeFlag(const int& flag)
{
    if (_hasFlag())
    {
        if (_hasFlag(flag))
           this->_state &= ~flag;
    }

    
    return;
}

//
void _Coffee::CoffeeMachine::_addFlag(const int& flag)
{
    if (_hasFlag(flag))
        return;

    this->_state |= flag;
    return;
}

//1) Must make sure flag is in range
void _Coffee::CoffeeMachine::_setFlag(const int& flag)
{ 
    if (flag > _Coffee::CoffeeMachine::Flag::MAX || flag < _Coffee::CoffeeMachine::Flag::FAILED)
        return;

    this->_state = flag;

    return;
}