

#include <iostream>
using namespace std;

// Function to find the pivot index (maximum element's index) in a rotated sorted array
int PivotIndex(int *arr, int size) {
    int s = 0, e = size - 1;
    int mid = s + (e - s) / 2;
    int index = -1;  // Default index in case no pivot is found

    // Binary search loop
    while (e >= s) {
        // If only one element is left, it's the pivot in a 1-element array
        if (s == e) {
            index = s;
            break;
        }

        // Check if mid is the pivot point (where previous element is greater)
        if (mid > 0 && arr[mid] < arr[mid - 1]) {
            index = mid - 1;
            break;
        }

        // Check if mid itself is the pivot point (greater than next element)
        if (mid < size - 1 && arr[mid + 1] < arr[mid]) {
            index = mid;
            break;
        }

        // If start is greater than mid, pivot must lie in the left half
        if (arr[s] > arr[mid])
            e = mid;
        else
            // Otherwise, pivot is in the right half
            s = mid + 1;

        // Recalculate mid
        mid = s + (e - s) / 2;
    }

    // Return the pivot index
    return index;
}

int main() {
    int arr[] = {1}; // Input array (can be rotated)
    int index = PivotIndex(arr, 1);
    
    if (index >= 0)
        cout << "Pivot Index is: " << index;
    else
        cout << "Not Pivot Index";
}
