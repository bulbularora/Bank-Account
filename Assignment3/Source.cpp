#include <iostream>
#include "Assignment3.h"
#include <vector>

using namespace std;

vector<BankAccount> accounts;

int main() {
	
	int id;  // id user inputs to manage account
	int destroyID; // id user inputs to destroy account.
	int dummyID = 0;  // increments every time user wants to create a new account id.
	int temp;
	string p; // password the user inputs for managing an account.
	string p1; // password the user inputs for destroying the account
	bool passwordCheck= false;  // checks if the password matches to the set password. 
	int mainOpt = 0; // main menu
	int manageOpt = 0; // manage account menu
	bool tempBool;
	while (mainOpt != 4) {
		std::cout <<endl<< "Welcome to Banking Program main menu!" << endl
			<< "Please select one of the following options :" << endl
			<< "1. Manage an account" << endl
			<< "2. Create an account" << endl
			<< "3. Destroy an account" << endl
			<< "4. Exit the program" << endl<<endl;
		cin >> mainOpt;
		if (mainOpt == 1) {   // manage account: deposit, withdraw or view balance.
			std::cout << "enter account ID: ";
			cin >> id;
			for (int i = 0; i < accounts.size(); i++) {  // loops through all the accounts to find desired ID.
				temp = accounts[i].getID();
				if (temp == id) {				// checks if the id given by the user exists
					temp = i;
					std::cout << "enter account ID #" << id << " password: ";
					cin >> p;
					passwordCheck = accounts[temp].checkPassword(p); // checks if the input passowrd matches the password associated.
					tempBool = true;  // true if this if statement was entered, bool for error checking
					break;
				}

				else {
					tempBool = false;
				}
				
			}

			if (tempBool == false) {  // temp was never equal to id. therefore there is no account with that id.
				std::cout << "The account does not exist." << endl;
			}

				if (passwordCheck == true) {      // if the id exists and the password is correct: user gets the option to withdraw, deposit or view balance.
					while (manageOpt != 4) {
						std::cout <<endl<< "Account #" << id << " management menu" << endl
							<< "Please select one of the following options :" << endl
							<< "1. Display balance" << endl
							<< "2. Deposit funds" << endl
							<< "3. Withdraw funds" << endl
							<< "4. Go to main menu" << endl<<endl;
						cin >> manageOpt;
						if (manageOpt == 1) {
							std::cout << "Your current balance is $" << accounts[temp].getBalance()<<endl; //view balance
						}
						if (manageOpt == 2) {
							accounts[temp].depositFunds();  // desposit funds
						}
						if (manageOpt == 3) {
							accounts[temp].withdrawFunds();  // withdraw funds
						}
					}
					manageOpt = 0; // so the last value of manageOpt does not remain at 4. 
				}
				passwordCheck = false; // to initialize it back to false so it shows the correct output.
			

		}
		
		if (mainOpt == 2) {   //create new account with new id and password.

			BankAccount dummy(dummyID, 0.00, " "); // dummy bank account with id incremented each time, 0 balance and a dummy string.
			std::cout << "To create an account, please provide a password." << endl
				<< "The password should be 8 to 32 characters long." << endl
				<< "New account password : ";
			cin >> p;

			if (p.size() >= 8 && p.size() <= 32) { // password matches the criteria.
				accounts.push_back(dummy);
				int a = accounts.size(); // accounts size for indexing.
				accounts[a - 1].setPassword(p); // sets the password for the new id. example: if a is 5, the index for accounts is 4.
				std::cout << "Account with ID number " << dummyID << " has been successfully created!" << endl;
				dummyID++; // increments dummy id so the next account has a different next id.
			}

			else {
				cout << "Account not added. The password does not match the criteria." << endl;
			}
			
		}

		if (mainOpt == 3) {  // destroy account: asks user for id and password authorization
			int tempID;  // becomes the index of the ID. 
			bool tempBool2;  // to see if the ID exists and to print appropriate messages.
			bool tempPassword= false;  // checks if the user entered password equals actual password.
			std::cout << "Enter the Account ID you want to destroy: ";
			cin >> destroyID; // the id you want to destroy.
			for (int i = 0; i < accounts.size(); i++) {
				tempID = accounts[i].getID();  // 
				if (tempID == destroyID) {   //checks if id exists.
					std::cout << "Enter the password: ";
					cin >> p1;
					tempID = i; // becomes the index of the account.
					tempPassword = accounts[tempID].checkPassword(p1); // checks password for given id
					tempBool2 = true;  // id exists therefore do not print "does not exist" message.
					break;
				}
				else {
					tempBool2 = false; // id does not exist. prints message later. 
				}
			}
			if (tempBool2== false) {
				std::cout << "The account does not exist." << endl; // prints message is ID was not found.
			}

			if (tempPassword == true) {
				accounts.erase(accounts.begin() + tempID);  // erases the given index.
				std::cout << "Your Account with ID " << destroyID << " has been destroyed." << endl;
			}
			

		}
	}
}
	

