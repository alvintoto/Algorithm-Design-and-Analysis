#include <iostream>

using namespace std;

int maxSubarray(int arr[], int low, int high) {
    // Base case return value
    if (low > high) {
        return 0;
    }

    // Calculate the middle index of array
    int mid = low + (high - low) / 2;

    // Calculate max subarray in the left half
    int left_max = maxSubarray(arr, low, mid-1);

    // Calculate max subarray in the right half
    int right_max = maxSubarray(arr, mid+1, high);

    // Need to calculate max subarray from middle index outwards
    
    // Get max subarray from mid to left
    int mid_left_max = 0;
    int mid_left_sum = 0;
    for (int i = mid-1; i >= low; i--) {
        mid_left_sum += arr[i];
        if (mid_left_sum > mid_left_max) {
            mid_left_max = mid_left_sum;
        }
    }

    // Get max subarray from mid to right
    int mid_right_max = 0;
    int mid_right_sum = 0;
    for (int i = mid+1; i <= high; i++) {
        mid_right_sum += arr[i];
        if (mid_right_sum > mid_right_max) {
            mid_right_max = mid_right_sum;
        }
    }

    // Return whichever left, right, or mid outwards subarray has the largest sum
    return max(max(left_max, right_max), mid_left_max + mid_right_max + arr[mid]);
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

    // Calculating then printing the maxSubarray output here
    cout << maxSubarray(nums, 0, nums_size-1);   

    delete[] nums;
}