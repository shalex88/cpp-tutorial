#include <iostream>
#include <fstream>

int main() {
  std::string in_filename {"..//..//..//..//beginner_tutorial//s19_challenge//s19_4_challenge//files//romeoandjuliet"
						   ".txt"};
  std::string out_filename {"..//..//..//..//beginner_tutorial//s19_challenge//s19_4_challenge//files"
							"//romeoandjuliet_copy.txt"};

  std::ifstream in_file {in_filename};
  if (!in_file) {
	std::cerr << "Error opening file" << std::endl;
	return 1;
  }

  std::ofstream out_file {out_filename};
  if (!out_file) {
	std::cerr << "Error opening file" << std::endl;
	return 1;
  }

  std::string line {};
  size_t line_number {};
  while (std::getline(in_file, line)) {
	if (!line.empty() && line != "\r") {
	  out_file << ++line_number << "\t";
	}
	out_file << line;
  }

  in_file.close();
  out_file.close();

  std::cout << "File copied" << std::endl;

  return 0;
}
