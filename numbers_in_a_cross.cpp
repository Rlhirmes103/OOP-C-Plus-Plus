#include <iostream>
using namespace std;

bool ok(int q[], int c){
static int adjacent[8][5] = {
{-1}, //box 0
{0, -1}, //box 1
{0, 1, -1}, //box 2
{0, 2, -1}, //box 3
{1, 2, -1}, //box 4
{1, 2, 3, 4, -1}, //box 5
{2, 3, 5, -1}, //box 6
{4, 5, 6, -1} //box 7
};
 for(int i=0; i<c; i++){
        if(q[i]==q[c]) return false;
    }
	int i = 0;
  while (adjacent[c][i] != -1) {
    // the values in the adjacent box cant be consecutive thats why == 
    if (abs(q[adjacent[c][i]] - q[c]) == 1) return false;
    i++;
  }
  return true;
}
void backtrack(int &c){
	 c--;
  if (c == -1) exit(0);
}
void print(int q[], int &count){
	 count++;
	  	cout << "Solution # " << count << endl;
	  	int i = 0;
	  	for (int r = 0; r < 3; r++) {
    		for (int c = 0; c < 4; c++) {
    			if (((r == 0) && (c == 0))  || ((r == 0) && (c == 3)) || ((r == 2) && ( c == 0))  || ((r == 2) && ( c == 3))) cout << "  ";
      			else {
    			 cout << q[i] << " ";
       			 i++;
    			}
    		}
    		 cout << endl;
    	}
}

int main()
{
 int c = 0, q[8], count = 0, i = 0;
  q[0] = 1;
 while(c != -1){ ++c;
	if(c==8) {
		print(q, count);
		backtrack(c);
	}
 else q[c]=-1;
	while (c < 8) {
     	q[c]++;
      if (q[c] == 8) backtrack(c);
      else if (ok(q, c) == true) break;
    }
 }
	return 0;
}