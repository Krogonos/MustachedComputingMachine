#ifndef __COFFEE_MACHINE_H__
#define __COFFEE_MACHINE_H__

namespace Coffee
{
	class CoffeeMachine
	{
	public: 
		CoffeeMachine() = default;

		/* Type Aliases */
		using cup = float;

		//Overload the fuck out of these, or just make templates.
		//CoffeeMachine& bool operator=(){}
		//bool operator==(){}
		//bool operator!=(){}
		//CoffeeMachine& operator+(){}
		//CoffeeMachine& operator-(){}
		//bool ++operator(){}
		//bool --operator(){}

		/* Public Member Functions */
		void BrewCoffee() const;           //Begin brewing coffee
		//void HaltBrew() const;             //Stop brewing coffee -- std::chrono
		void TurnOffMachine() const;       //Remove POWER flag.
		bool GetPowerState() const;        //Returns current power state - true is represents a presence of power, false otherwise.
		bool IsFull() const;               //Returns true if either LiquidInDecanter || LiquidInResevoir == FluidCapacity || CoffeeGrounds == GroundsCapacity
		bool HasWaterInResevoir() const;   //True if the resevoir isn't empty.
		bool HasCoffeeInDecanter() const;  //true if the decanter isn't empty.
		bool HasCoffeeGrounds() const;     //Returns true if the basin isn't empty.
		bool HasCoffeeFilter() const;      //Returns true if a coffee filter is in place
		
		inline cup GetCoffee() const { return Coffee; }
		inline cup GetCoffeeGrounds() const { return CoffeeGrounds; }

		/* Public Data Members */
		const cup FluidCapacity = 12.0f;
		const cup GroundsCapacity = 1.0f;
		cup LiquidInDecanter = 0.0f;
		cup LiquidInResevoir = 0.0f;
		cup CoffeeGrounds = 0.0f;
		cup Coffee = 0.0f;
		bool PoweredOn = false;
		bool CoffeeFilter = false;

	private:
		/* Private Data Members */
		enum Attributes
		{
			NONE                   = 0x00000000,
			POWER                  = 0x00000002, //If this flag is present there is power, otherwise there is not.
			WATER_IN_RESEVOIR      = 0x00000004, //If this flag is present there is liquid in the water resevoir
			COFFEE_GROUNDS         = 0x00000008, //If this flag is present there are coffee grounds in their basin, otherwise there is not.
			COFFEE                 = 0x00000010, //If this flag is present there is coffee!!! Otherwise, there is none.
			DECANTER_FILLED        = 0x00000020, //This flag is set when the Decanter is filled.
			WATER_RESERVIOR_FILLED = 0x00000040, //This flag is set when the water reservoir is filled.
			GROUNDS_BASIN_FILLED   = 0x00000080, //This flag is set if the coffee ground basin is filled.
			COFFEE_FILTER          = 0x00000100, //If this flag is present there is a coffee filter in place, otherwise there is not.
			FAILED                 = 0x00000200, //This flag is set if, for whatever reason, coffee is failed to be brewed.
			MAX                    = POWER | WATER_IN_RESEVOIR | WATER_RESERVIOR_FILLED
			                       | COFFEE_GROUNDS | COFFEE | DECANTER_FILLED
			                       | GROUNDS_BASIN_FILLED | COFFEE_FILTER | FAILED
		};

		/* Private Data Members */
		mutable unsigned int _state = NONE;

		/* Private Member Functions */
		//Member functions define within the class are implicitly inlined.
		void _setAttributes(const int& attris);
		void _removeAttributes(const int& attris);
		void _addAttributes(const int& attris);
		bool _hasAttributes(const int& attris) const;
	};
};



#endif
