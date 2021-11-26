#include <iostream>

using namespace std;

int *apply_all(const int p_array1[], const size_t size1, const int p_array2[], const size_t size2) {
	int *p_new_array {nullptr};
	size_t new_size {size1 * size2};
	p_new_array = new int[new_size];

	size_t position {0};
	for (size_t arr2_i {0}; arr2_i < size2; arr2_i++) {
		for (size_t arr1_i {0}; arr1_i < size1; arr1_i++) {
			p_new_array[position++] = p_array2[arr2_i] * p_array1[arr1_i];
		}
	}

	return p_new_array;
}

void print(const int array[], const size_t size)
{
	cout << "[ ";
	for (size_t i {0}; i < size; i++)
		cout << array[i] << " ";
	cout << "]" << endl;
}

int main() {
	const size_t array1_size {5};
	const size_t array2_size {3};

	int array1[] {1,2,3,4,5};
	int array2[] {10,20,30};

	cout << "Array 1: " ;
	print(array1,array1_size);

	cout << "\nArray 2: " ;
	print(array2,array2_size);

	int *results = apply_all(array1, array1_size, array2, array2_size);
	constexpr size_t results_size {array1_size * array2_size};

	cout << "\nResult: " ;
	print(results, results_size);

	delete [] results;
	cout << endl;

	return 0;
}
