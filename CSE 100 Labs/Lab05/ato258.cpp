#include <iostream>
#include <vector>

using namespace std;

void countingSort(vector<int> arr[], int row, int col) {
    // Temp matrix for output
    vector<int> *temp;
    temp = new vector<int>[row];

    // Array of size 4 because we only need to count {0,1,2,3}
    int counter[4];
    for (int i = 0; i < 4; ++i) {
        counter[i] = 0;
    }

    // Count the number of each value in a column and store them
    for (int i = 0; i < row; ++i) {
        counter[arr[i][col]]++;
    }

    // Store the cumulative sum of the elements
    for (int i = 1; i < 4; i++) {
        counter[i] += counter[i-1];
    }

    // Place elements in correct order by subtracting 1 from counter element and using that as index for temp
    // Decrease count by 1 so that repeated elements don't overlap with each other
    for (int i = row - 1; i >= 0; --i) {
        temp[counter[arr[i][col]] - 1] = arr[i];
        counter[arr[i][col]]--;
    }

    // Copy from temp array to original array
    for (int i = 0; i < row; ++i) {
        arr[i] = temp[i];
    }
}

void radixSort(vector<int> arr[], int row, int col) {
    // Iterate through each column and perform counting sort on its values
    for (int i = col - 1; i >= 0; --i) {
        countingSort(arr, row, i);
    }
}

int main(int argc, char **argv) {
    // Stuff to input data from test files into array
    int nums_size = 1;
    cin >> nums_size;

    // Create maxtrix of size n x 10 (array of vectors of size 10)
    vector<int> *nums;
    nums = new vector<int>[nums_size];

    for (int i = 0; i < nums_size; ++i) {
        for (int j = 0; j < 10; ++j) {
            int input;
            cin >> input;
            nums[i].push_back(input);
        }
    }    

    radixSort(nums, nums_size, 10);

    for (int i = 0; i < nums_size; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << nums[i][j] << ";";
        }
        cout << endl;
    }

    delete[] nums;
}