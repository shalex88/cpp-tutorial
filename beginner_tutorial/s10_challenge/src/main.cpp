#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	string key {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

	string decrypted {};
	cout << "Enter secret message: ";
	getline(cin,decrypted);

	string encrypted_message {};

	for (auto letter:decrypted)
	{
		size_t pos = alphabet.find(letter);
		if (pos != string::npos) {
			char new_char {key.at(pos)};
			encrypted_message += new_char;
		}
		else
			encrypted_message += letter;
	}

	cout << "Encrypted message: " << encrypted_message << endl;

	return 0;
}
