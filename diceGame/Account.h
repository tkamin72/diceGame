#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <map>
#include "Person.h"
#include "date.h"


using namespace std;
class Account
{
	private :
		
		string userName, password;
		Person person;
		double accountBalance, depositeAmount;
		//ofstream ActivityLogger, credentialWriter; //this outputfile stream will be logging account activity in a text file--------The seconed outputfile stream will be writing credentials to the text file //
		ifstream AccountRegCheck ; // this will read input from a text where all usernames and passwords are logged too check if credentials are valid or nahh// 
		map <string,string> accounts;
		
		
	public :
		
		Account();
		Account(string, string, string, string , int , int , int , int, double, double);
		
		bool checkForUserValidate(string ,string); //checks if account is valid or not//
		void mainMenu(Account&);
		string getName();
		void createNewAcount();
		void loadExistingAccount(string,string);
		Account& operator=(Account);
		friend ostream& operator<<(ostream& out , Account& a){
			
			//out<<"\nFirst & Last Name : " << a.person.getFname()<<" "<<a.person.getLname();//accessing "Accounts" persons private data members through the reference to the Account
			//Date f = a.person.getDate();
			out<<"\n\nUsername          : " << a.userName;
			//out<<"\nName              : " << a.password;
			out<< a.person;
			//out<<"\nDate of Birth     : " <<f; //a.person.getDate(); //date ostream operator is already overloaded in the date class//
			//out<<"\nAcount ID #       : " << a.person.idNumber;
			out<<"\nAcount Balance      : " << a.accountBalance;
			return out;
		}
	
			
};
#endif
