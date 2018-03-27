#ifndef KNOCKOUTGAME_H
#define KNOCKOUTGAME_H
#include <stdio.h>
#include <iomanip>
#include <ctime>
#include <iostream>
#include "Dice.h"
#include "Player.h"

class KnockOutGame
{
	private:
		Dice one;
		Dice two;
		Player player1;
		//Player player2;

	public:
		KnockOutGame(int knockout1, string name1);//, int knockout2, string name2);
		int roll();
};

#endif
