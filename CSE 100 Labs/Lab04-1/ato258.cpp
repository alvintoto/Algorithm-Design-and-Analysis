#include <iostream>

using namespace std;

void heapify(int arr[], int index, int size) {
    // Initialize max as parent root index
    int max = index;

    // Left child index: arr[2i+1]
    int left = 2 * index + 1;

    // Right child index: arr[2i+2]
    int right = left + 1;

    // Set max as the largest between itself, left, and right indices
    if (left < size && arr[left] > arr[max]) {
        max = left;
    }

    if (right < size && arr[right] > arr[max]) {
        max = right;
    }

    // If max was left or right child, swap values then recurse until root is largest
    if (max != index) {
        int temp = arr[index];
        arr[index] = arr[max];
        arr[max] = temp;

        heapify(arr, max, size);
    }
}

void max_heap(int arr[], int size) {
    for (int i = (size / 2) - 1; i >= 0; --i) {
        heapify(arr, i, size);
    }
}

void heapSort(int arr[], int size) {
    // Turn array input into a max heap
    for (int i = (size / 2) - 1; i >= 0; --i) {
        heapify(arr, i, size);
    }
    
    // Swap largest value (arr[0] or root) to the end arr[n-i]
    for (int i = size - 1; i >= 0; --i) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Heapify while excluding the last indices arr[...n-i] to get new largest root
        heapify(arr, 0, i);
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

    max_heap(nums, nums_size);

    for (int i = 0; i < nums_size; ++i) {
        cout << nums[i] << ";";
    }   

    delete[] nums;
}