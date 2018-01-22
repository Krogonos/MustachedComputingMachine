#ifndef _Coffee_MACHINE_H__
#define _Coffee_MACHINE_H__

#include <iostream>
#include "stdafx.h"

namespace Coffee
{

    class CoffeeMachine
    {
    public:
		//can the synthesized default constructor initialize a signed integer to a below zero value?
        CoffeeMachine() = default;

		bool brew() const;
        bool togglePower() const;
		void addSpecial(const int&);
		
		enum Specials
		{
			/*Specials*/
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
			/*Status*/
			NULL_STATUS      = 0x00000000,
			BLACK		     = 0x00000001,

            POWER            = 0x00001000, //
            GROUNDS          = 0x00002000, //
            WATER            = 0x00004000, //
			COFFEE           = 0x00008000,
            FULL_DECANTER    = 0x00010000, //
            FULL_GROUNDS     = 0x00020000, //
			FULL_WATER       = 0x00040000, //

            MAX_FLAGS = 
		        MAX_SPECIAL |
                BLACK | POWER | GROUNDS | COFFEE | WATER |
			    FULL_DECANTER | FULL_GROUNDS | FULL_WATER
        };
		
		mutable signed int _flags = Status::NULL_STATUS;

        /* Private Member Functions */
        void _setFlag(const int& flag);
        void _removeFlag(const int& flag);
        void _addFlag(const int& flag);
		bool _hasFlag(const int& flag) const;
    };
};

#endif