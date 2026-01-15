#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    
    stack<pair<ll,ll> > st;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int target;
        cin >> target;
        while(!st.empty() && st.top().first < target) {
            ans += st.top().second;
            ans += 1;
            st.pop();
        }

        if(st.empty()) st.push({target, 0});
        else if(st.top().first == target) {
            st.top().second += 1;
            ans += st.top().second;
            if(st.size() > 1) ans++;
        }
        else if(st.top().first > target) {
            st.push({target, 0});
            ans += 1;
        }
    }

    cout << ans;


    return 0;
}