#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const int MM = 1e6+7;
ll t, n;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        vector<string> in;
        string s;
        for (int i = 0; i < n; i++) {
            cin >> s;
            in.push_back(s);
        }

        string root = in.back();
        ll ans = 0;
        unordered_map<string, vector<string>> g;
        unordered_map<string, int> dep, vis;
        deque<string> stk;
        stk.push_back(root);
        string k = root;
        for (int i = 0; i < n; i++) {
            s = in[i];
            if (stk.size() == 1) k = root;
            else k = stk[stk.size() - 2];
            if (s == k) {
                stk.pop_back();
            } else {
                g[stk.back()].push_back(s);
                stk.push_back(s);
            }

            
        }
        // for (auto [a, b]: g) {
        //     cout << a << ": ";
        //     for (auto x: b) {
        //         cout << x << ' ';
        //     }
        //     cout << '\n';
        // }


        queue<string> q;
        q.push(root);
        vis[root] = true;
        dep[root] = 0;
        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            for (auto x: g[cur]) {
                if (!vis[x]) {
                    q.push(x);
                    vis[x] = true;
                    dep[x] = dep[cur] + 1;
                }
            }
        }

        unordered_set<int> depths;
        for (auto [x, y]: dep) {
            depths.insert(y);
        }

        ans = n * 10 - (depths.size() - 1) * 20;
        cout << ans << '\n';
        // cout << depths.size() * 20 - n * 10;
    }

    
    
}