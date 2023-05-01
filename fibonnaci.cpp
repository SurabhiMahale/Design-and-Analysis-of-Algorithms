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
