#pragma once

#include "MovieDbRepository.h"
#include "TheMovieDbApi.h"

/// <summary>
/// This is an implementation of object adapter
/// This implementation support using different sub classes 
/// </summary>
class MovieApiAdapter : public MovieRepository
{
	MovieApi& api_;

public:
	MovieApiAdapter(MovieApi& api) : api_(api){}

	std::shared_ptr<MovieData> GetById(const std::string& movie_id) override;
};

