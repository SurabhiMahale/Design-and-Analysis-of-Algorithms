#include <iostream>
using namespace std;

int fibonacci(int n) 
{
  // return the input n if it is 0 or 1, since the first two terms of the Fibonacci sequence are 0 and 1.
  if (n <= 1) 
  {
    return n;           
  }
  return fibonacci(n-1) + fibonacci(n-2);
}

int main() 
{
  int n;
  cout << "Enter the number of terms you want to display: ";
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << fibonacci(i) << " ";
  }
  return 0;
}

//display upto n number
// #include <iostream>
// using namespace std;

// void fibonacci(int t1, int t2, int n) {
//     int nextTerm = t1 + t2;
//     if (nextTerm > n) {
//         return;
//     }
//     cout << nextTerm << ", ";
//     fibonacci(t2, nextTerm, n);
// }

// int main() {
//     int t1 = 0, t2 = 1, n;

//     cout << "Enter a positive number: ";
//     cin >> n;

//     // displays the first two terms which is always 0 and 1
//     cout << "Fibonacci Series: " << t1 << ", " << t2 << ", ";

//     fibonacci(t1, t2, n);

//     return 0;
// }
// In this implementation, the fibonacci function takes three integer parameters: the first two terms t1 and t2 of the sequenc
