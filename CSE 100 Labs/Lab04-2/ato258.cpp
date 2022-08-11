#include <iostream>

using namespace std;

int partition(int arr[], int low, int high) {
    // Initialize pivot to final element in the array
    int pivot = arr[high];

    // Initialize index to leftmost index subtracted by one
    int index = low - 1;

    // Loop through the array up to before the pivot
    for (int i = low; i <= high-1; ++i) {
        // If current (i) element is less than the pivot
        // Increment index then swap with smaller (index) element
        if (arr[i] <= pivot) {
            index++;
            swap(arr[i], arr[index]);
        }
    }

    // Place pivot at correct position by swapping it with positon after index
    swap(arr[index+1], arr[high]);

    // Return index position of the pivot element
    return index + 1;
}

int random_partition(int arr[], int low, int high) {
    // Generate a random index between low and high
    int random = low + rand() % (high - low);

    // Swap element at random index with highest index so that it's the pivot
    swap(arr[random], arr[high]);

    // Partition using the randomly indexed element as the pivot
    return partition(arr, low, high);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Get the finalized index of random pivot element
        int p = random_partition(arr, low, high);

        // Sort left side of the pivot
        quickSort(arr, low, p-1);

        // Sort right side of the pivot
        quickSort(arr, p+1, high);
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

    quickSort(nums, 0, nums_size-1);

    for (int i = 0; i < nums_size; ++i) {
        cout << nums[i] << ";";
    }   

    delete[] nums;
}