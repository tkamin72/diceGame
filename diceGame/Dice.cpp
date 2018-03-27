#include "Dice.h"
#include "Player.h"
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <ctime>
Dice ::Dice(){
	srand(time(0));
	value=  rand() % 6 + 1;
}

void Dice::roll(){
	//srand(time(0));
	value= rand() % 6 + 1;
}

int Dice::getValue(){return value;}

