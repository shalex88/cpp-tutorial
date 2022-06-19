#include <iostream>
#include <fstream>

int main() {
  std::string filename {"files//romeoandjuliet.txt"};
  std::ifstream in_file {filename};
  if (!in_file) {
	std::cerr << "Error opening file" << std::endl;
	return 1;
  }

  /* Get the word to word_to_find */
  std::string word_to_find {};
  std::cout << "Enter a word to find: ";
  std::cin >> word_to_find;

  std::string current_word {};
  int match_count {};
  int total_count {};

  while (in_file >> current_word) {
	total_count++;
	size_t found_position = current_word.find(word_to_find);
	if (found_position != std::string::npos) {
	  match_count++;
	}
  }

  in_file.close();

  std::cout << "Match counter: " << match_count << " / " << total_count << std::endl;

  return 0;
}
