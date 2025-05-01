#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int ladder[101], snake[101];
bool vis[101];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    //뱀, 사다리 설정
    int node, input;
    for(int i=0; i<n; i++){
        cin >> node >> input;
        ladder[node] = input;
    }
    for(int i=0; i< m; i++){
        cin >> node >> input;
        snake[node] = input;
    }
    
    queue<pair<int,int> > q;
    q.push({1,0}); vis[1] = true;
    
    while(!q.empty()){
        pair<int, int> cur = q.front(); 
        q.pop();
        if(cur.X > 100) continue;
        if(cur.X == 100){
            cout << cur.Y;
            return 0;
        }
        //In case of ladder
        while(ladder[cur.X]){
            cur.X = ladder[cur.X];
            vis[cur.X] = true;
        }
        
        //In case of snake
        while(snake[cur.X]){
            cur.X = snake[cur.X];
            vis[cur.X] = true;
        }
        
        for(int j=1; j<= 6; j++){
            int tmp = cur.X + j;
            if(!vis[tmp]) {
                q.push({tmp, cur.Y + 1});
                vis[tmp] = true;
            }
        }
    }
    
}


