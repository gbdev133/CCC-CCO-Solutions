#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<int, pi> pii;
int n, m, r, c, moves;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n >> c >> r >> moves;
    int a[n][m] = {};
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            a[i][j] = 1;
            a[n-i-1][m-j-1] = 1;
            a[i][m-j-1] = 1;
            a[n-i-1][j] = 1;
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int x, y;
    bool f = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!a[i][j]) {
                x = i; y = j; 
                f = true;
                break;
            }
        }
        if (f) break;
    }
    // cout << x << ' ' << y << '\n';

    vector<vector<pi>> d = {
        {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}, // r
        {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}, // d
        {{1, 0}, {0, -1}, {0, 1}, {-1, 0}}, // l
        {{0, -1}, {-1, 0}, {0, 1}, {-1, 0}} // u
    };
    int cur = 0;
    while (moves--) {
        a[x][y] = 1;
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         cout << a[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << "---------------" << '\n';
        for (auto [dx, dy]: d[cur]) {
            int nx = x + dx, ny = y + dy;
            if (nx < n && ny < m && nx >= 0 && ny >= 0 && !a[nx][ny]) {
                x = nx; y = ny;
                if (dx == 0) {
                    if (dy == 1) {
                        cur = 0;
                    } else {
                        cur = 2;
                    }
                } else if (dy == 0) {
                    if (dx == 1) {
                        cur = 1;
                    } else {
                        cur = 3;
                    }
                }
                break;
            }
        }
        
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << y+1 << '\n' << x+1 << '\n';
    
}