#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
//solution for: https://cses.fi/problemset/task/1666

vector<vector<int>> adj(100001);
vector<bool> vis(100001);
 
void dfs(int node){
    if(vis[node]){
        return;
    }
    vis[node]=true;
    for(auto x : adj[node]){
        dfs(x);
    }
}
 
signed main(){
    int n,m; cin >> n >> m;
    for(int i=0 ; i < m ; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> ans;
    for(int i = 1; i <= n ; i++){
        if(!vis[i]){
            ans.push_back(i);
            dfs(i);
        }
    }
    cout << ans.size()-1 << endl;
    for(int i=1 ;i <ans.size() ; i++){
        cout << ans[i-1] << " " << ans[i] << endl;
    }
}
