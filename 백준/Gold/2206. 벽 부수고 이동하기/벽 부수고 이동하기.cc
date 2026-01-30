/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

string s[1001];
int dis[1001][1001][2];   //벽을 한번도 안부수기 와 한번은 부수기.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, 1, -1, 0};
    int m , n;
    cin >> m >> n;  //m행 n열
    for(int i = 0; i < m; i++){
        cin >> s[i]; // 0행 0열부터 시작 끝점은 m-1행 n-1열 이다
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(s[i][j] == '0') {
                dis[i][j][0] = -1;
                dis[i][j][1] = -1;
            }
        }
    }
    
    queue<tuple<int, int, bool> > q; //세번째 인자는 broken.
    q.push({0,0,0});
    dis[0][0][0] = 1;
    int curx, cury;
    bool broken = 0;
    while(!q.empty()){
        tie(curx, cury, broken) = q.front();
        q.pop();
        if(curx == m - 1 && cury == n - 1){
            cout << dis[curx][cury][broken];
            return 0;
        }
        for(int dir = 0; dir < 4; dir++){
            int nx = curx + dx[dir];
            int ny = cury + dy[dir];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(broken == 0){
                if(dis[nx][ny][0] < 0) { //벽 안부수는 경로.
                    dis[nx][ny][0] = dis[curx][cury][0] + 1;
                    q.push({nx, ny, 0});
                }
                if(s[nx][ny] == '1' && dis[nx][ny][1] == 0) {  //벽 부숴버리는 경로.
                    dis[nx][ny][1] = dis[curx][cury][0] + 1;
                    q.push({nx, ny, 1});
                }
            }
            //벽 부쉈으면 이제 못 부시지.
            else if(broken == 1 && dis[nx][ny][1] < 0){
                dis[nx][ny][1] = dis[curx][cury][1] + 1;
                q.push({nx,ny,1});
            }
            
            
        }
    }
    cout << -1;
    

    
    
    return 0;
}
