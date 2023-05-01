#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
    int leftSize = mid - low + 1;
    int rightSize = high - mid;
    int left[leftSize], right[rightSize];

    for (int i = 0; i < leftSize; i++)         //copying into left subarray
        left[i] = arr[low + i];
    for (int i = 0; i < rightSize; i++)        //copying into right subarray
        right[i] = arr[mid + i + 1];

    int i = 0, j = 0, k = low;                 // initial indexes of arrays
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];   
        else
            arr[k++] = right[j++];
    }
    while (i < leftSize)                       //copying remaining elements
        arr[k++] = left[i++];  
    while (j < rightSize)
        arr[k++] = right[j++];
}

void mergeSort(int arr[], int low, int high) {
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main() {
    int arr[] = {9, 5, 7, 3, 1, 8, 6, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
