#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class BankAccount {
private:
	string owner;//account holder (client's full name)
	double balance;//current balance (in rubles)
public:

	BankAccount(string o, double b = 0) {
		owner = o;
		balance = b;
	}

	BankAccount() {
		owner = "Unknown";
		balance = 0;
	}

	void deposit(double amount) {
		//deposits money into the account
		if (balance <= 0) {
			cout << "Operation fails...";
		}
		else 
			balance = balance + amount;
		cout << owner << " " << "topped up my account to " << owner << " ." << "New balance: "<< balance << " ." << endl;
	}

	void getMoney(double amount) {
		//withdraws money from the account
		if (balance <= 0) {
			cout << "The operation is rejected...";
		}
		if (balance > balance + amount) {
			cout << "The operation is impossible, a warning is displayed!";
		}
		else
			balance = balance - amount;
		cout << owner << " " << "withdrew " << balance << " ." << "Account balance: " <<" ." << endl;
	}
	void setOwner(const string& o) {
		owner = o;
	}

	string Owner()const {
		return owner;
	}

	void setBalance(const double& b) {
		balance = b;
	}

	double Balance()const {
		return balance;
	}

	void printInfo() {
		cout << "Client account: "<<owner << "."
			<< " Balance: "<<balance << " rubles." << endl;
	}
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	BankAccount o1;
	o1.printInfo();

	string owner;
	double balance;

	cout << "Enter name of owner: ";
	cin >> owner;
	o1.setOwner(owner);
	o1.printInfo();

	cout << "Balance: ";
	cin >> balance;
	o1.setBalance(balance);
	o1.printInfo();

	o1.deposit(100);
	o1.printInfo();

	o1.getMoney(30);
	o1.printInfo();
}