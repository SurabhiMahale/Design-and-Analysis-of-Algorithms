#include <iostream>
using namespace std;
void printArray(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void insertion_sort(int n, int arr[])
{
    cout << "Insertion Sort " << endl;
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 and arr[j] < arr[j - 1])
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
    printArray(n, arr);
}
int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Sort: " << endl;
    printArray(n, arr);
    insertion_sort(n, arr);
    return 0;
}
