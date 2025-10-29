#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
int r, c;
ll ans = 0;
vector<vector<char>> v;
unordered_map<char, int> mp = {{'S', 1}, {'M', 5}, {'L', 10}};
vector<pi> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void dfs(int x, int y) {
    ans += mp[v[x][y]];
    v[x][y] = '*';
    for (auto [dx, dy]: dir) {
        if (x + dx < r && x + dx >= 0 && y + dy < c && y + dy >= 0 && v[x+dx][y+dy] != '*') {
            dfs(x+dx, y+dy);
        }
    }
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> r >> c;
    v.resize(r);
    for (int i = 0; i < r; i++) {
        v[i].resize(c);
        for (int j = 0; j < c; j++) {
            cin >> v[i][j];
        }
    }
    int x, y;
    cin >> x >> y;
    dfs(x, y);
    cout << ans;
}
