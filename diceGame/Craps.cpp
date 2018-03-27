#include "Craps.h"
#include <stdio.h>
#include <iomanip>
#include <ctime>
#include <iostream>
#include "Dice.h"
#include "Player.h"

Craps::Craps(string name1, int age):player1(name1, age)//, player2(knockOut2, name2) /*, int knockOut2, string name2*/
{
	one = Dice();
	two = Dice();	
}

int Craps::roll(){
	one.roll();
	two.roll();
	int tot = (one.getValue() + two.getValue());
	return tot;
}

