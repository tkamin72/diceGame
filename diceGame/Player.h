#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <ctime>
#include"Cards.h"
using namespace std;
class Player{
	private: 
		string name;
		int score;
		int amountTurns;
		int ranking;
		int age;
		int level;
		float winnings;
		float betAmount;
		int highScore;
		int knockOut;
		//blackJack vars//
		int card1, card2;
		string type1, type2;
		
	public:						// make this look like its not for this game, make it work for any game
		//constructors//
		Player();
		Player(string);
		Player(string,int); //name and age//
		Player(string,int,int);//name, age, turns//
		Player(int, string);
		//***Constructor for blackjack***//
		Player (string,int,float,float); // name, age, winnigs, betAmount // 
		
		//functions for card 1//
		int getCardValue1();
		string getCardType1();
		void setCard1Value(int);
		//functions for card 2//
		int getCardValue2();
		string getCardType2();
		void setCard2Value(int);
		//common functions for both cards//
		void setCardValues(Cards);
		void setCardTypes(Cards);
		//Functions for winnings //
		void setWinnings(float);
		float getWinnings();
		float getBetAmount();
		
		// sets/gets
		//overloading: ranking / levels/ turns 
		
		
		// for practice put your objects in a vector( maybe have it in main ?)
		
};

#endif
