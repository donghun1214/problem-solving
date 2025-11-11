#include <bits/stdc++.h>

using namespace std;
/**
 * 1. arr 선언
 */

int arr[55]; //비트마스킹 숫자 담은 배열 //'z'-'a' = 0
bool vis[26]; //a ~ z까지
int n, ans;

void func(int start, int m) {
    if(m == 0) {
        //m 조합으로 만든 비트마스킹
        int target = 0;
        for(int i = 0; i < 26; i++) {
            if(vis[i] == true) {
                target |= (1 << i);
            }
        }

        //비교와 포함되는 거 확인
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if((arr[i] & target) == arr[i]) 
                cnt++;
        }
        //ans 갱신
        if(cnt > ans) 
            ans = cnt;

        return;
    }

    //재귀 돌리기 0부터 25
    for(int i = start + 1; i < 26; i++) {
        if(!vis[i]) {
            vis[i] = true;
            func(i, m-1);
            vis[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int m;
    cin >> n >> m;
    //arr 에 비트마스킹 숫자 저장
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int target = 0;
        for(char c : s) {
            int idx = c - 'a';
            target |= (1 << idx);
        }
        arr[i] = target;
    }

    //a, n, t, i, c 는 고정이지.
    int a_int = 'a' - 'a';
    int n_int = 'n' - 'a';
    int t_int = 't' - 'a';
    int i_int = 'i' - 'a';
    int c_int = 'c' - 'a';

    if(m <= 4) {
        cout << 0 << endl;
        return 0;
    }
    vis[a_int] = true;
    vis[n_int] = true;
    vis[t_int] = true;
    vis[i_int] = true;
    vis[c_int] = true;
    
    //a(0)부터 z(25) 중 m -5 개 골라.
    func(-1, m-5);

    cout << ans;
    return 0;
}

