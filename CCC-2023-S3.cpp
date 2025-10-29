#include <bits/stdc++.h>
using namespace std;
#define dbg(v) cout << "Line("<<__LINE__<<")->" << #v << "=" << (v) << endl;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<int, pi> pii;
int n, m, r, c;

void printArr(vector<string> a) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << a[i][j];
        }
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> r >> c;
    vector<string> a(n+1, string(m+1, 'b'));
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = 'a';
        }
    }

    for (int i = 1; i <= c; i++) {
        for (int j = 1; j <= n; j++) {
            a[j][i] = 'a';
        }
    }

    if (r == 0 && c == 0) {
        for (int i = 1; i < n; i++) {
            a[i][1] = 'a';
        }
        a[n][1] = 'c';
        for (int i = 1; i < m; i++) {
            a[1][i] = 'a';
        }
        a[1][m] = 'c';
    } else if (r == n){
        if (m % 2 != c % 2) {
            if (c % 2 == 1) {
                cout << "IMPOSSIBLE\n"; return 0;
            } else {
                int col = m;
                for (int i = m/2+1, j = m/2+1; col > c; i--, j++) {
                    if (i == j) {
                        col--;
                    } else {
                        col -= 2;
                    }
                    a[n][i] = a[n][j] = 'b';
                }
            }
        } else {
            int col = m, i, j;
            if (m % 2 == 1) {
                i = m/2; j = i+2;
            } else {
                i = m/2; j = i+1;
            }
            for (; col > c; i--, j++, col-=2) {
                // dbg(i); dbg(j); dbg(col);
                a[n][i] = a[n][j] = 'b';
            }
        }
    } else if (c == m) {
        if (n % 2 != r % 2) {
            if (r % 2 == 1) {
                cout << "IMPOSSIBLE\n"; return 0;
            } else {
                int row = n;
                for (int i = n/2+1, j = n/2+1; row > r; i++, j--) {
                    if (i == j) {
                        row--;
                    } else {
                        row -= 2;
                    }
                    a[i][m] = a[j][m] = 'b';
                }
            }
        } else {
            int row = n, i, j;
            if (n % 2 == 1) {
                i = n/2; j = i+2;
            } else {
                i = n/2; j = i+1;
            }
            for (; row > r; i--, j++, row-=2) {
                // dbg(i); dbg(j); dbg(col);
                a[i][m] = a[j][m] = 'b';
            }
        }
    } else if (r == 0) {
        for (int i = 1; i <= m; i++) {
            if (a[n][i] == 'b') a[n][i] = 'c';
        }
    } else if (c == 0) {
        for (int i = 1; i <= n; i++) {
            if (a[i][m] == 'b') a[i][m] = 'c';
        }
    }


    printArr(a);

    
}