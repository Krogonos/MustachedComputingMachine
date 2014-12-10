/*
* 
*
*
*/
#ifndef __COFFEE_MACHINE_H__
#define __COFFEE_MACHINE_H__

#include "Shared_Defines.h"
#include <iostream>
#include <string>
#include <cctype>

	class CoffeeMachine/*inheritance!!!! (container, input agent, attribute class, exception handling)*/
	{
	public:
		CoffeeMachine() = default;

		/*revisit constructors; function parameters*/
		explicit CoffeeMachine() : CoffeeMachine()
		{
			/*todo, get system time*/
			std::cout << "CoffeeMachine Constructor called: " << std::endl;

			//based on recieved input - set attributes accordingly
			/*if ()
			{

			}*/


		}

		/* Public Member Functions */
		inline float GetCoffee() const { return Coffee; }
		inline float GetCoffeeGrounds() const { return CoffeeGrounds; }
		bool HasCoffeeInCarafe();
		bool HasCoffeeGrounds();
		bool isPluggedIn();
		bool HasCoffeeFilter();

		/* Public Data Members */
		float ResevoirCapacity = 0.0f, CarafeCapacity = 0.0f, BasinCapacity = 0.0f;
		float CoffeeGrounds = 0.0f;
		float Coffee = 0.0f;
		float TotalWater = 0.0f;
		

	private:
		/* Private Data Members */ 
		enum Attributes
		{
			INOPERABLE                 = 0x00000001, //Inoperable
			POWER                      = 0x00000002, //If this flag is present there is power, otherwise there is not.
			WATER_IN_RESEVOIR          = 0x00000004, //If this flag is present there is water in the water resevoir
			COFFEE_GROUNDS             = 0x00000008, //If this flag is present there are coffee grounds in their basin, otherwise there is not.
			COFFEE                     = 0x00000010, //If this flag is present there is coffee!!! Otherwise, there is none.
			CARAFE_FILLED              = 0x00000020, //This flag is set when the carafe is filled.
			WATER_RESERVIOR_FILLED     = 0x00000040, //This flag is set when the water reservoir is filled.
			COFFEE_BASIN_FILLED        = 0x00000080, //This flag is set if the coffee ground basin is filled.
			COFFEE_FILTER              = 0x00000100, //If this flag is present there is a coffee filter in place, otherwise there is not.
			FAILED                     = 0x00000200, //This flag is set if, for whatever reason, coffee is failed to be brewed.
			//Attribute status codes - NOT ATTRIBUTES!
			ASC_EMPTY          =  0x00000000,
			ASC_NULL           = -0x00000001,
			ASC_ALL_ATTRIBUTES = INOPERABLE | POWER | WATER_IN_RESEVOIR | WATER_RESERVIOR_FILLED
			                   | COFFEE_GROUNDS | COFFEE | CARAFE_FILLED
			                   | COFFEE_BASIN_FILLED | COFFEE_FILTER | FAILED
		};//End Attributes

		//_state must always be able to change...?
		mutable unsigned int _state = ASC_EMPTY;

		void _setAttributes(const int& attris) { _state = attris; return; }
		void _removeAttributes(const int& attris);
		void _addAttributes(const int& attris);
		bool _hasAttributes(const int& attris) const;
	};//End CoffeeMachine

	//We can't ever check if the object has ASC_EMPTY set... it'll break things.
	bool CoffeeMachine::_hasAttributes(const int& attris = 0) const
	{
		//no args: true if _state is nonzero, false otherwise.
		if (!attris)
			return (_state ? true : false);

		//check range
		if (attris > ASC_ALL_ATTRIBUTES || attris < ASC_NULL)
			return false;

		//true if we have the flags present, false otherwise.
		return (_state & attris ? true : false);
	}

	void CoffeeMachine::_removeAttributes(const int& attris)
	{
		//If no attributes are set, why bother checking the object for the attribute provided?
		if (_hasAttributes())
			if (_hasAttributes(attris))
			_state &= ~attris;

		return;
	}

	/*One may only change an objects attribute status to ASC_NULL explicitly via the _SetAttribute function*/
	void CoffeeMachine::_addAttributes(const int& attris)
	{
		//If attribute is already present, continue.
		if (_hasAttributes(attris))
			return;

		_state |= attris;
		return;
	}
#endif