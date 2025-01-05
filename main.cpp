#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<vector<int>> adj(pow(10,5)+1);
vector<bool> vis(pow(10,5)+1);
vector<int> col(pow(10,5)+1);

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
            col[x]=2;
        } else {
            col[x]=1;
        }
        dfs(x);
    }
}

signed main(){
    int n; cin>> n;

    for(int i= 1 ; i <= n-1 ; i++){
        int a,b; cin >> a >>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    for(int i= 1; i<= n ; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    int blue=0,red=0;
    for(int i = 1; i <= n ; i++){
        if(col[i]==1){
            blue++;
        } else {
            red++;
        }
    }
    cout << blue*red-n+1 << endl;
}