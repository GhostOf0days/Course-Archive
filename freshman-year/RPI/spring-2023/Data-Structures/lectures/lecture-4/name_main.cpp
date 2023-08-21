#include <algorithm>
#include <iostream>
#include <vector>
#include "name.h"

int main() {
  std::vector<Name> names;
  std::string first, last;
  std::cout <<"\nEnter a sequence of names (first and last) and this program will alphabetize them\n";
  while (std::cin >> first >> last) { 
    names.push_back(Name(first, last));
  }
  std::sort(names.begin(), names.end());
  std::cout << "\nHere are the names, in alphabetical order.\n";
  for (int i = 0; i < names.size(); ++i) { 
    std::cout << names[i] << "\n";
  }  
  return 0;
}
