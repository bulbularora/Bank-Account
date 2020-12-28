#include "Assignment3.h"

using namespace std;

BankAccount::BankAccount() {  
	ID = 0;
	balance = 0.00;
	password = " ";
}

BankAccount::BankAccount(int id, float b, string s) {
	ID = id;
	balance = b;
	password = s;
}
void BankAccount::setBalance(float b) { // setter for balance
	balance = b;
}

unsigned int BankAccount::getID() { // getter for id
	return ID;
}

float BankAccount::getBalance() { // getter for balance
	return balance;
}

void BankAccount::setPassword(string p) {   // setter for password
		password = p;
}

bool BankAccount::checkPassword(string p) {   //returns true if the passoword is equal to the string that the user inputs

	if (p == password) {
		cout << "Password accepted." << endl;
		return true;
	}
	else {
		cout << "Password Incorrect. Please try again." << endl;
		return false;
	}

}

void BankAccount::depositFunds() {
	float b;
	cout << "Please enter the deposit amount:";
	cin >> b;
	balance = balance + b;
	int bonusNum = balance / 250;
	for (int i = 0; i < bonusNum; i++) {   // for the $5 bonus for every $250.
		balance = balance + 5;
	}

	cout << "Your balance now is : $" << balance << endl;

}

void BankAccount::withdrawFunds() {
	float w;
	cout << "Please enter the amount you want to withdraw: ";
	cin >> w;
	float bal = balance - 2;   // amount that the customer can withdraw after the $2 fee.

	if (w > bal) {  // checks if the balance is in within the allowed amount the customer can withdraw.

		cout << "You do not have enough balance to withdraw. " << endl;
	}
	else {
		balance = balance - (w + 2.00);    // if there is sufficiennt balance, withdraw the amount.
		cout << "Your new balance is : $" << balance << endl;  
	}

}

