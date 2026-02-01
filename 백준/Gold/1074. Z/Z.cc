#include <bits/stdc++.h>

using namespace std;

int base = 0;
void func(int n, int row, int column) {
    if(n == 0) {
        cout << base << endl;
        return;
    }

    int num = pow(2, n) / 2;
    if(row < num && column < num) {
        base += 0 * pow(4, n-1);
        func(n-1, row, column);
    } else if(row < num && column >= num) {
        base += 1 * pow(4, n-1);
        func(n-1, row, column-num);
    } else if(row >= num && column < num) {
        base += 2 * pow(4, n-1);
        func(n-1, row - num, column);
    } else if(row >= num && column >= num) {
        base += 3 * pow(4, n-1);
        func(n-1, row - num, column - num);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, r, c;
    cin >> N >> r >> c;
    func(N, r, c);
}