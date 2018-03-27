#ifndef DICE_H
#define DICE_H
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <ctime>
class Dice{
	private: 
		int value;
	
	public: 
		Dice();
		void roll();
		int getValue();
	
};
#endif
