#include <iostream>
#include <vector>

template <class T>
bool binsearch(const std::vector<T> &v, int low, int high, const T &x) {
  if (high == low) return x == v[low];
  int mid = (low+high) / 2;
  if (x <= v[mid])
    return binsearch(v, low, mid, x);
  else
    return binsearch(v, mid+1, high, x);


//Code for exercise 8.19
/*
if ( x < v[mid] )
  return binsearch( v, low, mid-1, x );
else
  return binsearch( v, mid, high, x );
*/
}
template <class T>
bool binsearch(const std::vector<T> &v, const T &x) {
  return binsearch(v, 0, v.size()-1, x);
}

int main(){
	std::vector<int> v;
	v.push_back(-1); v.push_back(3); v.push_back(5); v.push_back(6);
	std::vector<int> z;
	z.push_back(-1); z.push_back(3); z.push_back(6);

	if(binsearch(v,-2)){
		std::cout << "v has -2" << std::endl;
	}
	else{
		std::cout << "v no has -2" << std::endl;
	}

	if(binsearch(z,-2)){
		std::cout << "z has -2" << std::endl;
	}
	else{
		std::cout << "z no has -2" << std::endl;
	}

	if(binsearch(v,-1)){
		std::cout << "v has -1" << std::endl;
	}
	else{
		std::cout << "v no has -1" << std::endl;
	}

	if(binsearch(z,-1)){
		std::cout << "z has -1" << std::endl;
	}
	else{
		std::cout << "z no has -1" << std::endl;
	}

	if(binsearch(v,2)){
		std::cout << "v has 2" << std::endl;
	}
	else{
		std::cout << "v no has 2" << std::endl;
	}

	if(binsearch(z,2)){
		std::cout << "z has 2" << std::endl;
	}
	else{
		std::cout << "z no has 2" << std::endl;
	}

	if(binsearch(v,3)){
		std::cout << "v has 3" << std::endl;
	}
	else{
		std::cout << "v no has 3" << std::endl;
	}

	if(binsearch(z,3)){
		std::cout << "z has 3" << std::endl;
	}
	else{
		std::cout << "z no has 3" << std::endl;
	}

	if(binsearch(v,6)){
		std::cout << "v has 6" << std::endl;
	}
	else{
		std::cout << "v no has 6" << std::endl;
	}

	if(binsearch(z,6)){
		std::cout << "z has 6" << std::endl;
	}
	else{
		std::cout << "z no has 6" << std::endl;
	}

	return 0;
}
