#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>

using namespace std;

typedef pair<int, int> pairs;
vector<pairs> G[100000];

void min_span(int V) {
    int* keys = new int[V];
    int* parents = new int[V];
    bool* flags = new bool[V];
    
    priority_queue<pairs, vector<pairs>, greater<pairs> > Q;
    Q.push(make_pair(0, 0));

    for (int i = 0; i < V; ++i) {
        keys[i] = INT_MAX;
        parents[i] = 0;
        flags[i] = false;
    }

    do {
        int u = Q.top().second;
        Q.pop();
        flags[u] = true;

        for (int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i].first;
            int w = G[u][i].second;

            if (!flags[v] && w < keys[v]) {
                keys[v] = G[u][i].second;
                Q.push(make_pair(w, v));
                parents[v] = u;
            }
        }
    } while (!Q.empty());

    for (int i = 1; i < V; ++i) {
        cout << parents[i] << endl;
    }
}

int main() {
    int V;
    int E; 
    cin >> V;
    cin >> E;

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;

        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }

    min_span(V);
}