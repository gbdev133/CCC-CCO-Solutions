#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cin >> a >> b >> c >> d;
    int cnt = 0;
    while (a > 0) {
        a--; b++; cnt++;
        if (b == 35) a += 30; b %= 35;
        if (a <= 0) break;

        a--; c++; cnt++;
        if (c == 100) a += 60; c %= 100;
        if (a <= 0) break;

        a--; d++; cnt++;
        if (d == 10) a += 9; d %= 10;
    }
    cout << "Martha plays " << cnt << " times before going broke.";
    return 0;
}