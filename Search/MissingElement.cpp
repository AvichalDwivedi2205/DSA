#include <iostream>          // For input/output operations
using namespace std;

// Function to find the index of the missing element in a sorted array
int MissingElement(int *arr, int size){
    int s = 0, e = size - 1;                 // s = start index, e = end index
    int mid = s + (e - s) / 2;              // Calculate initial middle index
    int index = 2147483647;                 // Initialize index to max int (acts like infinity)

    // Binary search loop
    while(e >= s){
        // If value at mid is equal to expected value (index+1), missing is in the right half
        if(arr[mid] == mid + 1){
            s = mid + 1;
        }
        // If value at mid is greater than expected (index+2), missing is in the left half
        if(arr[mid] == mid + 2){
            e = mid - 1;
            index = min(index, mid);       // Update index to the smallest possible missing location
        }
        // Update mid for next iteration
        mid = s + (e - s) / 2;
    }
    return index;                           // Return the index where the missing number should be
}

int main(){
    // Example sorted array with one missing element (3)
    int arr[] = {1, 2, 4, 5, 6, 7, 8, 9};
    
    // Call function with array and its size
    int index = MissingElement(arr, 8);

    // Output result
    if(index >= 0)
        cout << "Element found at index: " << index;
    else
        cout << "Element Not Found";
}
