#include <iostream>
#include <string>
#include "Movies.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

void increment_watched(Movies &movies,string name) {
	if (movies.increment_watched(name)) {
		cout << name << " watch incremented" << endl;
	} else {
		cout << name << " not found" << endl;
	}
}

void add_movie(Movies &movies, string name, string rating, int times_watched) {
	if (movies.add_movie(name, rating, times_watched)) {
		cout << name << " added" << endl;
	} else {
		cout << name << " already in the list" << endl;
	}
}

int main() {
	Movies my_movies;

	my_movies.display();

	add_movie(my_movies, "Big", "PG-13", 2);
	add_movie(my_movies, "Star Wars", "PG", 5);
	add_movie(my_movies, "Cinderella", "PG", 7);

	my_movies.display();

	add_movie(my_movies, "Cinderella", "PG", 7);
	add_movie(my_movies, "Ice Age", "PG", 12);

	my_movies.display();

	increment_watched(my_movies, "Big");
	increment_watched(my_movies, "Ice Age");
	increment_watched(my_movies, "XXX");

	my_movies.display();

	return 0;
}
