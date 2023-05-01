// C++ program to print optimal parenthesization
// in matrix chain multiplication.
#include <bits/stdc++.h>
using namespace std;

// Function for printing the optimal
// parenthesization of a matrix chain product

//i and j: The starting and ending indices of the current segment of matrices.
//n: The total number of matrices in the expression.
//bracket: A 2D integer array of size n x n that contains the optimal split points for each segment of the expression. 
//name: A character reference that is used to assign a unique name to each intermediate matrix in the expression.
void printParenthesis(int i, int j, int n, int *bracket, char &name)
{
    // If only one matrix left in current segment
    if (i == j)
    {
        cout << name++;
        return;
    }

    cout << "(";

    // Recursively put brackets around subexpression
    // from i to bracket[i][j].
    printParenthesis(i, *((bracket + i * n) + j), n, bracket, name);

    // Recursively put brackets around subexpression
    // from bracket[i][j] + 1 to j.
    printParenthesis(*((bracket + i * n) + j) + 1, j, n, bracket, name);
    cout << ")";
}
// p--> array of matrix dimension
void matrixChainOrder(int p[], int n)
{
    // 0th row and 0th column of m[][] are not used
    int m[n][n];

    // bracket[i][j] stores optimal break point in
    // subexpression from i to j.
    int bracket[n][n];

    // cost is zero when multiplying one matrix.
    for (int i = 1; i < n; i++)
        m[i][i] = 0;
  
    // L is chain length.
    //Outer loop is for difference
    for (int L = 1; L < n ; L++)
    {
        for (int i = 1; i < n - L; i++)     //i will be for the rows (n-l becoz for the first time rows will be upto 3 only then upto 2 only)
        {
            int j = i + L;          //j is computed by adding difference and i
            m[i][j] = INT_MAX;      //?
            for (int k = i; k <= j - 1; k++)        //for finding minimum
            {
                // q = cost/scalar multiplications
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }

    // The first matrix is printed as 'A', next as 'B', and so on
    char name = 'A';
    cout << "Optimal Parenthesization is : ";
    printParenthesis(1, n - 1, n, (int *)bracket, name);
    cout << "\nOptimal Cost is : " << m[1][n - 1];
}

// Driver code
int main()
{
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    int arr[n];
    cout << "Enter the dimensions of the matrices:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Matrix " << i+1 << ": ";
        cin >> arr[i];
    }

    matrixChainOrder(arr, n);

    return 0;
}






