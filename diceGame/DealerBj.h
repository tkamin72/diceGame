#ifndef DEALERBJ_H
#define DEALERBJ_H
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include "cards.h"
using namespace std;

class DealerBj
{	
	private:
		int card, holeCard;//(HOLE CARD IS FACED DOWN WHEN PLAYING, these are the dealers cards)//
	    string holeDummy = "XXXX"; //(This is what is displayed for the point value and type of card when the hole card is faced down before the results)
		string type, holeType;
		bool insurance; //dealers may offer insurance, if the player takes the insurance and hits bj, then they get double the payout, else the dealer wins//
		
		
		
		
	public:
		DealerBj();
		void setCardValues(Cards); //sets card1 point val//
		int getHoleCard();//  //  // // // //
		void setCardTypes(Cards);// sets type of card//
		string getHoleType();
		int getCard();
		string getType();
		string getDummy(); //this gets the dummy display for when the hole card is down//
		void setInsurance(bool);
		bool getInsurance();
		void setCard1Value(int);
		void setHoleCardValue(int);


};

#endif
