#include <bits/stdc++.h>

using namespace std;

char arr[4][4];
char tmp, tmp_arr[4][4];
int same_flag = 0;
bool vis[10];

bool isSame() {
    char flag = tmp_arr[0][0];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++){
            if(flag != tmp_arr[i][j])
                return false;
        }
    }
    return true;
}

void reverse_(int i, int j){
    if(tmp_arr[i][j] == 'H')
        tmp_arr[i][j] = 'T';
    else
        tmp_arr[i][j] = 'H';
}

void reverse_func(int target) {
    if(target == 1) {
        reverse_(0, 0);
        reverse_(1, 0);
        reverse_(2, 0);
    } else if(target == 2) {
        reverse_(0, 1);
        reverse_(1, 1);
        reverse_(2, 1);
    } else if (target == 3) {
        reverse_(0, 2);
        reverse_(1, 2);
        reverse_(2, 2);
    } else if (target == 4) {
        reverse_(0, 0);
        reverse_(0, 1);
        reverse_(0, 2);
    } else if (target == 5) {
        reverse_(1, 0);
        reverse_(1, 1);
        reverse_(1, 2);
    } else if (target == 6 ){
        reverse_(2, 0);
        reverse_(2, 1);
        reverse_(2, 2);
    } else if (target == 7) {
        reverse_(0, 0);
        reverse_(1, 1);
        reverse_(2, 2);
    } else if (target == 8) {
        reverse_(0, 2);
        reverse_(1, 1);
        reverse_(2, 0);
    }
}

void func(int start, int r) {
    if(r == 0) {
        for(int i = 0; i < 3; i++) 
            for(int j = 0; j < 3; j++) 
                tmp_arr[i][j] = arr[i][j];
            
        for(int i = 1; i <= 8; i++){
            if(vis[i] == true)
                reverse_func(i);
        }
        if(isSame())
            same_flag = 1;
        return;
    }

    for(int i = start + 1; i <= 8; i++) {
        if(vis[i] == false){
            vis[i] = true;
            func(i, r-1);
            vis[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int tc;
    cin >> tc;

    while(tc--) {
        same_flag = 0;

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                cin >> tmp;
                arr[i][j] = tmp;
            }
        }

        for(int r = 0; r <= 8; r++) {
            for(int i = 0; i <= 8; i++)
                vis[i] = false;

            func(0, r); //8C0 ~ 8C8
            if(same_flag == 1) {
                cout << r << endl;
                break;
            }
        }
        if(same_flag == 0)
            cout << -1 << endl;
    }

}