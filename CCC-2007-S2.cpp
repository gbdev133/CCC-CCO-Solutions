#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
ll n, m;
vector<vector<ll>> boxes;

bool isValid(ll a, ll b, ll c, vector<ll> v) {
    if (a <= v[0] && ((b <= v[1] && c <= v[2]) || (b <= v[2] && c <= v[1]))) return true;
    if (a <= v[1] && ((b <= v[0] && c <= v[2]) || (b <= v[2] && c <= v[0]))) return true;
    if (a <= v[2] && ((b <= v[0] && c <= v[1]) || (b <= v[1] && c <= v[0]))) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (ll i = 0, a, b, c; i < n; ++i) {
        cin >> a >> b >> c; boxes.push_back({a, b, c});
    }
    sort(boxes.begin(), boxes.end(), [&](vector<ll> x, vector<ll> y){
        return x[0] * x[1] * x[2] < y[0] * y[1] * y[2];
    });
    cin >> m;
    ll a, b, c;
    while (m--) {
        cin >> a >> b >> c;
        bool good = false;
        for (int i = 0; i < boxes.size(); ++i) {
            if (isValid(a, b, c, boxes[i])) {
                good = true;
                cout << boxes[i][0] * boxes[i][1] * boxes[i][2];
                break;
            }
        }
        if (!good) cout << "Item does not fit.";
        if (m != 0) cout << '\n';
        good = false;
    }   
}