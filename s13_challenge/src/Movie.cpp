#include "Movie.h"

using std::cout;
using std::endl;
using std::string;

Movie::Movie(string name_val, string rating_val, int times_watched_val)
	: name{name_val}, rating{rating_val}, times_watched{times_watched_val} {
}
void Movie::display() const {
	cout << "[ " << name << ", " << rating << ", " << times_watched << " ]" << endl;
}
const string& Movie::get_name() const {
	return name;
}

void Movie::increment_watched() {
	times_watched++;
}
