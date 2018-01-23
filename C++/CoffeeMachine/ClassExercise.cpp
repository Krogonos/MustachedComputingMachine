// ClassExercise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "CoffeeMachine.h"

int main()
{
	CoffeeMachine lol(5, 5);

    lol.brew();


    std::cout << lol.coffee << std::endl;
	std::cin.get();
	std::cout << std::flush;
	return 0;
}

