// ClassExercise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "CoffeeMachine.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Coffee::CoffeeMachine mymachine;


	std::cout << "Press any key to continue..." << std::endl;
	std::cin.get();
	std::cout << std::flush;
	return 0;
}

