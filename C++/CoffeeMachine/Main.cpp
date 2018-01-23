// ClassExercise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "CoffeeMachine.h"

int main()
{
	CoffeeMachine cherry(10, 5);

    cherry.brew();



    std::cout << "Should be... 0 and 15!\n" << std::endl;
        





	std::cin.get();
	std::cout << std::flush;
	return 0;
}

