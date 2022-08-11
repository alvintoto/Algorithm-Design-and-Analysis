#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(vector<int>* G, bool* seen, vector<int> &f, int v) {
    seen[v] = true;

    for (int i = 0; i < G[v].size(); ++i) {
        if (!seen[G[v][i]]) {
            DFS(G, seen, f, G[v][i]);
        }
    }

    f.push_back(v);
}

int main() {
    int V; 
    int E; 
    cin >> V;
    cin >> E;

    vector<int>* G = new vector<int>[V];
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }

    vector<int>* GT = new vector<int>[V];
    for(int i = 0; i < V; i++){
        for(int j = 0; j < G[i].size(); j++) {
            int u = i;
            int v = G[i][j];
            GT[v].push_back(u);
        }
    }

    vector<int> f;
    bool* seen = new bool[V];
    for (int i = 0; i < V; ++i) {
        if (!seen[i]) {
            DFS(G, seen, f, i);
        }
    }

    for (int i = 0; i < V; ++i) {
        seen[i] = false;
    }

    reverse(f.begin(), f.end());

    vector< vector <int> > scc;
    for (int i = 0; i < f.size(); ++i) {
        if (!seen[f[i]]) {
            vector<int> v;
            DFS(GT, seen, v, f[i]);
            scc.push_back(v);
        }
    }

    int* res = new int[V];
    for (int i = 0; i < V; ++i) {
        res[i] = i;
    }
    
    for (int i = 0; i < scc.size(); ++i) {
        for (int j = 0; j < scc[i].size(); ++j) {
            int sccid = scc[i][j];
            for (int k = 0; k < V; ++k) {
                if (res[k] == sccid) {
                    res[k] = *min_element(scc[i].begin(), scc[i].end());
                }
            }
        }
    } 

    for (int i = 0; i < V; ++i) {
        cout << res[i] << endl;
    }
}