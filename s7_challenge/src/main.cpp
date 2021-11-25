#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	/* TODO:
	 * [v] declare empty vector1
	 * [v] declare empty vector2
	 * [v] add 10, 20 to vector1
	 * [v] display vector1 elements and size
	 * [v] add 100, 200 to vector2
	 * [v] display vector2 elements and size
	 * [v] declare empty 2d vector_2d
	 * [v] add vector1 and vector2 to vector_2d
	 * [v] display vector_2d elements
	 * [v] set vector1[0] = 1000
	 * [v] display vector_2d elements
	 * [v] display vector1 elements
	 * */

	vector <int> vector1;
	vector <int> vector2;

	vector1.push_back(10);
	vector1.push_back(20);

	cout << "Vector1" << endl;
	cout << "Size: " << vector1.size() << endl;
	cout << "Elements: " << endl << vector1.at(0) << " " << vector1.at(1) << endl;
	cout << "-------" << endl;

	vector2.push_back(100);
	vector2.push_back(200);

	cout << "Vector2" << endl;
	cout << "Size: " << vector2.size() << endl;
	cout << "Elements: " << endl << vector2.at(0) << " " << vector2.at(1) << endl;
	cout << "-------" << endl;

	vector <vector<int>> vector_2d;
	vector_2d.push_back(vector1);
	vector_2d.push_back(vector2);
	cout << "Vector2D" << endl;
	cout << "Elements: " << endl << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << endl
		<< vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl;
	cout << "-------" << endl;

	cout << "Vector2D" << endl;
	cout << "Elements: " << endl << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << endl
		 << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl;
	cout << "-------" << endl;

	vector1.at(0) = 1000;
	
	cout << "Vector1" << endl;
	cout << "Elements: " << endl << vector1.at(0) << " " << vector1.at(1) << endl;
	cout << "-------" << endl;

	return 0;
}