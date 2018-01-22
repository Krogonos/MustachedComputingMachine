#include "CoffeeMachine.h"

bool Coffee::CoffeeMachine::_hasFlag(const int& flag = 0) const
{
    if (!flag)
        return false;

    return ((_flags & flag) == flag);
}

//returns state AFTER toggle
bool Coffee::CoffeeMachine::togglePower()
{
    if (_hasFlag(POWER))
    {
        _removeFlag(POWER);
        return false;
    }

    _addFlag(POWER);
    return true;
}

void Coffee::CoffeeMachine::brew()
{
    while (water != 0)
    {
        --water;
        ++coffee;
    }

    if (coffee)
        _addFlag(COFFEE);

    if (!water)
        _removeFlag(WATER);

    return;
}

void Coffee::CoffeeMachine::addSpecial(const int& special)
{
    _addFlag(special);
    std::cout << "This coffee is special." << std::endl;
}
