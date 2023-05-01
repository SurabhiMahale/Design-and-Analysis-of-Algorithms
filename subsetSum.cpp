#include <iostream>

using namespace std;

// Function to print the subset
void printSubset(int subset[], int size) {
    for (int i = 0; i < size; i++) 
    {
        cout << subset[i] << " ";
    }
    cout << endl;
}

// arr: the input array of integers
// subset: an array used to store the current subset
// index: the current index in the array
// n: the length of the input array
// target: the target sum we are trying to achieve
// sum: the sum of the current subset
// size: the size of the current subset

// Function to find subsets with sum equal to target using backtracking
void subsetSum(int arr[], int subset[], int index, int n, int target, int sum, int size) {
    // If the current subset has the sum equal to target, print it
    if (sum == target) {
        printSubset(subset, size);
        return;
    }
    
    // If the sum is greater than the target or all elements have been processed, backtrack
    if (sum > target || index == n) {
        return;
    }
    
    // Include the current element and try to find the subset with the sum equal to target
    subset[size] = arr[index];
    subsetSum(arr, subset, index+1, n, target, sum+arr[index], size+1);
     
    // Exclude the current element and try to find the subset with the sum equal to target
    subsetSum(arr, subset, index+1, n, target, sum, size);
}

int main() {
    int n, target;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target sum: ";
    cin >> target;

    int subset[n];
    // Find subsets with sum equal to target
    subsetSum(arr, subset, 0, n, target, 0, 0);

    return 0;
}
