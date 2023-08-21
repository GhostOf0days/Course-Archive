// These "include guards" prevent errors from "multiple includes"
#ifndef __name_h_
#define __name_h_

#include <iostream>
#include <string>

class Name {
public:
  // CONSTRUCTOR (with default arguments)
  Name(const std::string& fst="", const std::string& lst="");
  // ACCESSORS  
  // Providing a const reference to the string allows the string to be
  // examined and treated as an r-value without the cost of copying it.
  const std::string& first() const { return first_; }
  const std::string& last() const { return last_; }
  // MODIFIERS
  void set_first(const std::string & fst) { first_ = fst; }
  void set_last(const std::string& lst) { last_ = lst; }
private:
  // REPRESENTATION
  std::string first_, last_;
};

// operator< to allow sorting
bool operator< (const Name& left, const Name& right);

// operator<< to allow output
// Name n("Some", "Person");
// std::cout << n;
// operator<<(cout, n);
// std::cout is of type std::ostream
// Is there an operator<<(std::ostream&, const Name&)

//What if I write Name::operator<<(std::ostream&)?
//That's a match n << std::cout;

// int a,b,c;
// a + b + c;
// operator+(operator+(a,b), c)

// std::cout << "My name is " << n;
// std::ostream operator<<(std::ostream operator<<(cout, "My Name is"), n);
// std::ostream operator<<(cout, "My Name is") is supposed to return cout  (std::ostream&)
// std::ostream  operator<<(cout, n);

/*
// what if I put operator<<(std::ostream& o) into Name
// operator<<(Name n, std::ostream& o)
 */
std::ostream& operator<< (std::ostream& ostr, const Name& n);
#endif
