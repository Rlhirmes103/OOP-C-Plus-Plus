#include <iostream>

using namespace std;

typedef bool (*TEST)(int);
bool is_even(int n);
bool is_odd(int n);
int* return_matches(int a[], int& size, TEST t);
void print(int a[], int size);

int main() {
  int whatever[] = {4,5,6,7,8,9,1,2,3,4};
  int size = 10;
/
  int *a1 = return_matches(whatever, size, is_even);
  print(a1, size);
  
  size = 10;
  
  int *a2 = return_matches(whatever, size, is_odd);
  print(a2, size);

k  delete []a2;

  return 0;
}

bool is_even(int n) {
  return n % 2 == 0;
}

bool is_odd(int n) {
  return n % 2 == 1;
}

int* return_matches(int a[], int& size, TEST t) {
  int count = 0;
  for (int i  = 0; i < size; ++i)
    if ( t(a[i]) ) ++count;

  int *arr = new int[count];
  int k = 0;
  for (int i = 0; i < size; ++i)
    if ( t(a[i]) ) arr[k++] = a[i];

  size = count;
  return arr;
}

void print(int a[], int size) {
  for (int i = 0; i < size; ++i)
    cout << a[i] << " ";
  cout << endl;
}