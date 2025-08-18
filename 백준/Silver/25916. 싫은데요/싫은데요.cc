#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, target;
    cin >> n >> target;
    
    vector<int> v; int tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    
    int start = 0, sum = 0, ans = 0;
    for(int end = 0; end < n; end++){
        sum += v[end];
        //cout << start << "    " << end << "   " << sum << "   " << ans << '\n';
        while(sum > target && start <= end){
            sum -= v[start];
            start++;
        }
        
        if(sum <= target) ans = max(ans, sum);
    }
    
    cout << ans;
}