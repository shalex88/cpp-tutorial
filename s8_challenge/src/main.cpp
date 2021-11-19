#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	/* TODO:
	 * [v] Prompt cents_amount
	 * [v] Set balance = cents_amount
	 * [v] CENTS_IN_DOLLAR = 100
	 * [v] CENTS_IN_QUARTER = 25
	 * [v] CENTS_IN_DIME = 10
	 * [v] CENTS_IN_NICKEL = 5
	 * [v] CENTS_IN_PENNY = 1
	 * [v] Calculate how many cents can be returned with <coin>. <coin> = balance / CENTS_IN_<COIN>
	 * [v] Evaluate balance to the remainder of balance left to return divided by CENTS_IN_<COIN>
	 * [v] Do it for every coin
	 * TEST:
	 * [v] cents_amount = 0, dollars = 0, quarters = 0, dimes = 0, nickels = 0, pennies = 0
	 * [v] cents_amount = 100, dollars = 1, quarters = 0, dimes = 0, nickels = 0, pennies = 0
	 * [v] cents_amount = 92, dollars = 0, quarters = 3, dimes = 1, nickels = 1, pennies = 2
	 * */
	int cents_amount {0};

	cout << "Enter cents amount: ";
	cin >> cents_amount;

	int balance {cents_amount};

	const int CENTS_IN_DOLLAR {100};
	const int CENTS_IN_QUARTER {25};
	const int CENTS_IN_DIME {10};
	const int CENTS_IN_NICKEL {5};
	const int CENTS_IN_PENNY {1};

	int dollars {balance / CENTS_IN_DOLLAR};
	cout << "Dollars: " <<  dollars << endl;
	balance %= CENTS_IN_DOLLAR;

	int quarters {balance / CENTS_IN_QUARTER};
	cout << "Quarters: " << quarters << endl;
	balance %= CENTS_IN_QUARTER;

	int dimes {balance / CENTS_IN_DIME};
	cout << "Dimes: " << dimes << endl;
	balance %= CENTS_IN_DIME;

	int nickels {balance / CENTS_IN_NICKEL};
	cout << "Nickels: " << nickels << endl;
	balance %= CENTS_IN_NICKEL;

	int pennies {balance / CENTS_IN_PENNY};
	cout << "Pennies: " << pennies << endl;

	return 0;
}