#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
int n, m;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    vector<pi> v;
    int cur;
    for (int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        if (i+1 == m) cur = a;
        else if (a-b >= 0) v.push_back({a,b});
    }
    
    sort(v.begin(), v.end(), [](pi x, pi y){
        return x.second < y.second;
    });

    int ans = 1;
    for (int i = 0; i < v.size(); i++) {
        if (cur >= v[i].second) {
            cur += v[i].first - v[i].second;
            ans++;
        }
    }
    cout << cur << '\n' << ans;
}