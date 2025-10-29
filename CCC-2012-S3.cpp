#include <bits/stdc++.h>
using namespace std;
const int MM = 2e6 + 1;
int n, a[MM] = {};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    while (n--) {
        int x; cin >> x;
        a[x]++;
    }

    int mx1, mx2 = 0;
    mx1 = *max_element(a, a + MM);
    for (int i = 0; i < MM; ++i) {
        if (a[i] < mx1 && mx2 < a[i]) {
            mx2 = a[i];
        }
    }

    int l = 0, r = MM - 1;
    while (l != r) {
        if (a[l] == mx1 && a[r] == mx1) break;
        if (a[l] != mx1) {
            l++;
        }
        if (a[r] != mx1) {
            r--;
        }
    }
    if (l != r) {
        cout << abs(l - r); 
        return 0;
    }
    
    int l1 = 0, r1 = MM - 1;
    while (l1 != r1) {
        if (a[l1] == mx2 && a[r1] == mx2) break;
        if (a[l1] != mx2) l1++;
        if (a[r1] != mx2) r1--;
    }
    if (mx2 == 0) {cout << abs(l - r);}
    else {cout << max(max(abs(l1 - r), abs(l1 - l)), max(abs(r1 - r), abs(r1 - l)));}
    return 0;
}