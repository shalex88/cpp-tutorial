#include <iostream>
#include <fstream>
#include <vector>

class Student {
 public:
  std::string name;
  std::string answer;
  int score;
};

int main() {
  std::string filename {"..//..//..//..//beginner_tutorial//s19_challenge//s19_2_challenge//files//file.txt"};
  std::ifstream in_file {filename};
  if (!in_file) {
	std::cerr << "Error opening file" << std::endl;
	return 1;
  }

  /* Get the right answer */
  std::string answer_key {};
  in_file >> answer_key;
  size_t tests_num {answer_key.length()};

  /* Create a vector of students */
  std::vector <Student> students_list {};
  Student student_temp {};
  while (in_file >> student_temp.name >> student_temp.answer) {
	students_list.push_back(student_temp);
  }

  in_file.close();

  /* Process the students vector */
  size_t total_score {};

  for (auto &student : students_list) {
	for (size_t i {}; i < tests_num; i++) {
	  if (answer_key.at(i) == student.answer.at(i)) {
		student.score++;
	  }
	}
	total_score += student.score;
	std::cout << student.name << " " << student.score << std::endl;
  }

  double average_score {static_cast<double>(total_score) / students_list.size()};
  std::cout << "Average score " << average_score << std::endl;

  return 0;
}
