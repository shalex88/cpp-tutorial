#include "Movie.h"

using std::cout;
using std::endl;
using std::string;

Movie::Movie(string name_val, string rating_val, int times_watched_val)
	: name{name_val}, rating{rating_val}, times_watched{times_watched_val} {
	cout << "Movie added" << endl;
}
void Movie::display()
{
	cout << "[ " << name << ", " << rating << ", " << times_watched << " ]" << endl;
}
