#include <iostream>

using namespace std;

void merge(int arr[], int low, int mid, int high) {
    // Temp for left side of array
    int left_arr[mid-low+1];

    // Temp for right side of array
    int right_arr[high-mid];

    // Filling in temp for left side values
    for (int i = 0; i < mid-low+1; ++i) {
        left_arr[i] = arr[low+i];
    }

    // Filling in temp for right side values
    for (int i = 0; i < high-mid; ++i) {
        right_arr[i] = arr[mid+1+i];
    }

    // Counter indices for temp and original arrays
    int left_index = 0;
    int right_index = 0;
    int orig_index = low;

    // While indices are less than their array size
    while (left_index < mid-low+1 && right_index < high-mid) {
        // Swap values when one is greater than the other
        if (left_arr[left_index] <= right_arr[right_index]) {
            arr[orig_index++] = left_arr[left_index++];
        }
        else {
            arr[orig_index++] = right_arr[right_index++];
        }
    }

    // Copy leftover values from temp to original array
    while (left_index < mid-low+1) {
        arr[orig_index++] = left_arr[left_index++];
    }

    while (right_index < high-mid) {
        arr[orig_index++] = right_arr[right_index++];
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        // Calculate midpoint index of the array
        int mid = low + (high - low) / 2;

        // Sort the left half
        mergeSort(arr, low, mid);

        // Sort the second half
        mergeSort(arr, mid+1, high);

        // Merge the sorted arrays
        merge(arr, low, mid, high);
    } 
} 

int main(int argc, char **argv) {
    // Stuff to input data from test files into array
    int* nums;
    int nums_size = 1;

    cin >> nums_size;
    nums = new int[nums_size];

    for (int i = 0; i < nums_size; ++i) {
        cin >> nums[i];
    }

    // Merge sort function here
    mergeSort(nums, 0, nums_size-1);

    // Print the values of the array
    for (int i = 0; i < nums_size; ++i) {
        cout << nums[i] << ";";
    }

    delete[] nums;
}