#include "Movies.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

Movies::Movies() {
	cout << "Movies list created" << endl;
}

bool Movies::add_movie(string name_val, string rating_val, int times_watched_val) {
	Movie  new_movie {name_val, rating_val, times_watched_val};
	movies_list.push_back(new_movie);

	return true;
}

bool Movies::increment_watched(string name_val) {
	for(auto movie:movies_list) {
		if (movie.name == name_val)
			movie.
	}
}

void Movies::display() {
	if (movies_list.empty()) {
		cout << "The list is empty" << endl;
	} else {
		cout << "Display my movies list: " << endl;
		for (auto movie: movies_list)
			movie.display();
	}
}
