//Rachel Hirmes
//stable marriage 
#include <iostream>
using namespace std;


bool ok(int q[], int col) {
	static int mp[3][3]={0,2,1, //man 0 prefernce
						 0,2,1, // man 1 prefernce
						 1,2,0};// man 2 prefernce
    static int wp[3][3]={2,1,0, 
    					 0,1,2,
    					 2,0,1};
    
    // nm=col, nw=q[col]
 for (int i=0; i<col; i++) {
        if (q[i]==q[col]) return false;

        /*
            mp[i][q[i]]=  how much ManI likes own wife
            mp[i][q[c]]= how much manI like man c's wife
            wp[q[i]][i]= how much manI's wife likes manI
            wp[q[i]][c]= how much manI's wife likes manC
            nm=c nw= qc
        */
        if (mp[i][q[col]] < mp[i][q[i]] && wp[q[col]][i] < wp[q[col]][col]) return false;
        if (mp[col][q[i]] < mp[col][q[col]] && wp[q[i]][col] < wp[q[i]][i]) return false;
    }
    return true;
}

void print(int q[]) {
	static int count = 0;
    cout << "Solution #" << ++count << ":\nMan\tWoman\n";

    for (int i = 0; i < 3; ++i)
    	cout << i << "\t" << q[i] << "\n";
   
    cout << "\n";
	}

int main () {
	int q[3];  
	int col=0;
	q[0]=0;

 	while (col<=3 & col>=0) {
        col++;
        if (col==3) {
            print (q);
            col--;
        }
        else q[col]=-1;
        
        while (col!= -1) {
            q[col]++;
            if (q[col]==3) {
                col--;
            }
            else if (ok (q, col)) break;
        }
    }
	return 0;
}