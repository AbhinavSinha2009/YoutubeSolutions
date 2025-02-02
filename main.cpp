#include <bits/stdc++.h>
#define int long long

using namespace std;

ifstream fin("loan.in");
ofstream fout("loan.out");

bool works(int x, int n, int m, int k){
    int g=0,days=0;
    while(g<n && days<k){
        int y=(n-g)/x;
	    int r=min((n-x*y-g)/y+1,k-days);
        if(y>m){
            g+=y*r;
            days+=r;
        } else {
            g+=m*(k-days);
            days=k;
        }
    }
    return g>=n && days<=k;
}

signed main(){
   int n,m,k; fin >> n >> k >> m;
   int low=1, high=n,ans=-1;
   while(low<=high){
    int mid=low+(high-low)/2;
    if(works(mid,n,m,k)){
        ans=mid;
        low=mid+1;
    } else {
        high=mid-1;
    }
   }
   fout << ans << endl;
} 