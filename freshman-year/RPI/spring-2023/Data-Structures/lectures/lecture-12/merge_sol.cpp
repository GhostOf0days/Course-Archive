#include <iostream>
#include <vector>
using namespace std;

template <class T> void mergesort(vector<T>& values);
template <class T> void mergesort(int low, int high, vector<T>& values, vector<T>& scratch);
template <class T> void merge(int low, int mid, int high, vector<T>& values, vector<T>& scratch);

int main() {
  vector<double> pts(7);
  pts[0] = -45.0;  pts[1] =   89.0;  pts[2] =    34.7;  pts[3] =   21.1;
  pts[4] =   5.0;  pts[5] =  -19.0;  pts[6] =  -100.3; 

  mergesort(pts);

  for (unsigned int i=0; i<pts.size(); ++i)
    cout << i << ": " << pts[i] << endl;
}

// The driver function for mergesort.  It defines a scratch vector for temporary copies.  
template <class T>
void mergesort(vector<T>& values) {
  vector<T> scratch(values.size());
  mergesort(0, int(values.size()-1), values, scratch);
}

// Here's the actual merge sort function.  It splits the vector in
// half, recursively sorts each half, and then merges the two sorted
// halves into a single sorted interval.
template <class T>
void mergesort(int low, int high, vector<T>& values, vector<T>& scratch) {
  cout << "mergesort:  low = " << low << ", high = " << high << endl;
  if (low >= high)  //  intervals of size 0 or 1 are already sorted!
    return;
  
  int  mid = (low + high) / 2;
  mergesort(low, mid, values, scratch);
  mergesort(mid+1, high, values, scratch);
  merge(low, mid, high, values, scratch);
}

// Non-recursive function to merge two sorted intervals (low..mid & mid+1..high) 
// of a vector, using "scratch" as temporary copying space.  
template <class T> 
void merge(int low, int mid, int high, vector<T>& values, vector<T>& scratch) {

  // some output so we can watch how merge sort works
  cout << "merge:  low = " << low << ", mid = " << mid << ", high = " << high << endl;
  int i=low, j=mid+1, k=low;
  // int p;
  /*
  cout << "LOW INTERVAL:     ";
  for (int p = low; p <= mid; p++) 
    cout << values[p] << " ";
  cout << endl << "HIGH INTERVAL:    ";
  for (int p = mid+1; p <= high; p++) 
    cout << values[p] << " ";
  cout << endl;
  */
  
  // while there's still something left in one of the sorted subintervals...
  while (i <= mid && j <= high) {
    // look at the top values, grab the smaller one, store it in the scratch vector
    if (values[i] < values[j]) {
      scratch[k] = values[i];
      ++i;
    } else {
      scratch[k] = values[j];
      ++j;
    }
    ++k;
  }
 
  // Copy the remainder of the interval that hasn't been exhausted
  // Note: only one of for loops will do anything (have a non-zero index range)
  for ( ; i<=mid; ++i, ++k ) scratch[k] = values[i];  // low interval
  for ( ; j<=high; ++j, ++k ) scratch[k] = values[j]; // high interval

  // Copy from scratch back to values
  for (int l=low; l<=high; ++l ) values[l] = scratch[l];

  // observe how the interval has been sorted correctly
  /*
  cout << "SORTED INTERVAL:  ";
  for (int p = low; p <= high; p++) 
    cout << values[p] << " ";
  cout << endl;
  */

}
