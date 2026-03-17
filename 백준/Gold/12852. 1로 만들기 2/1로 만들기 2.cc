#include <bits/stdc++.h>
using namespace std;

int dp[1000005];

void dfs(int n, vector<int> v) {
    if(n == 1) {
        for(auto i : v) {
            cout << i << ' ';
        }
        return;
    }

    int target = n-1;
    if(n % 3 == 0) {
        if(dp[target] > dp[n/3]) {
            target = n/3;
        }
    }
    if(n % 2 == 0) {
        if(dp[target] > dp[n/2]) {
            target = n / 2;
        }
    }
    v.push_back(target);
    dfs(target, v);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 2; i <=n; i++) {
        dp[i] = dp[i-1] + 1;
        if(i % 3 == 0)
            dp[i] = min(dp[i], dp[i/3] + 1);
        
        if(i % 2 == 0)
            dp[i] = min(dp[i], dp[i/2] + 1);
    }
    cout << dp[n] << '\n';

    vector<int> v;
    v.push_back(n);
    dfs(n, v);
}