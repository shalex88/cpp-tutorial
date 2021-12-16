#ifndef CPP_TUTORIAL_S15_CHALLENGE_PERSON_H_
#define CPP_TUTORIAL_S15_CHALLENGE_PERSON_H_

#include "Account.h"

class Person {
	std::string name; // Composition - "has-a"
	Account account; // Composition - "has-a"
};

#endif //CPP_TUTORIAL_S15_CHALLENGE_PERSON_H_
