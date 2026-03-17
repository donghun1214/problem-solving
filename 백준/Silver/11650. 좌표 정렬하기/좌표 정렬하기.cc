#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
    if(a.first == b.first) return a.second < b.second;
    else 
        return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<int, int> > v;
    int n, a, b;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), cmp);

    for(auto i : v) {
        cout << i.first << ' ' << i.second << '\n';
    }
}
