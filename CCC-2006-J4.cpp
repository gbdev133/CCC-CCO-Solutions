#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const int MM = 1e5+7;
int n, m;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<pi> v = {{1, 7}, {1, 4}, {2, 1}, {3, 4}, {3, 5}};
    cin >> n >> m;
    while (n != 0 && m != 0) {
        v.push_back({n, m});
        cin >> n >> m;
    }

    vector<int> ind(8);
    vector<int> tasks = {1, 2, 3, 4, 5, 6, 7};
    bool good;
    do {
        good = true;
        for (int i = 0; i < 7; i++) ind[tasks[i]] = i;
        for (int i = 0; i < v.size(); i++) {
            if (ind[v[i].first] >= ind[v[i].second]) {
                good = false;
            }
        }
        if (good) {
            for (int i = 0; i < 7; i++) cout << tasks[i] << " ";
            return 0;
        }
    } while (next_permutation(tasks.begin(), tasks.end()));

    cout << "Cannot complete these tasks. Going to bed.";


}
