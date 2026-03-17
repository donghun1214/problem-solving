#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, tmp;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    for(auto i : v) {
        cout << i << '\n';
    }
}