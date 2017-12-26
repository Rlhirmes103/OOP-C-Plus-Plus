#include <iostream>
using namespace std;

int main() {
	int board [8][8] = {0};
	int count = 0;//count solutions found
	int r = 0; // row index
	int c = 0;//column index
	board[0][0] = 1;

nextColumn: c++; 
	if (c == 8)	goto print;
	r= -1;

nextRow: r++;
	if(r ==8) goto backtrack;	
//row testing
for (int i =0; i<c; i++){
    if (board[r][i] == 1) 
	   goto nextRow; 
}
//to chck up diaganols 
for(int i =1;(r-i)>=0 && (c-i)>=0; i++){
    if (board[r-i][c-i] == 1)
        goto nextRow;
}
//down diaganol
for (int i=1;(r+i)<8 && (c-i)>=0; i++){
    if (board[r+i][c-i]== 1)
        goto nextRow;
}
board[r][c]=1;
    goto nextColumn;    

backtrack:
    c--;
        if(c==-1) return 0;
    
    r=0;
while(board[r][c]!=1)
    r++;
    board[r][c]=0;
	   goto nextRow;

print:
    count++;
    cout<<"Solution #"<<count<<endl;
    for(int r=0;r<8;r++){
        for(int c=0;c<8;c++){
            if(board[r][c]==1)
                cout<<"q";
            else
                cout<<"-";
    }
                cout<<endl;
}
                cout<<endl;
  goto backtrack;
}
