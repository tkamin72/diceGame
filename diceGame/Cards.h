#ifndef CARDS_H
#define CARDS_H
#include <vector>
#include <iostream>
#include <iomanip>
#include <vector>
#include <conio.h>
using namespace std;

class Cards
{
	private:
		
		
		int hearts [13];
		int spades[13];
		int diamonds [13];
		int cloves[13];
		vector<int> cardDeck;
		string cardType[4];
		
	
	public:

		Cards();
		
		friend ostream& operator<<(ostream&, Cards&); // this is for test puposes//
		int getCardValue(); // gets card value, using it in blackjack to set card values for both player and dealer // 
		string getCardType();//gets a random type, using it // // // // //

	};
	
#endif
