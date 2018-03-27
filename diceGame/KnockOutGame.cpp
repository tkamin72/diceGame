#include "KnockOutGame.h"
#include <stdio.h>
#include <iomanip>
#include <ctime>
#include <iostream>
#include "Dice.h"
#include "Player.h"

KnockOutGame::KnockOutGame(int knockOut1, string name1):player1(knockOut1, name1)//, player2(knockOut2, name2) /*, int knockOut2, string name2*/
{
	one = Dice();
	two = Dice();
	
	
}

int KnockOutGame::roll(){
	one.roll();
	two.roll();
	int tot = (one.getValue() + two.getValue());
	return tot;
}
