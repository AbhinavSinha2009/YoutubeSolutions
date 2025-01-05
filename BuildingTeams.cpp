#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
//solution for: https://cses.fi/problemset/task/1668

vector<vector<int>> adj(pow(10,5)+1);
vector<bool> vis(pow(10,5)+1);
vector<int> col(pow(10,5)+1); 
 
bool flag=false;
 
void dfs(int node){
    if(vis[node]){
        return;
    }
    if(col[node]==0){
        col[node]=1;
    }
    vis[node]=true;
    for(auto x : adj[node]){
        if(col[node]==1){
            if(col[x]==1){
                flag=true;
            }
            col[x]=2;
        } else {
            if(col[x]==2){
                flag=true;
            }
            col[x]=1;
        }
        dfs(x);
    }
}   
 
signed main(){
    // ifstream fin("inp.in");
    // ofstream fout("inp.out");
    int n,m; cin >> n >> m; 
    for(int i=0; i < m ; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1 ; i <= n ; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    if(flag){
        cout << "IMPOSSIBLE" << endl;
    } else {
        for(int i=1 ; i <= n ; i++){
            cout << col[i] << " ";
        } 
    }
}
