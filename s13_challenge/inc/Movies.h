#ifndef _MOVIES_H_
#define _MOVIES_H_

#include <vector>
#include <string>
#include "Movie.h"

using std::vector;
using std::string;

class Movies
{
 private:
	vector<Movie> movies_list;
 public:
	Movies();
	bool add_movie(string name_val = "Unknown", string rating_val = "None", int times_watched_val = 0);
	bool increment_watched(string name_val);
	void display();
};

#endif //_MOVIES_H_
