#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
vector<int> lowrank, scores;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    int a[n] = {}, b[n] = {};
    while (k--) {
        for (int i = 0, x; i < n; ++i) {
            cin >> x; b[i] += x;
        }

        
        for (int i = 0; i < n; ++i) {
            int rank = 1;
            for (int j = 0; j < n; ++j) {
                if (b[j] > b[i]) rank++;
            }
            a[i] = max(a[i], rank);
        }

        
    }
    int mx = -1e9;
    for (int i = 0; i < n; ++i) {
        mx = max(mx, b[i]);
    }

    for (int i = 0; i < n; ++i) {
        if (b[i] == mx) {
            cout << "Yodeller " << i + 1 << " is the TopYodeller: score ";
            cout << b[i] << ", worst rank " << a[i] << "\n";
        }
    }
    return 0;
}