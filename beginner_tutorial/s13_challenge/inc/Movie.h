#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <iostream>
#include <string>

class Movie {
 private:
	std::string name;
	std::string rating;
	int times_watched;
 public:
	Movie(std::string name_val = "Unknown", std::string rating_val = "None", int times_watched_val = 0);
	void display() const;
	const std::string& get_name() const;
	void increment_watched();
};

#endif //_MOVIE_H_
