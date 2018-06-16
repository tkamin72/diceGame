#include <iostream>
#include <windows.h>
#include <sstream>
#include "Account.h"
#include "date.h"
#include "person.h"

using namespace std;

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Account::Account(){
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Account::Account(string userName, string password, string fname , string lname, int dd , int mm , int yy ,int idnum, double depositeAmount, double accountBalance=0):person(fname,lname,dd,mm,yy,idnum){
		//acountNmber=230;
		this->userName=userName;
		this->password=password;
		this->depositeAmount=depositeAmount;
		if(depositeAmount !=0)
			accountBalance=depositeAmount;	
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//account validation//

string Account::getName(){return userName;}

bool Account::checkForUserValidate(string user, string pass){
	string usr, psw,line, login= "Logging in, Please Wait . . . ."; //used to read first and seconed fields of Account registration file (Accounts.txt) 
	string k,l,m,n;
	AccountRegCheck.open("Accounts.txt"); // opening file
	while(getline(AccountRegCheck,line)){//reads the first two fields of each line from the file until it reaches the last line//
	stringstream st (line);
	st >>usr >> psw ;//>>k>>l>>m>>n;
	//cout << usr<<" "<< psw;
	//cout<<"runningl";
	accounts.insert(pair<string,string>(usr,psw));//Re-loading my map everytime a user wants to login so new accounts are loaded in the map as well//
	//cout<<"done l";
	}
	
	if(accounts.find(user) != accounts.end() && accounts.find(pass) != accounts.end()){
		for(int c=0; c < login.size(); c++){
			cout<<login[c];
			Sleep(100);
		}
		cout<<"\nLogin Successful ";
		//cout<<usr<< psw << k<<l<<m<<n;
		return true;
	}
	else{
		cout<<"\n false";
		//for(map<string,string>::iterator it=accounts.begin() ; it !=accounts.end();++it)
			//cout<<endl<<it->first<<"-"<<it->second;
		return false;
	}
}//end of validate account//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Getting is right.//

void Account::loadExistingAccount(string us, string ps){

	//Declaring fields that will be carrying read input from txt file//
	string firstName, lastName, UserName, Password;
	int day , month, year, idNum;
	double Deposite, Balance;
	//this will be each line of the file through the following loop// 
	string line;
	
	AccountRegCheck.open("Accounts.txt");
	cout<<"\nThis is what is stored in 'line' "<<getline(AccountRegCheck, line);
	while (getline(AccountRegCheck, line)){
		stringstream ssl (line); // making line a stringstream to access strings and chars within each line//
		ssl >> UserName >> Password; //reading the first two fields of line
		if ((UserName == us) && (Password == ps)){
			ssl >> firstName >> lastName >> day >> month >> year >> idNum >> Deposite >> Balance;		
			userName = UserName;
			password = Password;
			person.setFname(firstName);
			person.setLname(lastName);
			person.getDate().setDay(day);
			person.getDate().setMonth(month);
			person.getDate().setYear(year);
			person.setIdNum(idNum);
			depositeAmount = Deposite;
			accountBalance = Balance;
			cout<<"Proccessed";
			break;
	
			
		}//end of if
	
		
	}//end of while loop
	AccountRegCheck.close();
}//end of function//

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//THIS was BEFORE learning maps//
	/*AccountRegCheck.open("Accounts.txt"); // opening file
	
	while(AccountRegCheck >>usr>>psw){//while reading both fields of the file on each line...
		if (user==usr && pass==psw){
		
			return true;
		}
		else if(user==usr && pass!=psw ){
			cout<<"\n!<---Invalid Password--->";
			return false;	
		}
		else
			return false;	
		}//end of while loop//
	
	}//end of account validation//
	*///used later for validating
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
//	rewrite this function to grab fields depending on username and password//
//use ifs to check first 2 fields of each line then determine rather to grab the rest or not//
/*void Account::loadExistingAccount(string u, string p){
	
	string usr, psw, fname, lname , line ; //using line to get each line in the text file// 
	int dd,mm,yy, idNum;
	double deposite, balance;
	//cout<<"\nWORK2";	
	AccountRegCheck.open("Accounts.txt");
	cout<<"\nWORK";//prints//
	while(getline(AccountRegCheck,line)){//getline(AccountRegCheck ,line)){ // gets every line in the text file // 
		cout<<"\nx";//doesnt//
		stringstream ss (line); //String stream takes in each line from the text file and reads all the words on the line as a sequence of characters, and grants you accessibility to them//
		ss >> usr >> psw; // telling the string streamer to read the first and second word in the line variable (string) everytime it grabs a different line (loop / if)//
	 //cout<<"\nx";
	 	if(u=="admin" && p=="admin"){ // checking if the login credentials are valid and exsisting in the txt file // 
			cout<<"\n\nittt";
			//strStreamer >> fname>> lname>> dd>> mm>> yy>> idNum>> deposite >> balance; // if the user name and password match, fetch the rest of the data on that line//
			//Account ret (usr, psw,  fname, lname, dd, mm , yy , idNum , deposite, balance); // creating a new account object, passing in the users infor to the constructor and returning it as a reference to catch in main // 
			//return new Account (usr, psw,  fname, lname, dd, mm , yy , idNum , deposite, balance); // creating a new account object, passing in the users infor to the constructor and returning it as a reference to catch in main // 
			userName=usr;
			password=psw;
			person.setFname(fname);
			person.setLname(lname);
		    person.setDate(dd,mm,yy);
		    person.setIdNum(idNum);
		    accountBalance=balance;
			depositeAmount=deposite;
			
			cout<<endl<<"------------------"<<userName;
			cout<<endl<<password;
			cout<<endl<<person.getFname();
			cout<<endl<<person.getLname();
			//cout<<endl<<person.getDate();
			cout<<endl<<accountBalance;
			cout<<endl<<deposite;
			
		//break;
		}//end of iff
	}//end of loop
	//AccountRegCheck.close();


	//cout<<"ou"; //prints


	/*string usr, psw, fname, lname ; //used to read first and seconed fields of Account registration file (Accounts.txt) 
	int dd,mm,yy, idNum;
	double deposite, balance;	
	AccountRegCheck.open("Accounts.txt"); // opening file
	
	while(AccountRegCheck >> usr >> psw >>fname >> lname >> dd >> mm >> yy >> idNum >> deposite >> balance){
		
		// assing file variable to objects data vars then return the object as a refence to catch in main//
		// start thinking of inheritence for sub accounts // 
		if (usr== u && psw == p){
			string usr, psw, fname, lname ; //used to read first and seconed fields of Account registration file (Accounts.txt) 
			int dd,mm,yy, idNum;
			double deposite, balance;
			
			while (AccountRegCheck >> usr>> psw>> fname>> lname>> dd>> mm>> yy>> idNum>> deposite >> balance ){
			
			
			Account ret (usr, psw,  fname, lname, dd, mm , yy , idNum , deposite, balance);
	
			return ret;
			break;
			}
			AccountRegCheck.close();
		
		else{
			cout<<"404 Error - Acount Not Found";
		}
		AccountRegCheck.close();
		
		}
		
	}//END OF LOAD EXISTING//				*/
 //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 //NOT DONE WITH THIS FUNCTION YET//
 void Account::createNewAcount(){ //returning a reference //
	
	string userNm,passw, passd, fname, lname;//passd is used for password verification//
	char sure;
	bool tr=false;
	int age; 
	double depositeAmount2 , accountBalance2;
	cout<<setw(10)<<"\n                                  <!---Welcome---!> ";
	cout<<"\n\nStep #1 : ";
	cout<<"\n"<<setw(15)<<"Enter your first and last name  : ";
	cin>>fname>>lname;
	cout<<"\n"<<setw(15)<<"Enter your date of birth (Month/Day/Year) : ";
	cin>>age;// overloaded 
	cin.ignore(100,'\n');//the dashes(in date) ruin the input without using the ignore input function//
	cout<<"\nStep #2";
	cout<<"\n"<<setw(15)<<"Create a user name & Password :";
	cout<<"\n"<<setw(15)<<" User Name : ";
	getline(cin,userNm);
	bool su = false;
	while(su==false){
	
	cout<<"\n"<<setw(15)<<"Are you sure you want to set ' "<<userNm<<" ' as your user name ? (y/n)";
	cin>>sure;
	
	
	//VERIFICATION FOR Y/N IS NOT FUNCTIONING//
	while(true){
	
	if(sure=='n'){//what to do if user answers no//
	
		cout<<"Re-enter User Name : ";
		cin>>userNm;
		break;
	
	}
	else if (sure=='y'){
		su=true;
		break;
		}
	else{ //verfication for input//
		cout<<"Invalid Entry, (y/n)";
		cin>>sure;
		
		}
		
	}
	break;
	
	}//UP TILL HERE//
	
	
	cout<<"\nStep #3";
	while(tr==false){
	
	cout<<"\n"<<setw(15)<<"Create a Password : ";
	char ch; 
   ch = _getch();
   while(ch != 13){
      passd.push_back(ch);
      cout <<'*';
      ch = _getch();
   }
   cout<<"\n"<<setw(15)<<"Re-enter Password : ";
	ch = _getch();
   while(ch != 13){
      passw.push_back(ch);
      cout <<'*';
      ch = _getch();
   }
   	if (passw==passd){
   		tr=true;
   		cout<<"\n"<<setw(15)<<"Passwords Match";
   		break;
	   }
	else{
		cout<<"\n"<<setw(15)<<"!<---Passwords do not match--->!";
		passw="";
		passd="";
		tr=false;
	} 
}
   
	cout<<"\nStep #4";
	int add;
	double amm,accBalance;
	
	
	cout<<"\nWould you like to to add any funds to your account ? ";
	cout<<"\n1) Yes";
	cout<<"\n2) No";
	cin.ignore(100,'\n');
	cin>>add;
	
	while (add<1 || add>2){
	
		cout<<"\nInvalid Entry";
		cout<<"\nWould you like to to add any funds to your account ? ";
		cout<<"\n1) Yes";
		cout<<"\n2) No";
		cin>>add;
		if(add==1 || add==2)
			break;
		}//end of while loop//
		
		if(add==1){
		cout<<"Enter Amount to Deposite : ";
		cin>>amm;
		accBalance=amm;
		}
		else{amm=0;}
	
	
	
	//Account newAccount(userNm, passd, fname , lname, person.getDate().getMonth(), person.getDate().getDay(), person.getDate().getYear(), amm,accBalance);
	

	//return newAccount;	
	
	}

	Account& Account::operator=( Account a){
		userName=a.userName;
		password=a.password;
		
		return *this;//Account ac(a.userName,a.password,a.person.getFname(), a.person.getLname(), a.person.getDate().getDay(), a.person.getDate().getMonth(), a.person.getDate().getYear(), a.depositeAmount, a.accountBalance);
	}

	//NOT DONE//
 void Account::mainMenu(Account& ac){
 	
 	
 	cout<<"\nUser : "<<ac.person.getFname()<<" "<<ac.person.getLname();
 	cout<<"\nUser name ID : "<< userName;
 	cout<<"____________________________";
 	cout<<"|						  |";
 	cout<<"|		Main Menu	      |";
 	cout<<"|						  |";
 	cout<<"|__________________________|";
 }		
	
	
