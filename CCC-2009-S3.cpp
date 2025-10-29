#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
vector<unordered_set<int>> adj(50);

void initAdj() {
    adj[1] = {6}; adj[2] = {6}; adj[3] = {4, 5, 6, 15}; adj[4] = {3, 6, 5};
    adj[5] = {3, 4, 6}; adj[6] = {1, 2, 3, 4, 5, 7}; adj[7] = {6, 8};
    adj[8] = {7, 9}; adj[9] = {8, 10, 12}; adj[10] = {9, 11}; adj[11] = {10, 12}; adj[12] = {9, 11, 13};
    adj[13] = {12, 14, 15}; adj[14] = {13}; adj[15] = {3, 13};
    adj[16] = {17, 18}; adj[17] = {16, 18}; adj[18] = {16, 17};
}

int bfs(int x, int y) {
    bool vis[50]; memset(vis, false, sizeof(vis));
    int dist[50] = {};
    queue<int> q;
    q.push(x);
    vis[x] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == y) {
            return dist[y];
        }

        for (auto i: adj[cur]) {
            if (!vis[i]) {
                q.push(i);
                vis[i] = true;
                dist[i] = dist[cur] + 1;
            }
        }
    }
    return -1;
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    initAdj();
    char cmd; 
    cin >> cmd;
    while (cmd != 'q') {
        int x, y;
        if (cmd == 'i') {
            cin >> x >> y;
            if (adj[x].find(y) != adj[x].end()) {
                continue;
            } else {
                adj[x].insert(y);
                adj[y].insert(x);
            }
        } else if (cmd == 'd') {
            cin >> x >> y;
            adj[x].erase(y);
            adj[y].erase(x);
        } else if (cmd == 'n') {
            cin >> x;
            cout << adj[x].size() << '\n';
        } else if (cmd == 'f') {
            cin >> x;
            unordered_set<int> friends;
            friends.insert(x);  
            for (auto i: adj[x]) {
                friends.insert(i);
                for (auto j: adj[i]) {
                    friends.insert(j);
                }
            }
            cout << friends.size() - adj[x].size() - 1 << '\n';
        } else if (cmd == 's') {
            cin >> x >> y;
            int ans = bfs(x, y);
            if (ans == -1) cout << "Not connected";
            else cout << ans;
            cout << '\n';
        }
        cin >> cmd;
    }
    
}