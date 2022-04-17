#include <bits/stdc++.h>

using namespace std;

const int N = 500 + 10;
int n, a[N], s[N];

int solve(int l, int r) {
	if (l == r) {
		return 0;
	}
	int ans = 1 << 30;
	for (int m = l; m < r; m ++) {
		ans = min(ans, solve(l, m) + solve(m + 1, r));
	}
	return ans + s[r] - s[l - 1];
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i ++) 
		cin >> a[i];
	for (int i = 1; i <= n; i ++) 
		s[i] = s[i - 1] + a[i];
	printf("%d\n", solve(1, n));
	return 0;
}