#ifndef CRAPS_H
#define CRAPS_H
#include <stdio.h>
#include <iomanip>
#include <ctime>
#include <iostream>
#include "Dice.h"
#include "Player.h"


class Craps
{
		private:
		Dice one;
		Dice two;
		Player player1;
		//Player player2;

	public:
		Craps(string name1, int age);
		int roll();
};

#endif

