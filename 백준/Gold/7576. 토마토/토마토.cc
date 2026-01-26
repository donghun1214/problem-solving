#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
int arr[1005][1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> m >> n; //n행 m열
    queue<pair<int, int> > q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) 
                q.push({i,j});
        }
    }

    while(!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if(nx < 0 || nx >= n) continue;
            if(ny < 0 || ny >= m) continue;
            if(arr[nx][ny] >= 1) continue;
            if(arr[nx][ny] == -1) continue;

            arr[nx][ny] = arr[cur.first][cur.second] + 1;
            q.push({nx,ny});
        }
    }

    int mx = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 0) {
                cout << -1;
                return 0;
            }
            mx = max(mx, arr[i][j]);
        }
    }

    cout << mx-1;
    return 0;
}