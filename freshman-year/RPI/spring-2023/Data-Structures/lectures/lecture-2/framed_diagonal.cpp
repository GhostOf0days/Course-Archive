#include <iostream>
#include <string>

int main() {
  std::cout << "What is your first name? ";
  std::string first;
  std::cin >> first;
  
  const std::string star_line(first.size()+4, '*');
  const std::string blanks(first.size()+2, ' ');
  const std::string empty_line = '*' + blanks + '*';
  std::string one_line = empty_line;

  std::cout << '\n' << star_line << '\n' << empty_line << std::endl;

  // Output the interior of the greeting, one line at a time.
  for (unsigned int i = 0; i < first.size(); ++i ) {
    // Create the output line by overwriting a single character from the 
    // first name in location i+2.  After printing it restore the blank.
    one_line[ i+2 ] = first[i];
    std::cout << one_line << '\n';
    one_line[ i+2 ] = ' ';
  }
  
  std::cout << empty_line << '\n' << star_line << std::endl;
  
  return 0;
}
