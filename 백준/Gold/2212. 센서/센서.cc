#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    if(k>n){
        cout << 0;
        return 0;
    }
    
    //요소 넣고 오름차순 정렬
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    
    int max_width = v[n-1] - v[0]; // n-1 이니까 접근 가능하겠지
    
    //gap 요소 넣고,내림차순 정렬
    vector<int> gap;
    for(int i = 0; i < n-1; i++) {
        gap.push_back(v[i+1]-v[i]); //v[n-1] - v[n-2] 가 최대인데
    }
    sort(gap.begin(), gap.end(), greater<int> ());
    
    int target = 0;
    for(int i = 0; i < k-1; i++) {
        target += gap[i];
    }
    
    cout << max_width-target << endl;
}
