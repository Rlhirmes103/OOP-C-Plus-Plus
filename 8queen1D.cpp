#include <iostream>
using namespace std;

bool test(int q[], int c){
	 for(int i=0;i<c;i++){
		if(q[i]==q[c] || abs(q[c]-q[i])==(c-i))
			return false;
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
  		for (int r = 0; r < 8; r++) {
    		for (int c = 0; c < 8; c++) {
      			if (q[c] == r) cout << "1" << " ";
      			else cout << "0" << " ";
    			}
    			cout << endl;
 				}
}

int main(){
	int q[8];//1d array representing the chess board
	int c=0;//column index
	int count = 0;//count the # of solutions
	q[0]=0;

	while(c != -1){ ++c;
		if(c==8) {
			print(q, count);
			backtrack(c);
		}
		else q[c]=-1;
		while (c < 8) {
     		 q[c]++;
      if (q[c] == 8) backtrack(c);
      else if (test(q, c) == true) break;
    }
  }
return 0;
}
