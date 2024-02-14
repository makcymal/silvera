#include <bits/stdc++.h>

using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int root) {
    int n = graph.size();
    vector<int> dist(n, INT32_MAX);
    dist[root] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, root);

    while (!pq.empty()) {
        while (!pq.empty() and dist[pq.top().second] <= pq.top().first)
            pq.pop();
        if (pq.empty()) continue;

        auto [d, v] = pq.top();
        pq.pop();
        dist[v] = d;
        for (auto adj : graph[v]) pq.emplace(d + adj.second, adj.first);
    }

    return dist;
}