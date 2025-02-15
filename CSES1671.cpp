#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define int long long

using namespace std;

//https://cses.fi/problemset/task/1671/

struct Edge {
    int destination;
    int weight;
};

vector<int> dijkstra(vector<vector<Edge>>& adj, int src) {
    int n=adj.size();
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(n,LONG_LONG_MAX);
    dist[src]=0;
    pq.push({0,src});
    while (!pq.empty()) {
        int distnode=pq.top().first, node=pq.top().second;
        pq.pop();
        if (distnode>dist[node]){continue;}
        for (Edge it : adj[node]) {
            int neighbor=it.destination, weight=it.weight;
            if (distnode+weight<dist[neighbor]) {
                dist[neighbor]=distnode+weight;
                pq.push({dist[neighbor],neighbor});
            }
        }
    }
    return dist;
}

signed main() {
    int n,m; cin >> n >> m;
    vector<vector<Edge>> graph(n);
    for (int i=0 ; i < m; i++) {
        int a,b,c; cin >> a >> b >> c;
        a--; b--;
        graph[a].push_back({b, c});
    }
    int src = 0;
    vector<int> dist = dijkstra(graph, src);
    for (int i = 0; i < n; i++) {
            cout << dist[i] << " ";
    }
    cout << endl;
}
