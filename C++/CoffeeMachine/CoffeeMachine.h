#include "stdafx.h"

class CoffeeMachine
{
public:
    CoffeeMachine() = default;
    CoffeeMachine(int w) : water(w) { if (water) _addFlag(WATER); }
    CoffeeMachine(int w, int c) : water(w), coffee(c)
    {
        if (water)
            _addFlag(WATER);

        if (coffee)
            _addFlag(COFFEE);

        std::cout << "object created with two arguments." << std::endl;
        std::cout << _flags << std::endl;
    }

    int water = 0;
    int coffee = 0;

    bool togglePower();
    void brew();

    void removeSpecial(const int& spec) { _removeFlag(spec); }
    void addSpecial(const int& spec) { _addFlag(spec); }
    bool hasSpecial(const int& spec) const { if (_hasFlag(spec)) return true; }

    enum Special
    {
        CHOCOLATE        = 0x00000002,
        VANILLA          = 0X00000004,
        HAZELNUT         = 0X00000008,
        PUMPKIN_SPICE    = 0x00000010,
        WHIPPED_CREAM    = 0x00000020,
        SPRINKLES        = 0x00000040,
        MAX_SPECIAL =
            CHOCOLATE | VANILLA | HAZELNUT | PUMPKIN_SPICE | WHIPPED_CREAM | SPRINKLES
    };

private:
    enum Status
    {
        NULL_STATUS  = 0x00000000,
        BLACK        = 0x00000001,
        POWER        = 0x00001000,
        GROUNDS      = 0x00002000,
        WATER        = 0x00004000,
        COFFEE       = 0x00008000,

        MAX_FLAGS =
        MAX_SPECIAL |
        BLACK | POWER | GROUNDS | COFFEE | WATER
    };

    mutable int _flags = 0;

    inline void _setFlag(const int& flag)    { _flags = flag; }
    inline void _removeFlag(const int& flag) { _flags &= ~flag; }
    inline void _addFlag(const int& flag)    { _flags |= flag; }
    inline bool _hasFlag(const int& flag = 0) const { return ((_flags & flag) == flag); }
};


bool CoffeeMachine::togglePower()
{
    if (_hasFlag(POWER))
    {
        _removeFlag(POWER);
        return false;
    }

    _addFlag(POWER);
    return true;
}

void CoffeeMachine::brew()
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



