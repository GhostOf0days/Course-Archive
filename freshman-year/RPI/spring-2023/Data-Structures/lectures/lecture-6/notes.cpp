
int n; //Size of array
double* a = new double[n]; //Already initialized with values

//don't worry about pointer pass by reference YET
void double_array(double*& a, int n){
	//Allocate array of size 2*n in temp
	double* tmp = new double[2*n];

	//Copy the n values from a to tmp
	for(int i=0; i<n; i++){
		tmp[i] = a[i];
	}

	//Delete array a
	delete [] a;

	//Assign tmp to a
	a = tmp;
}
//At the end of the function, "tmp" is automatically cleaned up from the stack...
// BUT whatever tmp points to, is NOT cleaned up automatically






double ** a = new double[rows][cols]; //doesn't compile





//Code to delete 2D array

//delete inner "rows"
for(int k=0; k<rows; k++){
	delete [] a[k];
}

//delete outer array
delete [] a;

//can't do
delete [][] a;

