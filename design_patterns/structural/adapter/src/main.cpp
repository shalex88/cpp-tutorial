#include <iostream>

#include "MovieDbRepository.h"
#include "MovieManager.h"
#include "MovieApiAdapter.h"
#include "TheMovieDbApi.h"
#include "api_key.h"
#include "FileBasedApi.h"
#include "MovieApiAdapter2.h"

const std::string MOVIE_ID {"141052"};

int main()
{
	// Sign up at www.themoviedb.org for an api key and add it in api_key.h
	std::cout << "Api key" << MY_API_KEY << std::endl;
	
	std::cout << "---- WebAPI with Object Adapter ---" << std::endl;
	TheMovieDbApi api(MY_API_KEY);
	MovieApiAdapter adapter_1(api);
	const MovieManager manager_1(adapter_1);
	manager_1.ShowMovieDetails(MOVIE_ID);

	std::cout << "---- WebAPI with Class Adapter ----" << std::endl;
	MovieApiAdapter2 adapter_2(MY_API_KEY);
	const MovieManager manager_2(adapter_1);
	manager_2.ShowMovieDetails(MOVIE_ID);

	std::cout << "--- File API with Object Adapter --" << std::endl;
	FileBasedApi file_api(R"(files//)");
	MovieApiAdapter adapter_3(file_api);
	const MovieManager manager_3(adapter_3);
	manager_3.ShowMovieDetails (MOVIE_ID);
}