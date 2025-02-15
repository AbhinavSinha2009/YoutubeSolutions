#include <bits/stdc++.h>
#define int long long

using namespace std;
/*
https://codeforces.com/problemset/problem/2062/C

when i was initially solving this problem, i thought brute force would be sufficient based on the constraints, even though it was, my brute force was too slow. so then i implemented dp and reduced the time complexity on each vector to reduce the time complexity and solved the problem.
*/
vector<int> diff(vector<int> a)
{
    vector<int> b;
    for (int i = 0; i < a.size() - 1; i++)
    {
        b.push_back(a[i + 1] - a[i]);
    }
    return b;
}

vector<int> rev(vector<int> a)
{
    vector<int> b = a;
    int low = 0, high = b.size() - 1;
    while (low < high)
    {
        int tmp = b[low];
        b[low] = b[high];
        b[high] = tmp;
        low++;
        high--;
    }
    return b;
}
map<vector<int>, int> dp;
int solve(vector<int> aa)
{
    vector<int> a = aa;
    if (a.size() == 1)
    {
        return a[0];
    }
    if (dp.find(a) != dp.end())
    {
        return dp[a];
    }
    int sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];
    }
    vector<int> revDif;
    for (int i = a.size() - 1; i > 0; i--)
    {
        revDif.push_back(a[i - 1] - a[i]);
    }
    vector<int> dif = diff(a);
    vector<int> difRev = rev(dif);
    return dp[a] = max(sum, max(solve(difRev), max(solve(revDif), solve(dif))));
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << solve(a) << endl;
    }
}
