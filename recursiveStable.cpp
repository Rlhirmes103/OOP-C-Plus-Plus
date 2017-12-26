#include <iostream>
#include <cmath>
using namespace std;

bool ok(int* q, int col) {
	static int mp[3][3]={0,2,1, //man 0 prefernce
						 0,2,1, // man 1 prefernce
						 1,2,0};// man 2 prefernce
    static int wp[3][3]={2,1,0, 
    					 0,1,2,
    					 2,0,1};
    
    // nm=col, nw=q[col]
 for (int i=0; i<col; i++) {
        if (q[i]==q[col]) return false;

        if (mp[i][q[col]] < mp[i][q[i]] && wp[q[col]][i] < wp[q[col]][col]) return false;
        if (mp[col][q[i]] < mp[col][q[col]] && wp[q[i]][col] < wp[q[i]][i]) return false;
    }
    return true;
}

void print(int* q) {
	static int count = 0;
    cout << "Solution #" << ++count << ":\nMan\tWoman\n";

    for (int i = 0; i < 3; ++i)
    	cout << i << "\t" << q[i] << "\n";
   
    cout << "\n";
	}


void move(int* q, int col){
        if (col==3) {
            print (q);
            return;
        }
        for (int j = 0; j < 3; ++j) {
            q[col]=j;
            if (ok (q, col)) move(q, col + 1);
        }
}


    int main () {
    int q[3];  
    move(q, 0);
    system("pause");
}