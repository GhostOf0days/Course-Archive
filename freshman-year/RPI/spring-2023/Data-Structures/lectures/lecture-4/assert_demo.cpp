#include <cassert>

//assert(condition)...
/*if(!condition){
 * cerr << "Condition failed!";
   exit(0);
   }
   */

int main(){
	//Infinite loop (x=5, 3, 1, -1, ...)
	for(int x=5; x!=0; x-=2){
		/* If this line is uncommented, then the program will crash
		 * when x<0 . If compiled with -g you will see the line number
		 * and filename. */
		assert(x>0);

		/* If the above line was commented out and the one below is
		 * uncommented, then the program will crash with x<0, but
		 * we will also have this string to help us understand the
		 * issue. You can put && "SOME DESCRPTIVE STRING" in your asserts
		 * so that you don't have to go back to your code to see what
		 * the assert was about... if you make the strings descriptive
		 * enough. */
		//assert(x>0 && "Great scott, we overshot!");
	}
	return 0;
}
