#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
int n;


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
	cout << (n-1)*(n-2)*(n-3)/6;
	
    return 0;
}