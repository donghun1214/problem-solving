#include <bits/stdc++.h>
using namespace std; 

#define SOUTH 0
#define NORTH 1
#define EAST 2
#define WEST 3
#define OPPOSITE 4

int value[7];
int bottom = 1, top = 6, north = 2, south = 5, west = 4, east = 3;
int arr[21][21];

void rollEast() {
    int prev_bottom = bottom, prev_top = top, prev_south = south, prev_north = north, prev_west = west, prev_east = east;
    bottom = prev_east;
    top = prev_west;
    west = prev_bottom;
    east = prev_top;
    north = prev_north;
    south = prev_south;
}

void rollWest() {
    int prev_bottom = bottom, prev_top = top, prev_south = south, prev_north = north, prev_west = west, prev_east = east;
    bottom = prev_west;
    top = prev_east;
    west = prev_top;
    east = prev_bottom;
    north = prev_north;
    south = prev_south;
}

void rollNorth() {
    int prev_bottom = bottom, prev_top = top, prev_south = south, prev_north = north, prev_west = west, prev_east = east;
    bottom = prev_north;
    top = prev_south;
    west = prev_west;
    east = prev_east;
    north = prev_top;
    south = prev_bottom;
}

void rollSouth() {
    int prev_bottom = bottom, prev_top = top, prev_south = south, prev_north = north, prev_west = west, prev_east = east;
    bottom = prev_south;
    top = prev_north;
    west = prev_west;
    east = prev_east;
    north = prev_bottom;
    south = prev_top;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int row, col, x, y, k;
    cin >> row >> col >> x >> y >> k;

    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            cin >> arr[i][j];
        
    int cmd;
    for(int i = 0; i < k; i++) {
        cin >> cmd;
        //동쪽
        if(cmd == 1) {
            if(y+1 >= col) continue;
            y++;
            rollEast();
        }
        //서쪽
        else if(cmd == 2) {
            if(y-1 < 0) continue;
            y--;
           rollWest();
           
        }

        else if(cmd == 3) {
            if(x-1 < 0) continue;
            x--;
            rollNorth();
        }
        else if (cmd == 4) {
            if(x+1 >= row) continue;
            x++;
            rollSouth();
        }

        if(arr[x][y] == 0) {
            arr[x][y] = value[bottom];
        }
        else {
            value[bottom] = arr[x][y];
            arr[x][y] = 0;
        }
        cout << value[top] << '\n';
    }
}