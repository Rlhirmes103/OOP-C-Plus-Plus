#include <iostream>
using namespace std;

bool shiftEquivalent(int a[], int b[], int n) {
  int test;
  int y;
  for (int x = 0; x < n; x++) {
    test = 0;
	for (int s=0; s < n; s++){
		if (a[0]== b[s])
			y = s;
    for (int i = 0; i < n; i++, y++) {
         if (a[i] == b[(y) % n]) test++;
   	   }
	}
    if (test != n) return false;
  }
  return true;
}


int main () {
  int a[5] = {1, 2, 3, 4, 5};
  int b[5] = {3, 4, 5, 1, 2};
  if (shiftEquivalent(a, b, 5)) {
    cout << "These are equivalent." << endl;
  }
  else {
    cout << "These are not equivalent." << endl;
  }
  return 0;
}
