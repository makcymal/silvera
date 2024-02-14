#include <bits/stdc++.h>

using namespace std;

void floyd(vector<vector<int>> &graph) {
  int n = graph.size();
  auto dist(graph);
  for (int i = 0; i < n; ++i) dist[i][i] = 0;
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dist[i][k] != INT32_MAX and dist[k][j] != INT32_MAX and
            dist[i][j] < dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          dist[j][i] = dist[i][j];
        }
      }
    }
  }
}