#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

class BankAccount {
private:
	unsigned int ID;   // account id
	float balance;  // account balance
	string password;  // account password used for authorization to manage or destroy account
public:
	BankAccount();  //initializer
	BankAccount(int id, float b, string s); // initializes with parameters
	void setBalance(float b); // setter for balance
	unsigned int getID(); // getter for ID.
	float getBalance(); //getter for balance
	void setPassword(string p);  // setter for password
	bool checkPassword(string p);  // returns true if the passoword is equal to the string that the user inputs.
	void depositFunds();  // adds to the existing funds of the account
	void withdrawFunds();  // subtracts the given funds from the balance with error checking. 

};


