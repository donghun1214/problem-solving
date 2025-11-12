#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int arr[100005];
int n, m;

int func(int mid) {
    int sum = 0, cnt = 1;
    for(int i = 0; i < n; i++) {
        //보따리 새로 싸야지
        if(arr[i] > mid) {
            return m + 1;
        }
        sum += arr[i];
        
        if(sum > mid) {
            cnt++;
            sum = arr[i];
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    ll lo = 0, hi = 0;
    //hi는 sum
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        hi += arr[i];
    }

    //이분탐색 lo 갱신, hi 갱신, while(lo <= hi), lo if 문은 부등호 없는 걸로, 가능한 곳에 ans = mid 박아
    ll mid;
    ll ans;
    while(lo <= hi) {
        mid = (lo + hi) / 2;
        // 보따리가 m 개 초과일 때는 작은 거임. 늘려야 함
        if(func(mid) > m) {
            lo = mid + 1;
        } else {
            ans = mid;
            hi = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}