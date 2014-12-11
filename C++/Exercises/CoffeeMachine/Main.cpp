// ClassExercise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "CoffeeMachine.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Coffee::CoffeeMachine mymachine;

	for (const auto& i : mymachine.Decanter)
		std::cout << i;
	std::cout << std::endl;

	std::cout << "Press any key to continue..." << std::endl;
	std::cin.get();
	std::cout << std::flush;
	return 0;
}

