/*
this problem is unsolvable.  I tessted that in the while loop if either of the numbers are even to continue to increment.  Therefore, if both are odd it will print the square.  
Since this isn't possible after testing 100000000 numbers the program will print that this number doesnt exist.
*/

#include <iomanip>
#include <iostream>
using namespace std;

int main() {
long long i = 10;

while (i < 100000000){
	if ((i*i)%2 == 0 || ((i*i)/10)%2 == 0)
		{
			i++;
		}
	else 
	cout << (i*i) << endl;
}

 
	cout << "this doesn't exist" << endl;

  return 0;
}