#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<int,int> > v;
    int n, L, tmp;
    cin >> n >> L;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        v.push_back({tmp, i});
    }

    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        pq.push(v[i]);
        while(pq.top().second < i-L+1)
            pq.pop();
        ans.push_back(pq.top().first);
    }

    for(auto i : ans) {
        cout << i << ' ';
    }
}