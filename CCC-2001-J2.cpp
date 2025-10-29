#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x, m;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> x >> m;
    for (int i = 2; i <= 100; ++i) {
        if (x * i % m == 1) {
            cout << i;
            return 0;
        }
    }
    cout << "No such integer exists.";
    return 0;
}