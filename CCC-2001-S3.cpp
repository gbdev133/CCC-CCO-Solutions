#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<pair<char, char>> edges;
    unordered_map<char, unordered_set<char>> adj;
    while (true) {
        char u, v;
        cin >> u >> v;
        if (u == '*') break;
        adj[u].insert(v);
        adj[v].insert(u);
        edges.push_back({u, v});
    }

    vector<pair<char, char>> ans;
    for (auto [u, v]: edges) {
        adj[u].erase(v);
        adj[v].erase(u);
        queue<char> q;
        unordered_map<char, bool> vis;
        q.push('A'); vis['A'] = true;
        while (!q.empty()) {
            char cur = q.front(); q.pop();

            for (auto c: adj[cur]) {
                if (!vis[c]) {
                    vis[c] = true;
                    q.push(c);
                }
            }
        }
        adj[u].insert(v);
        adj[v].insert(u);
        if (!vis['B']) {
            ans.push_back({u, v});
        }
    }

    for (auto [x, y]: ans) {
        cout << x << y << '\n';
    }
    cout << "There are " << ans.size() << " disconnecting roads." << '\n';
        
    
}