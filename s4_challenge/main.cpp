#include <iostream>

int main() {
    int favorite_number = 0;

    std::cout << "Enter your favorite number from 1 to 100: ";
    std::cin >> favorite_number;
    std::cout << "Amazing!! That's my favorite number too!" << std::endl;
    std::cout << "No really!! " << favorite_number << " is my favorite number!" << std::endl;

    return 0;
}
