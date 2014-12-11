#ifndef __COFFEE_MACHINE_H__
#define __COFFEE_MACHINE_H__

class CoffeeMachine
{
public:
	//Explicitly ask the compiler to generate a default constructor for us; This only works because this class is considered trivial.
	CoffeeMachine() = default;
	CoffeeMachine() : CoffeeMachine()
	{

	}

	/* Public Member Functions */
	//Overload the fuck out of these, or just make templates.
	//CoffeeMachine& bool operator=(){}
	//bool operator==(){}
	//bool operator!=(){}
	//CoffeeMachine& operator+(){}
	//CoffeeMachine& operator-(){}
	//bool ++operator(){}
	//bool --operator(){}

	inline float GetCoffee() const { return Coffee; }
	inline float GetCoffeeGrounds() const { return CoffeeGrounds; }
	bool HasCoffeeFilter();
	bool HasCoffeeInDecanter();
	bool HasCoffeeGrounds();
	bool HasPower();
	bool HasCoffeeFilter();

	/* Public Data Members */
	float ResevoirCapacity = 12.0f, DecanterCapacity = 12.0f, BasinCapacity = 0.0f;
	float CoffeeGrounds = 0.0f;
	float Coffee = 0.0f;
	float TotalWater = 0.0f;

private:
	/* Private Data Members */ 
	enum Attributes
	{
		INOPERABLE                 = 0x00000001, //Inoperable
		POWER                      = 0x00000002, //If this flag is present there is power, otherwise there is not.
		WATER_IN_RESEVOIR          = 0x00000004, //If this flag is present there is liquid in the water resevoir
		COFFEE_GROUNDS             = 0x00000008, //If this flag is present there are coffee grounds in their basin, otherwise there is not.
		COFFEE                     = 0x00000010, //If this flag is present there is coffee!!! Otherwise, there is none.
		Decanter_FILLED            = 0x00000020, //This flag is set when the Decanter is filled.
		WATER_RESERVIOR_FILLED     = 0x00000040, //This flag is set when the water reservoir is filled.
		COFFEE_BASIN_FILLED        = 0x00000080, //This flag is set if the coffee ground basin is filled.
		COFFEE_FILTER              = 0x00000100, //If this flag is present there is a coffee filter in place, otherwise there is not.
		FAILED                     = 0x00000200, //This flag is set if, for whatever reason, coffee is failed to be brewed.
		//Attribute status codes
		ASC_EMPTY          =  0x00000000,
		ASC_NULL           = -0x00000001,
		ASC_ALL_ATTRIBUTES = INOPERABLE | POWER | WATER_IN_RESEVOIR | WATER_RESERVIOR_FILLED
		                   | COFFEE_GROUNDS | COFFEE | Decanter_FILLED
		                   | COFFEE_BASIN_FILLED | COFFEE_FILTER | FAILED
	};

	/* Private Data Members */
	mutable unsigned int _state = ASC_EMPTY;

	/* Private Member Functions */
	//Member functions define within the class are implicitly inlined.
	inline void _setAttributes(const int& attris) { _state = attris; return; }
	void _removeAttributes(const int& attris);
	void _addAttributes(const int& attris);
	bool _hasAttributes(const int& attris) const;
};

bool CoffeeMachine::_hasAttributes(const int& attris = 0) const
{
	if (!attris)
		return (_state ? true : false);

	if (attris > ASC_ALL_ATTRIBUTES || attris < ASC_NULL)
		return false;
	return (_state & attris ? true : false);
}

void CoffeeMachine::_removeAttributes(const int& attris)
{
	if (_hasAttributes())
		if (_hasAttributes(attris))
		_state &= ~attris;
	return;
}

void CoffeeMachine::_addAttributes(const int& attris)
{
	if (_hasAttributes(attris))
		return;
	_state |= attris;
	return;
}
#endif