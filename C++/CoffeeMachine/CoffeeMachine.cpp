#include "CoffeeMachine.h"

//if no args, false if null
bool Coffee::CoffeeMachine::_hasFlag(const int& flag = 0) const
{
    if (!flag)
        return false;

    if (flag <= Coffee::CoffeeMachine::Status::NULL_STATUS || flag > Coffee::CoffeeMachine::Status::MAX_FLAGS)
        return false;

    return (this->_flags & flag == flag);
}

bool Coffee::CoffeeMachine::togglePower() const
{
}

void Coffee::CoffeeMachine::addSpecial(const int &)
{
}

//1) Must make sure flag is in range
void Coffee::CoffeeMachine::_setFlag(const int& flag)
{ 
    if (flag > Coffee::CoffeeMachine::Status::MAX_FLAGS || flag < Coffee::CoffeeMachine::Status::NULL_STATUS)
        return;

    this->_flags = flag;

    return;
}