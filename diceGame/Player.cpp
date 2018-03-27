#include "Player.h"
#include "Dice.h"
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <ctime>

//Default constructor//
Player::Player(){}
///////////////////////
Player::Player(string name)
{
	this->name=name;
}

Player::Player(string name, int age)
{
	this->name=name;
	this->age=age;
}
Player::Player(string name, int age, int amountTurns)
{
	this->name=name;
	this->age=age;
	this->amountTurns=amountTurns;
}
Player::Player(int knockOut, string name)
{
	this->knockOut=knockOut;
	this->name=name;
}

//Constructor for black jack//
Player::Player(string name, int age, float winnings, float betAmount){
	this->name = name;
	this->age = age;
	this->winnings = winnings;
	this->betAmount = betAmount;

	}
//class funtions used in black jack//
void Player::setCardValues(Cards k){ 
	card1 = k.getCardValue();			//gets a random number from the card deck vector in the cards class and assignss it to the card eachtime//
	card2 = k.getCardValue();
	}

void Player::setCardTypes(Cards n ){ // assigning types of card //
		type1=n.getCardType();
		type2=n.getCardType();
	}

int Player::getCardValue1(){return card1;}

string Player::getCardType1(){return type1;}		//getting cards point values and types //

int Player::getCardValue2(){return card2;}

string Player::getCardType2(){return type2;}

//winnings accessors and mutators//
void Player::setWinnings(float winnings){this->winnings = winnings;}

float Player::getWinnings(){return winnings;}

void Player::setCard1Value(int val){val = card1;}

void Player::setCard2Value(int valu){valu = card2;}

float Player::getBetAmount(){return betAmount;}




