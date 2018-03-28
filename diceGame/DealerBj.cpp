#include "DealerBj.h"
#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;

//default constructor//
DealerBj::DealerBj(){ }

//class functions//
void DealerBj::setCardValues(Cards f){
	srand(time(0));
	card = f.getCardValue();
	holeCard = f.getCardValue();
	}

void DealerBj::setCardTypes(Cards g){
	type = g.getCardType();
	holeType = g.getCardType();
	}

int DealerBj::getCard(){return card;}

int DealerBj::getHoleCard(){return holeCard;}

string DealerBj::getType(){return type;}

string DealerBj::getHoleType(){return holeType;}

void DealerBj::setCard1Value(int val){val =card;}

void DealerBj::setHoleCardValue(int valu){valu = holeCard;}

string DealerBj::getDummy(){return holeDummy;}

void DealerBj::setInsurance(bool insurance){this->insurance = insurance;}

bool DealerBj::getInsurance(){return insurance;}
