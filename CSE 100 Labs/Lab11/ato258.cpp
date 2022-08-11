#include <iostream>
#include <map>

using namespace std;

map<pair<int, int>, int> points;
map<pair<int, int>, int>::iterator itr;
map<pair<int, int>, int>::iterator itr2;

int max_sum() {
    int max = 0;
    int flag = false;

    for (itr = points.begin(); itr != points.end(); ++itr) {
        pair<int, int> diagonal = make_pair(itr->first.first - 1, itr->first.second - 1);
        itr2 = points.find(diagonal);
        if (itr2 != points.end()) {
            flag = true;
            if (itr->second > max) {
                max = itr->second;
            }
        }
        else {
            continue;
        }
    }
        
    if (!flag) return -1;
    return max;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;

        pair<int, int> point = make_pair(a, b);
        pair<pair<int, int>, int> entry = make_pair(point, point.first + point.second);
        points.insert(entry);
    }

    cout << max_sum();
}