#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

vector<int> adj[20005];
int dis[20005];
int u, v, node, step;
queue<pair<int,int> > q;

int solution(int n, vector<vector<int>> edge) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    
    for(auto edg: edge){
        u = edg[0]; 
        v = edg[1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    q.push({1, 0}); dis[1] = -1;
    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        node = cur.X; 
        step = cur.Y;
        for(auto nxt: adj[node]){
            if(dis[nxt] != 0) continue;
            q.push({nxt, step+1});
            dis[nxt] = step+1;
        }
    }
    
    int mx = 0;
    for(int i = 1; i <= n; i++){
        if(mx < dis[i]) mx = dis[i];
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(dis[i] == mx) cnt ++;
    }
    
    return cnt;
}