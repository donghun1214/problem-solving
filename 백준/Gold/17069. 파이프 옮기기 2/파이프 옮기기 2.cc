#include <bits/stdc++.h>
#define HORIZONTAL 0
#define HORIZONTAL_VERTICAL 1
#define VERTICAL 2
using namespace std;

long long mp[33][33], dp[33][33][3];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> mp[i][j];
    dp[1][2][HORIZONTAL] = 1; dp[1][2][HORIZONTAL_VERTICAL] = 1;
//     dp[m][n][가로방향] = dp[m][n-1][가로방향] + dp[m-1][n-1][대각선방향]     : 이게 무슨 말이냐면, (m,n) 위치에서 가로 방향으로 나아갈 “예정”
// dp[m][n][대각선방향] = dp[m][n-1][가로방향] + dp[m-1][n-1][대각선방향] + dp[m-1][n][세로방향]
// dp[m][n][세로방향] = dp[m-1][n-1][대각선방향] + dp[m-1][n][세로방향]

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j][HORIZONTAL] = dp[i][j-1][HORIZONTAL] + dp[i-1][j-1][HORIZONTAL_VERTICAL];
            dp[i][j][HORIZONTAL_VERTICAL] = dp[i][j-1][HORIZONTAL] + dp[i-1][j-1][HORIZONTAL_VERTICAL] + dp[i-1][j][VERTICAL];
            dp[i][j][VERTICAL] = dp[i-1][j-1][HORIZONTAL_VERTICAL] + dp[i-1][j][VERTICAL];
            
            //초깃값 설정
            if(i==1 && j==2) {
                dp[i][j][HORIZONTAL] = 1;
                dp[i][j][HORIZONTAL_VERTICAL] = 1;
            }
            
            if(mp[i][j+1] == 1){
                dp[i][j][HORIZONTAL] = 0;
                dp[i][j][HORIZONTAL_VERTICAL] = 0;
            }
            if(mp[i+1][j+1] == 1)
                dp[i][j][HORIZONTAL_VERTICAL] = 0;
            if(mp[i+1][j] == 1){
                dp[i][j][HORIZONTAL_VERTICAL] = 0;
                dp[i][j][VERTICAL] = 0;
            }
        }
    }
    
    long long ans = dp[n-1][n][VERTICAL] + dp[n-1][n-1][HORIZONTAL_VERTICAL] + dp[n][n-1][HORIZONTAL];
    
    // for(int i=1; i<= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout << dp[i][j][HORIZONTAL] << '/'<< dp[i][j][HORIZONTAL_VERTICAL] << '/' << dp[i][j][VERTICAL] << "        ";
    //     }
    //     cout << '\n';
    // }
    
    cout << ans;
    return 0;
}