/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

int dis[100001];
int dir[2] = {1, -1};

int main()
{
    int n, k;
    fill(dis, dis + 100001, -1);
    queue<pair<int,int> > q;
    cin >> n >> k;
    q.push({n, 0}); dis[n] = 0;
    
    while(!q.empty()) {  
        pair<int,int> cur = q.front(); q.pop();
        if(cur.x == k){
            cout << cur.y;
            return 0;
        }
        
        int temp = cur.x;
        //2배 먼저 때려.
        while(temp != 0 && temp < k){
            temp *= 2;
            if(temp > 100000 || dis[temp] >= 0 && dis[temp] <= cur.y) continue;
            dis[temp] = cur.y;
            q.push({temp,cur.y});
            if(temp == k){
                cout << cur.y;
                return 0;
            }
        }
        
        for(int i = 0; i < 2; i++){
            int nx = cur.x + dir[i];
            if(nx < 0 || nx > 100000) continue;
            if(dis[nx] >= 0 && dis[nx] <= cur.y + 1) continue;
            dis[nx] = cur.y + 1;
            q.push({nx, cur.y + 1});
        }
    }
    
    return 0;
}