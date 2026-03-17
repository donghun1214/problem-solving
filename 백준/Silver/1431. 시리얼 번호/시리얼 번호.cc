#include <bits/stdc++.h>
using namespace std;

bool cmp(const string& a, const string& b) {
    if(a.length() != b.length()) 
        return a.length() < b.length();
    
    int sum_a = 0, sum_b = 0;
    for(char c : a) {
        if(c >= '0' && c <= '9') 
            sum_a += c - '0';        
    }
    for(char c : b) {
        if(c >= '0' && c <= '9')
            sum_b += c - '0';
    }

    if(sum_a != sum_b) return sum_a < sum_b;

    return a < b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> v;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);

    //todo
    for(auto i : v) {
        cout << i << '\n';
    }
}