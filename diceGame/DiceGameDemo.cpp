#include <stdio.h>
#include <iomanip>
#include <ctime>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "Dice.h"
#include "Player.h"
#include "KnockOutGame.h"
#include "Cards.h"
#include "Craps.h"
#include "BlackJack.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	//Objects used for BlackJack game//
	Player BlackJackPlayer;
	DealerBj Dealer;
	Cards Cards;
	int card3, card3D;
	string type3, type3D;
	char ans='y';
	bool third=false;
	bool thirdDealer=false;
	/////////////////////////////////////
	int choice,totalDealer, totalPlayer;
	float betAmount, winnings=0;
	int age;
	int v;
	char again;
	string name1;
	cout<<"Please enter your name: ";
	cin>>name1;
	cout<<"\nPlease enter your age: ";
	cin>>age;
	cout<<"Please select the game you wish to play:\n";
	cout<<"Age 21 and over:\n"<<"1) Black Jack\n"<<"2) Craps";
	cout<<"\n\nUnder 21:\n"<<"3) Knock Out Game\n";
	cout<<"Please choose your game: ";
	cin>>choice;
 
 	
	switch(choice)
	{
		case 1:
		{
			if(age>=21){
			
			
			while(ans=='y'){
				ans='n';
				cout<<"*********************************************************\n";
				cout<<"******************--Welcome to Black Jack--******************\n";
				cout<<"*********************************************************\n";
				cout <<"\nEnter your bet amount : $ ";
				cin>>betAmount;
				
				BlackJack blackJack(name1,age,winnings,betAmount); //blackjack constructor//
				BlackJackPlayer = blackJack.getPlayer();	//player//				
				Cards = blackJack.getCards();			//cards//
				Dealer = blackJack.getDealer(); 	 //dealer//
				
				Dealer.setCardValues(Cards);
				Dealer.setCardTypes(Cards);
				
				BlackJackPlayer.setCardTypes(Cards);//setting players card types//
				BlackJackPlayer.setCardValues(Cards);//setting players card values//
				
				
				cout<<"\nPlease press Z to recieve a card"; // need to set condition and validate // 
				getch();
				
				//EVERYTHING HERE THATS A COUT NEEDS FORMATTING//
				
				//Displaying the recieved cards // 
				cout<<"\n\n"<<setw(20)<<"Dealers Cards "<<setw(15)<<name1<<"'s Cards";	
				cout<<"\n"<<setw(10)<<Dealer.getCard() <<" "<<Dealer.getType()  <<setw(17)<<  BlackJackPlayer.getCardValue1()<<" "<<BlackJackPlayer.getCardType1();
				cout<<"\nPress Z again to recieve a seconed card";
				getch();
				//Re-Displaysthe top 2 lines (ln 69 & 70)
				cout<<"\n\n"<<setw(20)<<"Dealers Cards "<<setw(15)<<name1<<"'s Cards";	
				cout<<"\n"<<setw(10)<<Dealer.getCard() <<" "<<Dealer.getType()  <<setw(17)<<  BlackJackPlayer.getCardValue1()<<" "<<BlackJackPlayer.getCardType1();
				cout<<"\n"<<setw(10)<<Dealer.getDummy()<<" "<<Dealer.getDummy()<<setw(17)<<   BlackJackPlayer.getCardValue2()<<" "<<BlackJackPlayer.getCardType2();
				
				cout<<"\nPress Z again to display Dealers Hole Card";
				getch();
				//Re-displaying lns 74 thru 76 (with the hole card value and type)//
				cout<<"\n\n"<<setw(20)<<"Dealers Cards "<<setw(15)<<name1<<"'s Cards";	
				cout<<"\n"<<setw(10)<<Dealer.getCard() <<" "<<Dealer.getType()  <<setw(17)<<  BlackJackPlayer.getCardValue1()<<" "<<BlackJackPlayer.getCardType1();
				cout<<"\n"<<setw(10)<<Dealer.getHoleCard()<<" "<<Dealer.getHoleType()<<setw(17)<<   BlackJackPlayer.getCardValue2()<<" "<<BlackJackPlayer.getCardType2();
					//These are retrictions for the ace card swapping to a value of 11 for BOTH the deler and player //	
					if (Dealer.getHoleCard() == 1 && Dealer.getCard()>=10){
						Dealer.setHoleCardValue(11);
						Dealer.setCard1Value(10);
						
					}
					else if(Dealer.getCard() == 1 && Dealer.getHoleCard()>=10){
						Dealer.setCard1Value(11);
						Dealer.setHoleCardValue(10);
						
					}
					else if (Dealer.getCard()==1 && Dealer.getHoleCard()<10){
						
						Dealer.setCard1Value(11);
					}
					else if (Dealer.getHoleCard()==1 && Dealer.getCard()<10){
						
						Dealer.setHoleCardValue(11);
					}
						//Player conditions // 
					if (BlackJackPlayer.getCardValue1()== 1 && BlackJackPlayer.getCardValue2()>=10){
						BlackJackPlayer.setCard1Value(11);
						BlackJackPlayer.setCard2Value(10);
						
					}
					else if(BlackJackPlayer.getCardValue2()== 1 && BlackJackPlayer.getCardValue1()>=10){
						BlackJackPlayer.setCard1Value(10);
						BlackJackPlayer.setCard2Value(11);
						
					}
					else if (BlackJackPlayer.getCardValue1()== 1 && BlackJackPlayer.getCardValue2()<10){
						
						BlackJackPlayer.setCard1Value(11);
						
					}
					else if (BlackJackPlayer.getCardValue2()== 1 && BlackJackPlayer.getCardValue1()<10){
						
						BlackJackPlayer.setCard2Value(11);
					}
				
					totalDealer = Dealer.getCard() + Dealer.getHoleCard();
					totalPlayer = BlackJackPlayer.getCardValue1() + BlackJackPlayer.getCardValue2();
					//Incase one of the players have a total that is lt 21// makes a third card//
				/*	if(totalPlayer<21){
						cout<<"\n\n"<<name1<<"'s Cards";	
						cout<<"\n"<<setw(10)<<BlackJackPlayer.getCardValue1()<<" "<<BlackJackPlayer.getCardType1();
						cout<<"\n"<<setw(10)<<BlackJackPlayer.getCardValue2()<<" "<<BlackJackPlayer.getCardType2();
						cout<<"\nPress Z to draw another Card or press any other key to continue";
						cin.ignore(1);
						if(getch()==122 || getch()==90){
							card3 = Cards.getCardValue();
							type3 = Cards.getCardType();
							cout<<"\nYou Drew a "<<card3<<" "<<type3;
							totalPlayer += card3;
							//its exiting here//
						}
					}*/
				/*	else if (totalDealer<21){
						
						cout<<"\n\nDealer's Cards";	
						cout<<"\n"<<setw(10)<<Dealer.getCard()<<" "<<Dealer.getType();
						cout<<"\n"<<setw(10)<<Dealer.getHoleCard()<<" "<<Dealer.getHoleType();
						cout<<"\n"<<setw(10)<<"Card drawn by dealer :"<<card3D<<" "<<type3D;
						card3D = Cards.getCardValue();
						type3D = Cards.getCardType();
						totalDealer += card3D;
					}*/
					
					//modded from here and below//
					
					if ((totalPlayer == 21 && totalDealer >21) || (totalPlayer==21 && totalDealer <21)){
						//float c = (BlackJackPlayer.getBetAmount());
						cout<<"!!!--YOU HIT BLACK JACK--!!!";
						BlackJackPlayer.setWinnings(  BlackJackPlayer.getBetAmount() * 1.5);//pays out (1.5 * the betamount) if player wins//
						cout<<"Payout : "<<betAmount<<" x 1.5";
						cout<<"--------------------------------";
						cout<<"$ "<<BlackJackPlayer.getWinnings();
					}
						//if player wins//
					else if((totalDealer == 21 && totalPlayer >21) || (totalDealer==21 && totalPlayer <21)){
						
						cout<<"<--Dealer Hit Black Jack-->";
						BlackJackPlayer.setWinnings(BlackJackPlayer.getBetAmount() - (BlackJackPlayer.getBetAmount() /3));	//lose 1/3 of bet amount if lose//
						cout<<"Lost Amount : "<<betAmount<<" - "<<(BlackJackPlayer.getBetAmount()/3);
						cout<<"--------------------------------";
						cout<<"$ "<<BlackJackPlayer.getWinnings();
					}
					else if (totalDealer<21 || totalPlayer <21){
						if(totalPlayer<21){
						cout<<"\n\n"<<name1<<"'s Cards";	
						cout<<"\n"<<setw(10)<<BlackJackPlayer.getCardValue1()<<" "<<BlackJackPlayer.getCardType1();
						cout<<"\n"<<setw(10)<<BlackJackPlayer.getCardValue2()<<" "<<BlackJackPlayer.getCardType2();
						cout<<"\nPress Z to draw another Card or press any other key to continue";
						cin.ignore(1);//cLEARING BUFFER
						if(getch()==122 || getch()==90){
							third = true;
							card3 = Cards.getCardValue();
							type3 = Cards.getCardType();
							cout<<"\nYou Drew a "<<card3<<" "<<type3;
							totalPlayer += card3;
						
						}//end of 2nd if
						
						
					}//end of if
					if (totalDealer<21){
						thirdDealer=true;
						cout<<"\n\nDealer's Cards";	
						cout<<"\n"<<setw(10)<<Dealer.getCard()<<" "<<Dealer.getType();
						cout<<"\n"<<setw(10)<<Dealer.getHoleCard()<<" "<<Dealer.getHoleType();
						cout<<"\n"<<setw(10)<<"Card drawn by dealer :"<<card3D<<" "<<type3D;
						card3D = Cards.getCardValue();
						type3D = Cards.getCardType();
						totalDealer += card3D;
						
						if(totalDealer==21 ){
							if(thirdDealer==true){
								
								cout<<"\n\nDealer's Cards";	
								cout<<"\n"<<setw(10)<<Dealer.getCard()<<" "<<Dealer.getType();
								cout<<"\n"<<setw(10)<<Dealer.getHoleCard()<<" "<<Dealer.getHoleType();
								cout<<"\n"<<setw(10)<<card3D<<" "<<type3D;
							}
							
							else{
									cout<<"\n\nDealer's Cards";	
									cout<<"\n"<<setw(10)<<Dealer.getCard()<<" "<<Dealer.getType();
									cout<<"\n"<<setw(10)<<Dealer.getHoleCard()<<" "<<Dealer.getHoleType();
								
							}
								
							if (third==true){
							cout<<"\n\n"<<name1<<"'s Cards";	
							cout<<"\n"<<setw(10)<<BlackJackPlayer.getCardValue1()<<" "<<BlackJackPlayer.getCardType1();
							cout<<"\n"<<setw(10)<<BlackJackPlayer.getCardValue2()<<" "<<BlackJackPlayer.getCardType2();
							cout<<"\n"<<setw(10)<<card3<<" "<<type3;	
							}
							else{
								cout<<"\n\n"<<name1<<"'s Cards";	
								cout<<"\n"<<setw(10)<<BlackJackPlayer.getCardValue1()<<" "<<BlackJackPlayer.getCardType1();
								cout<<"\n"<<setw(10)<<BlackJackPlayer.getCardValue2()<<" "<<BlackJackPlayer.getCardType2();
							}
							
						
							cout<<"\n<--Dealer Hit Black Jack-->";
							BlackJackPlayer.setWinnings(BlackJackPlayer.getBetAmount() - (BlackJackPlayer.getBetAmount() /3));	//lose 1/3 of bet amount if lose//
							cout<<"\nLost Amount : "<<betAmount<<" - "<<(BlackJackPlayer.getBetAmount()/3);
							cout<<"--------------------------------";
							cout<<"\n$ "<<BlackJackPlayer.getWinnings();	
							}
							else if (totalPlayer==21){
								if(thirdDealer==true){
								
								cout<<"\n\nDealer's Cards";	
								cout<<"\n"<<setw(10)<<Dealer.getCard()<<" "<<Dealer.getType();
								cout<<"\n"<<setw(10)<<Dealer.getHoleCard()<<" "<<Dealer.getHoleType();
								cout<<"\n"<<setw(10)<<card3D<<" "<<type3D;
							}
							
							else{
									cout<<"\n\nDealer's Cards";	
									cout<<"\n"<<setw(10)<<Dealer.getCard()<<" "<<Dealer.getType();
									cout<<"\n"<<setw(10)<<Dealer.getHoleCard()<<" "<<Dealer.getHoleType();
								
							}
								
							if (third==true){
							cout<<"\n\n"<<name1<<"'s Cards";	
							cout<<"\n"<<setw(10)<<BlackJackPlayer.getCardValue1()<<" "<<BlackJackPlayer.getCardType1();
							cout<<"\n"<<setw(10)<<BlackJackPlayer.getCardValue2()<<" "<<BlackJackPlayer.getCardType2();
							cout<<"\n"<<setw(10)<<card3<<" "<<type3;	
							}
							else{
								cout<<"\n\n"<<name1<<"'s Cards";	
								cout<<"\n"<<setw(10)<<BlackJackPlayer.getCardValue1()<<" "<<BlackJackPlayer.getCardType1();
								cout<<"\n"<<setw(10)<<BlackJackPlayer.getCardValue2()<<" "<<BlackJackPlayer.getCardType2();
							}
							cout<<"\n!!!--YOU HIT BLACK JACK--!!!";
							BlackJackPlayer.setWinnings(  BlackJackPlayer.getBetAmount() * 1.5);//pays out (1.5 * the betamount) if player wins//
							cout<<"\nPayout : "<<betAmount<<" x 1.5";
							cout<<"\n--------------------------------";
							cout<<"\n"<<BlackJackPlayer.getWinnings();
								
								
								
							}//before this
					}
					
						
					}//end of else if
					cout<<"wanna go again?";
					cin>>ans;
				
				}
				
					
			
			}//case 1
			else
			{
				cout<<"I'm sorry you didn't meet the minimum age requirements of 21 years old!";
			}
			break;
		}
		case 2:
        {
            if(age>=21)
            {
                system("cls");
                cout<<"\n\n\n\n";
                cout<<setw(90)<<"*********************************************************\n";
                cout<<setw(90)<<"******************--Welcome to Craps!--******************\n";
                cout<<setw(90)<<"*********************************************************\n";
                cout<<setw(90)<<"************************--Rules--************************\n";
                cout<<setw(90)<<"****--Each round has two phases: Come Out and Point--****\n";
                cout<<setw(90)<<"*****--In the come out phase if you roll a 7 or 11--*****\n";
                cout<<setw(90)<<"**************--you are a natural winner!--**************\n";
                cout<<setw(90)<<"**********--if you roll a 2, 3 or 12 you lose--**********\n";
                cout<<setw(90)<<"*********************************************************\n";
                cout<<setw(90)<<"********--In the point phase if roll a match--***********\n";
                cout<<setw(90)<<"***********************--You Win!--**********************\n";
                cout<<setw(90)<<"***************--if you roll a 7 you lose--**************\n";
                cout<<setw(90)<<"************--You will continue to roll until--**********\n";
                cout<<setw(90)<<"*****************--you match or roll a 7--***************\n";
                cout<<setw(90)<<"*********************************************************\n";
                cout<<setw(90)<<"********************--Enjoy the Game!--******************\n";
                cout<<setw(90)<<"*********************************************************\n";
                cout<<setw(82)<<"Press double tap the space bar to continue!";
                do
                {
                    if(getch()==32)
                    {
                        system("cls");
                    }
                    else
                    {
                        cout<<"You didn't press the space bar!";
                    }
                }while(getch()!=32);
                do
                {
                    Craps game(name1, age);
                    cout<<"\nCome Out Phase: Please press the space bar to roll\n";
                    if(getch()==32) 
                    {
                        
                        v = game.roll();
                        cout<<"You rolled "<<v;
                        if(v==7 || v==11)
                        {
                            cout<<"\nYou are a natural winner!\n";
                        }
                        else if(v==2 || v==3 || v==12)
                        {
                            cout<<"\nYou Crapped Out!\n";
                        }
                        else
                        {
                            int x=0;
                            do
                            {
                                cout<<"\nPoint Phase: Please press the space bar to roll again\n";
                                x = game.roll();
                                if(getch()==32)
                                {
                                    if(x==v)
                                    {
                                        cout<<"\nYou rolled a match and are a winner!\n";
                                    }
                                    else if(x==7)
                                    {
                                        cout<<"\nYou rolled a 7 and lost!\n";
                                    }
                                    else
                                    {
                                        cout<<"You rolled "<<x<<" match is "<<v;
                                    }
                                }
                                else
                                {
                                    
                                    cout<<"\nYou did not strike the space bar!";
                                }
                            }while(x!=v && x!=7);
                        }   
                    }
                    else
                    {
                        cout<<"\nYou did not strike space bar!";
                    }
                    cout<<"\n\nWould you like to play again Y or N? ";
                    cin>>again;
                }while(again=='y' || again=='Y');
                cout<<"\n\nThank You for playing!\n";
            }
            else
            {
                cout<<"I'm sorry you didn't meet the minimum age requirements of 21 years old!";
            }
            break;
        }
		case 3:
		{
			int knockOut1;
			string name2;
			int knockout2;
			cout<<"*********************************************************\n";
			cout<<"******************Welcome to Knock Out!******************\n";
			cout<<"*********************************************************\n";
			cout<<"Player 1:\n";
			cout<<"Please enter your knockout number (6, 7, 8 or 9): ";
			cin>>knockOut1;
			
			//	cout<<"Player 2";
			//	cout<<"Please enter your knockout number (6, 7, 8 or 9)";
			//	cin>>knockout2;
			//	cout<<"Please enter your name: ";
			//	cin>>name2;
			//Player player1(name);
			//Dice d; // dice// 
			//d.roll(); // roll function for dice obj//
			//cout<<d.getValue();
			KnockOutGame game(knockOut1, name1);
			//	cout<<"Please press the Z key to roll ";
			//	cin>>v;
			//	if(v==132 || v==172)
			//	{
			//		game.roll();
			//	}
			//cout<<knockOut1;//test//
			cout<<"\nPlease press the Z key to roll\n";
	
			while(getch()==122 || getch()==90)
			{
		
		 		v = game.roll();
				cout<<"\n|Your roll was : "<<v<<" | KnockOut Number : "<<knockOut1;
		
				if(v==knockOut1)
				{
					cout<<"\nMatch";
					break;
				}
				else{
					cout<<"\n|Not a Match ; Re-roll| ";
				}
			}
			cout<<"|!!!YOU HIT THE KNOCKOUT NUMBER!!!|";
		}
	
	return 0;
}
}
