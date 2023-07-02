#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void print(vector<vector<int>> &arr, int i, int j) {
    if (i == j) {
        cout << "A" << (i - 1);
    }
    else {
        cout << "(";
        print(arr, i, arr[i][j]);
        print(arr, arr[i][j] + 1, j);
        cout << ")";
    }
}

void matrix_chain(int arr[], int size) {
    int m[size][size];
    vector <vector<int> > n;
    n.resize(size, vector<int>(size, 0));

    for (int i = 1; i < size; ++i) {
        m[i][i] = 0;
    }

    for (int i = 2; i < size; ++i) {
        for (int j = 1; j <= size - i + 1; ++j) {
            int p = i + j - 1;
            m[j][p] = INT_MAX;

            for (int k = j; k <= p - 1; ++k) {
                int q = m[j][k] + m[k+1][p] + (arr[j-1] * arr[k] * arr[p]);
                if (q < m[j][p]) {
                    m[j][p] = q;
                    n[j][p] = k;
                }
            }
        }
    }

    cout << m[1][size-1] << endl;
    print(n, 1, size - 1);
    cout << endl;
}

int main(int argc, char **argv) {
    // Stuff to input data from test files into array
    int* nums;
    int nums_size = 1;

    cin >> nums_size;
    nums = new int[nums_size+1];

    for (int i = 0; i <= nums_size; ++i) {
        cin >> nums[i];
    }

    matrix_chain(nums, nums_size + 1);    

    delete[] nums;
}