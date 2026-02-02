#include <bits/stdc++.h>

using namespace std;

int n, m;
int ans[10];
vector<int> v, arr;
void dfs(int cur_num, int start) {
    if(cur_num == m) {
        for(int i = 0; i < m; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    //
    for(int i = start; i < arr.size(); i++) {
        ans[cur_num] = arr[i];
        dfs(cur_num+1, i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;

    int tmp;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    arr.push_back(v[0]);
    for(int i = 1; i < v.size(); i++) {
        if(v[i-1] == v[i]) continue;
        arr.push_back(v[i]);
    }

    dfs(0, 0);
}