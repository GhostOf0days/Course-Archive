
//  Use a map to count the number of words that appear in the input.
//  This does not convert upper case letters to lower case, so for
//  example Hi and hi are treated differently.  This could be changed

// If you are using Visual Studio 6, remove the comment from the
// following line. 
// #pragma warning( disable : 4786 )

#include <iostream>
#include <map>
#include <string>

int main() {
  std::string s;
  std::map<std::string, int> counters; // store each word and an associated counter

  // read the input, keeping track of each word and how often we see it
  while (std::cin >> s) {
    std::map<std::string, int>::iterator it = counters.find(s);
    if (it == counters.end()) {
      counters.insert(std::make_pair(s,1));
    }
    else {
      it->second++;
    }
  }
    //  ++counters[s];

  // write the words and associated counts
  std::map<std::string, int>::const_iterator it;
  for (it = counters.begin(); it != counters.end(); ++it) {
    std::cout << it->first << "\t" << it->second << std::endl;
  }
  return 0;
}

