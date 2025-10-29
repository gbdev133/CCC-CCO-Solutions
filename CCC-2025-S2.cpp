#include <bits/stdc++.h>
using namespace std;
#define dbg(v) cout << "Line("<<__LINE__<<")->" << #v << "=" << (v) << endl;
typedef long long ll;
typedef pair<ll, pair<ll, char>> pic;
string s;
ll n;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s >> n;
    vector<pic> intervals;
    ll i = 0, l = 0;
    while (i+1 < s.size()) {
        char c = s[i];
        i++;
        string num = "";
        while (s[i] <= '9' && s[i] >= '0') {
            num += s[i];
            i++;
        }
        intervals.push_back({l, {l + stoll(num) - 1, c}});
        l += stoll(num);
    }


    ll length = intervals.back().second.first+1;
    n %= length;
    for (auto [L, x]: intervals) {
        auto [R, c] = x;
        if (n >= L && n <= R) {
            cout << c << '\n';
            return 0;
        }
    }


}