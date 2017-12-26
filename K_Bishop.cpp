#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c, int n) {
    
    int r = q[c] / n;
    int col = q[c] % n;
    
    for (int i=0; i<c; i++) {
        int row = q[i] / n;
        int column = q[i] % n;
        if (q[i]==q[c] || abs(r-row)==abs(col-column)) return false;
    }
    
    return true;
}

int kbishops(int n, int k) {
    
    int* q = new int[k];
    q[0] = 0;
    q[1]=1;
    
    int c = 1, solutions = 0;
    
    while (c >= 0) {
        ++c;
        
        if (c == k) {
            ++solutions;
            --c;
        }
        else
            q[c] = q[c-1];
        
        while (c >= 0) {
            ++q[c];
        
            if (q[c] == n*n)
                --c;
            else if (ok(q, c, n))
                break;
        }
    }
    
    delete[] q;
    return solutions;
}

int main() {
    int n, k;
    
    while (true) {
        cout << "Enter value of n: ";
        cin >> n;
        if (n == -1)
            break;
        cout << "Enter value of k: ";
        cin >> k;
        cout << "number of solutions: " << kbishops(n, k) << "\n";
    }
    
    return 0;
}