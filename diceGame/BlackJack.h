#ifndef BLACKJACK_H
#define BLACKJACK_H
#include "player.h"
#include "cards.h"
#include "dealerbj.h"

class BlackJack
{
	private:
		Cards cards;
		Player p1;
		DealerBj Dealer;	
	public:
		BlackJack(string ,int,float,float); //name, age, winnings, betamount// 
		Cards getCards();
		Player getPlayer();
		DealerBj getDealer();
};

#endif
