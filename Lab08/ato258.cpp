#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void cut_rod(int arr[], int size) {
    int revenue[size+1];
    int lengths[size+1];

    revenue[0] = 0;

    for (int i = 1; i <= size; ++i) {
        int q = 0;
        for (int j = 1; j <= i; ++j) {
            if (q < arr[j] + revenue[i-j]) {
                q = arr[j] + revenue[i-j];
                lengths[i] = j;
            }
        }
        revenue[i] = q;
    }

    // Print output
    for (int i = 0; i <= size; ++i) {
        cout << revenue[i] << endl;
    }
    while (size > 0) {
        cout << lengths[size] << " ";
        size -= lengths[size];
    }
    cout << "-1" << endl;
}

int main(int argc, char **argv) {
    // Stuff to input data from test files into array
    int* nums;
    int nums_size = 1;

    cin >> nums_size;
    nums = new int[nums_size+1];

    // Need first value of prices to be 0
    nums[0] = 0;

    for (int i = 1; i <= nums_size; ++i) {
        cin >> nums[i];
    }    

    cut_rod(nums, nums_size);

    delete[] nums;
}