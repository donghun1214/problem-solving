#include <bits/stdc++.h>
#define MAX 1000005

using namespace std;
vector<int> adj[MAX];
int dp[MAX][2], p[MAX];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int sz = n-1;
    while(sz--) {
        int a, b; 
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    
    
    queue<int> q; q.push(1);
    deque<int> dq;
    p[1] = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        dq.push_back(cur);
        for(auto i : adj[cur]) {
            if(i == p[cur]) continue;
            p[i] = cur;
            q.push(i);
        }
    }
    
    for(int i = n-1; i >= 0; i--) {
        int node = dq[i];
        dp[node][1] = 1;
        for(auto i : adj[node]){
            if(p[node] == i) continue;
            dp[node][0] += dp[i][1];
            dp[node][1] += min(dp[i][0], dp[i][1]);
        }
    }

    cout << min(dp[1][0], dp[1][1]);
    return 0;
}