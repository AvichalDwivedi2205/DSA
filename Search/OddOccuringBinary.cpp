#include <iostream>
using namespace std;

// Function to find the index of the unique element in a sorted array
// where every other element appears exactly twice.
int binarySearch(int *arr, int size) {
    int s = 0, e = size - 1;
    int mid = s + (e - s) / 2;

    while (e >= s) {
        // If search space is reduced to one element, it must be the answer
        if (s == e)
            return s;

        // Check if mid is odd (bitwise AND with 1)
        if (mid & 1) { // true for odd index
            // If mid and its previous element are a matching pair
            if (mid - 1 >= 0 && arr[mid - 1] == arr[mid])
                s = mid + 1; // Unique element is to the right
            else
                e = mid - 1; // Unique element is to the left
        } else {
            // If mid and next element are a matching pair
            if (mid + 1 < size && arr[mid] == arr[mid + 1])
                s = mid + 2; // Unique element is further right
            else
                e = mid;     // Unique element is to the left or at mid
        }

        // Recalculate mid for the next iteration
        mid = s + (e - s) / 2;
    }

    // Element not found (should not reach here in a valid input)
    return -1;
}

int main() {
    int arr[] = {10, 10, 2, 5, 5, 2, 2, 5, 5, 20, 20, 11, 11};
    int index = binarySearch(arr, 13);
    if (index >= 0)
        cout << "Element found at index: " << index;
    else
        cout << "Element Not Found";
}
