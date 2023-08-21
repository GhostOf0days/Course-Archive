#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include "student.h"

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Usage:\n  " << argv[0] << " infile-students outfile-grades\n";
    return 1;
  }  
  std::ifstream in_str(argv[1]);
  if (!in_str) {
    std::cerr << "Could not open " << argv[1] << " to read\n";
    return 1;
  }  
  std::ofstream out_str(argv[2]);
  if (!out_str) {
    std::cerr << "Could not open " << argv[2] << " to write\n";
    return 1;
  }

  int num_homeworks, num_tests;
  double hw_weight;
  in_str >> num_homeworks >> num_tests >> hw_weight;
  std::vector<Student> students;
  Student one_student;

  // Read the students, one at a time.
  while(one_student.read(in_str, num_homeworks, num_tests)) {
    students.push_back(one_student); //Vector push_back makes a COPY (not by reference/&)
  }
  
  // Compute the averages.  At the same time, determine the maximum name length.  
  unsigned int i; 
  unsigned int max_length = 0;
  for (i=0; i<students.size(); ++i) {
    students[i].compute_averages(hw_weight);
    unsigned int tmp_length = students[i].first_name().size() + students[i].last_name().size();
    max_length = std::max(max_length, tmp_length);
  }
  max_length += 2;   // account for the output padding with ", "

  // Sort the students alphabetically by name.
  std::sort(students.begin(), students.end(), less_names);

  // Output a header...
  out_str << "\nHere are the student semester averages\n";
  const std::string header = "Name" + std::string(max_length-4, ' ') + "  HW  Test Final";
  const std::string underline(header.size(), '-');
  out_str << header << '\n' << underline << std::endl;

  // Output the students...
  for (i=0; i<students.size(); ++i) {
    unsigned int length = students[i].last_name().size() + 
      students[i].first_name().size() + 2;
    students[i].output_name(out_str);
    out_str << std::string(max_length - length, ' ') << "  ";
    students[i].output_averages(out_str);
  }  

  return 0;  // everything fine
}
