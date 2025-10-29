#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<int, pi> pii;
int n, a, b;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> v = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
    cin >> a >> b >> n;
    for (int i = 0, m; i < n; i++) {
        cin >> m; v.push_back(m);
    }
    sort(v.begin(), v.end());

    ll dp[v.size()] = {};
    dp[0] = 1;
    for (int i = 1; i < v.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (v[i] - v[j] >= a && v[i] - v[j] <= b) {
                dp[i] += dp[j];
            }
        }
    }

    // for (int i = 0; i < v.size(); i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << '\n';

    cout << dp[v.size()-1] << '\n';

    

}