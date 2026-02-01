#include <bits/stdc++.h>

using namespace std;

void func(int num, int start, int end) {
    if(num == 1){
        cout << start << ' ' << end << '\n';
        return;
    }

    int target = 6-(start+end);
    func(num-1, start, target);
    cout << start << ' ' << end << '\n';
    func(num-1, target, end);

    return;
}

int dp[21];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    dp[1] = 1;
    for(int i = 2; i <= 20; i++) {
        dp[i] = dp[i-1] + 1 + dp[i-1];
    }
    cout << dp[n] << '\n';
    func(n, 1, 3);
}