#include <bits/stdc++.h>
using namespace std;

int getWeight(char op){
    switch(op){
        case '(': case ')': return 1;
        case '+': case '-': return 2;
        case '*': case '/': return 3;
    }
}

int main(){
	string s;
  	cin >> s;
  	string ans;
  	stack<char> st;
  
  	for(char c : s){
    	if(isupper(c)) ans += c;
      	else if(c == '('){
        	st.push(c);
        }
        else if(c == ')'){
            while(st.top() != '('){
                ans += st.top(); st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && getWeight(c) <= getWeight(st.top())){
                ans += st.top(); st.pop();
            }
            st.push(c);
        }
    }
    
    while(!st.empty()){
        ans += st.top(); st.pop();
    }
    
	cout << ans << endl;	
}