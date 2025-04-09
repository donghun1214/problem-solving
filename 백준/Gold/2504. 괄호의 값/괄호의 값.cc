#include <bits/stdc++.h>

using namespace std;

int tmp = 1, ans = 0;
bool isErr = false;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    stack<char> st;
    cin >> s;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '('){
            tmp *= 2;
            st.push(s[i]);
        } else if (s[i] == '[') {
            tmp *= 3;
            st.push(s[i]);
        } else if (s[i] == ')') {
            //온전하지 못한 괄호쌍이면 바로 0 출력.
            if (st.empty() || st.top() != '(') {
                cout << 0;
                return 0;
            }
            
            st.pop();
            //만약 이전에도 ),] 가 있다면, ans 갱신은 넘어간다. 그 이외의 경우는 ( 이므로 갱신.
            if(s[i-1] == '(') ans += tmp;
            tmp /= 2;
        } else if (s[i] == ']') {
            if (st.empty() || st.top() != '[') {
                cout << 0;
                return 0;
            }
            
            st.pop();
            if(s[i-1] == '[') {
                ans += tmp;
            }
            tmp /= 3;
        }
    }
    
    if(!st.empty()) ans = 0;
    
    cout << ans;
    return 0;
}