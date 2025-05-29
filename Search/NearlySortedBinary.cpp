#include <iostream>
using namespace std;

// Modified binary search function for a nearly sorted array
int binarySearch(int *arr, int size, int ele){
    int s = 0, e = size - 1;
    int mid = s + (e - s) / 2;
    int index = -1; // Default value if element not found

    // Continue searching while the search space is valid
    while (e >= s) {
        // Check if mid is the target
        if (arr[mid] == ele) {
            index = mid;
            break;
        }
        // Check left neighbor (since element may be one position off)
        else if (mid - 1 >= 0 && arr[mid - 1] == ele) {
            index = mid - 1;
            break;
        }
        // Check right neighbor
        else if (mid + 1 < size && arr[mid + 1] == ele) {
            index = mid + 1;
            break;
        }

        // If target is greater than mid, skip two positions ahead (since mid+1 already checked)
        if (ele > arr[mid]) {
            s = mid + 2;
        }
        // If target is less than mid, skip two positions back (since mid-1 already checked)
        else {
            e = mid - 2;
        }

        // Update mid for the next iteration
        mid = s + (e - s) / 2;
    }

    // Return the found index, or -1 if not found
    return index;
}

int main() {
    // Nearly sorted array (each element can be misplaced by 1 position)
    int arr[] = {20, 10, 30, 50, 40, 70, 60, 90, 80, 100};
    
    // Search for the element 100
    int index = binarySearch(arr, 10, 100);

    // Output result
    if (index >= 0)
        cout << "Element found at index: " << index;
    else
        cout << "Element Not Found";
}
