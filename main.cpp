#include <bits/stdc++.h>
#define int long long
using namespace std;

//solution for: https://cses.fi/problemset/task/1192/

char adj[1000][1000];
bool vis[1000][1000];

void floodFill(int i, int j, int n, int m){
    //mark every .in the connected component true
    if(i<0 || i >= n || j <0 || j>= m || vis[i][j] || adj[i][j]=='#'){
        return; 
    }
    vis[i][j]=true;
    floodFill(i+1,j,n,m);
    floodFill(i-1,j,n,m);
    floodFill(i,j+1,n,m);
    floodFill(i,j-1,n,m);
}

signed main(){

    int n,m; cin >> n >> m;
    for(int i=0 ;i < n ; i ++){
        for(int j= 0 ; j < m ; j++){
            cin >> adj[i][j];
        }
    }
    int rooms=0;
    for(int i=0 ; i < n ; i++){
        for(int j=0 ; j < m ; j++){
            if(!vis[i][j] && adj[i][j]=='.'){
                rooms++;
                floodFill(i,j, n, m);
            }
        }
    }
    cout << rooms << endl;
}