#include "CoffeeMachine.h"

//1) If no argument is provided, return true if the object has any attributes set
//2) If nonzero value has been passed to this function, check bounds
//3) Within expected range, return true if the object has the attribute(s) provided
bool Coffee::CoffeeMachine::_hasAttributes(const int& attris = 0) const
{
	if (!attris)
		return (_state ? true : false);

	if (attris <= Coffee::CoffeeMachine::Attributes::NONE || attris > Coffee::CoffeeMachine::Attributes::MAX)
		return false;

	return (_state & attris ? true : false);
} 

//1) Before removing attributes, check if the object has any to remove first.
//2) Then check if the object has the attribute(s) provided.
void Coffee::CoffeeMachine::_removeAttributes(const int& attris)
{
	if (_hasAttributes())
		if (_hasAttributes(attris))
			_state &= ~attris;
	return;
}

//1) Check if the object already has provided attribute(s)
void Coffee::CoffeeMachine::_addAttributes(const int& attris)
{
	if (_hasAttributes(attris))
		return;
	_state |= attris;
	return;
}

//1) Check range - make sure it's a flag.
void Coffee::CoffeeMachine::_setAttributes(const int& attris)
{ 
	if (attris > Coffee::CoffeeMachine::Attributes::MAX || attris < Coffee::CoffeeMachine::Attributes::NONE || !(attris % 2))
		return;

	_state = attris;
	return;
}