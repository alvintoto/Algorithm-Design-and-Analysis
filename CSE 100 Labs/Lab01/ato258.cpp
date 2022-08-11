#include <iostream>

using namespace std;

// Function for insertion sort algorithm here
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int temp;
        int j = i;

        // Swap array values if not sorted
        while (arr[j-1] > arr[j] && j > 0) {
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;

            j = j - 1;
        }

        // Print after each sorting sequence
        for (int k = 0; k <= i; ++k) {
            cout << arr[k] << ";";
        }

        cout << endl;
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

    // Insertion sort the array here
    insertionSort(nums, nums_size);    

    delete[] nums;
}