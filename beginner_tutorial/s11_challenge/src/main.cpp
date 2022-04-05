#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void display_menu()
{
	cout << "Menu" << endl;
	cout << "-------------------" << endl;
	cout << "P - Print numbers" << endl;
	cout << "A - Add number" << endl;
	cout << "M - Display avg of the numbers" << endl;
	cout << "S - Display smallest number" << endl;
	cout << "L - Display largest number" << endl;
	cout << "F - Find number" << endl;
	cout << "Q - Quit" << endl;
	cout << "Choose: " << endl;
	cout << endl;
}

char choose_menu_item();
void print_numbers(const vector<int>& my_list);
void add_number(vector<int>& my_list);
void display_avg(const vector<int>& my_list);
void show_smallest(const vector<int>& my_list);
void show_largest(const vector<int>& my_list);
bool find_in_vector(const vector<int>& my_list, int item_to_find);
void find_number(const vector<int>& my_list);
void quit();

char choose_menu_item()
{
	char selection {};

	cin >> selection;
	selection = static_cast<char>(toupper(selection));
	return selection;
}

void print_numbers(const vector<int>& my_list)
{
	if (my_list.empty())
		cout << "The list is empty" << endl;
	else {
		cout << "[ ";
		for (auto list_member: my_list)
			cout << list_member << " ";
		cout << "]" << endl;
	}
}

void add_number(vector<int>& my_list)
{
	int new_member {};
	cout << "Enter integer: ";
	cin >> new_member;
	my_list.push_back(new_member);
	cout << new_member << " added" << endl;
}

void display_avg(const vector<int>& my_list)
{
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
}

void show_smallest(const vector<int>& my_list)
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
}

void show_largest(const vector<int>& my_list)
{
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
}

void quit()
{
	cout << "Goodbye" << endl;
}

bool find_in_vector(const vector<int>& my_list, int item_to_find)
{
	for (auto item:my_list)
		if (item == item_to_find)
			return true;
	return false;
}

void find_number(const vector<int>& my_list)
{
	if (my_list.empty())
		cout << "The list is empty" << endl;
	else {
		int num_to_find {};
		cout << "Enter a number: ";
		cin >> num_to_find;
		if (find_in_vector(my_list, num_to_find))
			cout << "Number " << num_to_find << " found" << endl;
		else
			cout << "Number " << num_to_find << " not found" << endl;
	}
}

int main()
{
	vector <int> my_list {};
	char selection {};

	do {
		display_menu();

		selection = choose_menu_item();

		switch (selection)
		{
			case 'P': {
				print_numbers(my_list);
				break;
			}
			case 'A': {
				add_number(my_list);
				break;
			}
			case 'M': {
				display_avg(my_list);
				break;
			}
			case 'S':
			{
				show_smallest(my_list);
				break;
			}
			case 'L': {
				show_largest(my_list);
				break;
			}
			case 'F': {
				find_number(my_list);
				break;
			}
			case 'Q': {
				quit();
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
