#pragma once

#include "MovieDbRepository.h"

class MovieManager
{
	MovieRepository& repository_;

	static void PrintMovieData(const std::shared_ptr<MovieData>& movie);
public:
	MovieManager(MovieRepository& repository)
		: repository_(repository)
	{
	}

	void ShowMovieDetails(const std::string& movie_id) const
	{
		const auto movie = repository_.GetById(movie_id);

		PrintMovieData(movie);
	}
};

