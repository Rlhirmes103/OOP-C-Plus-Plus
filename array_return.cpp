#include <iostream>

using namespace std;

int count_digits(int n);
int* return_an_array(int n);

int main() {
  int *a = return_an_array(23542); //array of size 5
  delete []a;

  return 0;
}

int count_digits(int n) {
  int count = 0;

  while (n > 0) {
    ++count;
    n /= 10;
  }

  return count;
}

int* return_an_array(int n) {
  int size = count_digits(n);
  int *arr = new int[size];

  for (int i = size-1; i >= 0; --i) {
    arr[i] = n % 10;
    n /= 10;
  }

  return arr;
}