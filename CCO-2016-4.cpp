#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, G, g[10][10]; unordered_map<int, int> mp; char c;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> G;
    for (int k = 1; k <= G; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> c; g[i][j] = c == 'R';
            }
        }
        for (int i = 0; i < N-1; i++) {
            for (int j = 0; j < N-1; j++) {
                if (g[i][j]) {
                    g[i][j] ^= 1; g[i][j+1] ^= 1; g[i+1][j] ^= 1; g[i+1][j+1] ^= 1;
                }
            }
        }
        int val = 0;
        for (int i = 0; i < N; i++) val = val << 1 | g[i][N-1];
        for (int i = 0; i < N; i++) val = val << 1 | g[N-1][i];
        mp[val]++;
    }
    ll ans = 0;
    for (auto [k, v]: mp) {
        ans += 1LL * v * (v-1)/2;
    }
    cout << ans;


}