#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(vector<int>* G, bool* seen, vector<int> &f, int v){
  seen[v] = true;

  for (int i = 0; i < G[v].size(); ++i) {
    if (!seen[G[v][i]]) {
      DFS(G, seen, f, G[v][i]);
    }
  }

  f.push_back(v);
}

void DFS2(vector<int>* G, bool* seen, vector<int> &scc, int v){
  seen[v] = true;

  for (int i = 0; i < G[v].size(); ++i) {
    if (!seen[G[v][i]]) {
      scc.push_back(v);
      DFS2(G, seen, scc, G[v][i]);
    }
  }
}

int* argsort(vector<int> &f) {
  int* arr = new int[f.size()];
  vector <pair<int, int>> v;

  for (int i = 0; i < f.size(); ++i) {
    v.push_back(make_pair(f[i], i));
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < f.size(); ++i) {
    arr[i] = v[i].second;
  }

  return arr;
}

int main(){

  int V; // no. of vertices
  int E; // no. of edges
  cin>>V;
  cin>>E;

  vector<int>* G = new vector<int>[V];
  for(int i = 0; i < E; i++){
    int u,v;
    cin>>u>>v;
    G[u].push_back(v);
  }

  vector<int>* GT = new vector<int>[V];
  for(int i = 0; i < V; i++){
    for(int j = 0; j < G[i].size(); j++){
      int u = i;
      int v = G[i][j];
      GT[v].push_back(u);
    }
  }

  bool* seen = new bool[V];
  vector<int> f;
  for(int i = 0; i < V; i++){
    if(!seen[i]){
       DFS(G, seen, f, i);
    }
  }

  //              0  1  2  3  4
  // argsort f = [3, 9, 4, 2, 5]
  // sort:  [2, 3, 4, 5, 9]
  // asort: [3, 0, 2, 4, 1]
  // modify sorting, you can built-in function to do argsort
  int* af = argsort(f);
  int* res = new int[V];

  for (int i = 0; i < V; ++i) {
    seen[i] = false;
  }

  for(int i = 0; i < V; i++){
    int v = af[i];
    if(!seen[v]){
      vector<int> scc;
      DFS2(G, seen, scc, v);
      int sccid = *min_element(scc.begin(), scc.end());
      for(int u : scc){
         res[u] = sccid;
      }
    }
  }

  for(int i = 0; i < V; i++){
    cout << res[i] << endl;
  }

  return 0;
}