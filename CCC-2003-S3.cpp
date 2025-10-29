#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
int flooring, r, c;
int t = 0;


void dfs(int x, int y, vector<vector<char>> &v) {

    if (v[x][y] == 'I') return;
    if (v[x][y] == '.') t++;
    v[x][y] = 'I';
    if (x - 1 >= 0) dfs(x-1, y, v);
    if (y + 1 < c) dfs(x, y+1, v);
    if (x + 1 < r) dfs(x+1, y, v);
    if (y - 1 >= 0) dfs(x, y-1, v);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> flooring >> r >> c;
    vector<vector<char>> v(r);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            char x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    vector<int> rooms; int x;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (v[i][j] != '.') continue;
            dfs(i, j, v);
            x = t;
            rooms.push_back(x);
            t = 0;
        }
    }

    sort(rooms.begin(), rooms.end(), greater<>());
    int ans = 0;
    for (int k: rooms) {
        if (flooring - k < 0) break;
        flooring -= k;
        ans++;
    }
    if (ans == 1) cout << ans << " room, ";
    else cout << ans << " rooms, ";
    cout << flooring << " square metre(s) left over";
}