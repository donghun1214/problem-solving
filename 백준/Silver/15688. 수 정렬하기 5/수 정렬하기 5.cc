#include <bits/stdc++.h>

using namespace std;
#define MILL 1000000
int cnt[2000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, tmp;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> tmp;
        int num = tmp + MILL;
        cnt[num]++;
    }

    for(int i = 0; i <= 2*MILL; i++) {
        while(cnt[i] > 0) {
            cout << i - MILL << '\n';
            cnt[i]--;
        }
    }
}
