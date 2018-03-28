#include "BlackJack.h"
#include "player.h"
#include "cards.h"
#include "dealerbj.h"


// Black Jack Constructor constructor//
BlackJack::BlackJack(string nm, int age, float win, float bet):p1(nm,age,win,bet),cards(),Dealer(){
	srand(time(0));
	p1.setCardValues(cards); //setting player one card values// 
	p1.setCardTypes(cards) ; // setting card types// 
	
	Dealer.setCardValues(cards);//setting dealers cards (both the faceup card and the holecard)
	Dealer.setCardTypes(cards);//setting card types//
	Dealer.setInsurance(false); // player will be asked if they want insurance at apporpiate time//
	

	}
	
	
	Cards BlackJack::getCards(){return cards;}
	Player BlackJack::getPlayer(){return p1;}
	DealerBj BlackJack::getDealer(){return Dealer;}




