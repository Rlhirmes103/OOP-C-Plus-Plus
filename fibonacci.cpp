#include<iostream>
using namespace std;

long fib(int n){
	static int f[70]={0,1,1,2};
if(n==1 || n==2) return 1;

f[n] =f[n-1]+f[n-2];
return f[n];
};

int main(){
for(int i=1; i<=70; i++)
cout<<" fib("<<i<<") = "<<fib(i)<<endl;\

return 0;
}