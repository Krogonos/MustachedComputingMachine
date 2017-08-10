#ifndef __COFFEE_MACHINE_H__
#define __COFFEE_MACHINE_H__

#include <iostream>
 
//todo: 
//boost for real time brewing, timer functions, and measurements
//exception handling
//console picture functions

namespace _Coffee
{
    using milileter = float;
    using ounce     = float;
    using gram      = float;

    class CoffeeMachine
    {
    public:
        CoffeeMachine() = default;
        //todo more constructors

        //todo: make size affect visual
        milileter fluidCapacity = 12.0f;
        milileter groundCapacity = 1.0f;

        milileter decanter = 0.0f;
        milileter resevoir = 0.0f;
        gram      grounds = 0.0f;
        
        milileter coffee = 0.0f;

        //void pour(signed 
        void start() const;
        void halt() const;
        void togglePower() const;

        bool full() const;
        bool status() const;

    private:
        enum Flag
        {
            FAILED                 = 0x00000000, //coffee not made
            SUCCEEDED              = 0x00000002, //
            POWER                  = 0x00000004, //need before brew
            GROUNDS                = 0x00000008, //grounds in
            WATER                  = 0x00000010, //water in
            FILTER                 = 0x00000020, //filter in

            DECANTER_MAX           = 0x00000040, //set when filled
            GROUNDS_MAX            = 0x00000080, //
            WATER_MAX              = 0x00000100, //

            CHOCOLATE              = 0x00000200, //set when added
            VANILLA                = 0x00000400, //
            WHIPPED_CREAM          = 0x00000800, //
            HALF_AND_HALF          = 0x00001000, //

            MAX = 
              POWER | GROUNDS
            | WATER | FILTER | DECANTER_MAX | GROUNDS_MAX | WATER_MAX
            | CHOCOLATE | VANILLA | WHIPPED_CREAM | HALF_AND_HALF
        };

        //could be either signed or unsigned.
        mutable signed int _state = Flag::POWER;
        
        /* Private Member Functions */
        void _setFlag(const int& flag);
        void _removeFlag(const int& flag);
        void _addFlag(const int& flag);
        bool _hasFlag(const int& flag);
    };
};

#endif