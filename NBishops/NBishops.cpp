#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c, int n) {
   for (int i = 0; i < c; ++i)                       // For each previous bishop,
      if ((q[c]/n - q[i]/n) == abs(q[c]%n - q[i]%n)) // if the row difference is the same as the column difference, return false.
         return false;
   return true;
}

int kbishops(int n, int k) {
   int* q = new int[k];        // Each element is the position of a bishop, so the array is size k.
   q[0] = 0;
   int c = 0, solutions = 0;
   while (c >= 0) {
      ++c;
      if (c == k) {            // If you've placed all k bishops on the board, you've found a solution.
         ++solutions;
         --c;
      }
      else
         q[c] = q[c-1];        // When you move to the next bishop, start from the position of the previous bishop.
      while (c >= 0) {
         ++q[c];
         if (q[c] == n*n)      // If you run out of squares on which to place the current bishop, backtrack.
            --c;
         else if (ok(q, c, n)) // Pass n as a parameter so you can use it to calculate row and column numbers.
            break;
      }
   }
   delete [] q;
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