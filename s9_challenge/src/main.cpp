#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector <int> my_list {};
	char selection {};

	do {
		cout << "Menu" << endl;
		cout << "-------------------" << endl;
		cout << "P - Print numbers" << endl;
		cout << "A - Add number" << endl;
		cout << "M - Display avg of the numbers" << endl;
		cout << "S - Display smallest number" << endl;
		cout << "L - Display largest number" << endl;
		cout << "Q - Quit" << endl;
		cout << "Choose: " << endl;
		cout << endl;

		cin >> selection;
		selection = static_cast<char>(toupper(selection));

		switch (selection)
		{
			case 'P': {
				if (my_list.empty())
					cout << "The list is empty" << endl;
				else {
					cout << "[ ";
					for (auto list_member: my_list)
						cout << list_member << " ";
					cout << "]" << endl;
				}
				break;
			}
			case 'A': {
				int new_member {};
				cout << "Enter integer: ";
				cin >> new_member;
				my_list.push_back(new_member);
				cout << new_member << " added" << endl;
				break;
			}
			case 'M': {
				if (my_list.empty())
					cout << "The list is empty";
				else {
					int sum {};
					double avg {};
					for (auto list_member: my_list)
						sum += list_member;
					avg = static_cast<double>(sum) / my_list.size();
					cout << "Average: " << avg << endl;
				}
				break;
			}
			case 'S':
			{
				if (my_list.empty())
					cout << "The list is empty" << endl;
				else
				{
					int smallest{ my_list.at(0) };
					for (auto list_member: my_list)
					{
						if (list_member < smallest)
							smallest = list_member;
					}
					cout << "Smallest number is " << smallest << endl;
				}
				break;
			}
			case 'L': {
				if (my_list.empty())
					cout << "The list is empty" << endl;
				else {
					int largest{ my_list.at(0) };
					for (auto list_member: my_list) {
						if (list_member > largest)
							largest = list_member;
					}
					cout << "Largest number is " << largest << endl;
				}
				break;
			}
			case 'Q': {
				cout << "Goodbye" << endl;
				break;
			}
			case 0: {
				cout << "Escape infinite loop in Github Actions" << endl;
				selection = 'Q';
				break;
			}
			default: {
				cout << "Invalid selection" << endl;
			}
		}
		cout << "-------------------" << endl;
	} while (selection != 'Q');

	return 0;
}
