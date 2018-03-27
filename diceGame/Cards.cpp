#include "Cards.h"
#include <ctime>
#include <iostream>
#include <iomanip>
#include <vector>
#include <conio.h>
using namespace std;


Cards::Cards(){
	
	cardType[0]="Diamonds";
	cardType[1]="Spades";
	cardType[2]="Cloves";		
	cardType[3]="Hearts";
	
	for(int c=1 ; c<14; c++){
		
		diamonds[c-1]=c;
		hearts[c-1]=c;
		spades[c-1]=c;
		cloves[c-1]=c;
		
	}
	
		
		cardDeck.insert( cardDeck.begin() , diamonds , diamonds + 13 ) ;
		cardDeck.insert( cardDeck.begin() , hearts , hearts + 13 ) ;
		cardDeck.insert( cardDeck.begin() , cloves , cloves + 13 ) ;		//Passing all array contents into a vector// this is the actual deck of cards used in the game//
		cardDeck.insert( cardDeck.begin() , spades , spades + 13 ) ;
	
}//end of constructor//

int Cards::getCardValue(){ return  cardDeck[(rand() % cardDeck.size() + 1)];} // just generating a random between 1-52 in the vectors index

string Cards::getCardType(){return  cardType[(rand() % 3 + 1)];} //random number for card type//



ostream& operator<<(ostream& out, Cards& c){ // test purposes//
	for(int r=0; r<52;r++){
		
		out<<"\n"<<c.cardDeck.at(r);
		
		}


	return out;
	}
	
