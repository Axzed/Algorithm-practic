#include <bits/stdc++.h>

using namespace std;

const int N = 500 + 10;
// 记忆化搜索, f数组表示某一段区间的合并最小值, 如果之前被计算过, 直接返回使用 
int n, a[N], s[N], f[N][N];
// 其实就是有个数组去记忆求过的值

int solve(int l, int r) {
	// 当前区间被计算过了, 直接返回给上层递归使用
	if (f[l][r] != -1) {
		return f[l][r];
	}
	// 递归出口, 返回f[l][r]被计算过 == 0
	if (l == r) {
		return f[l][r] = 0;
	}
	int ans = 1 << 30; 
	for (int m = l; m < r; m ++) {
		ans = min(ans, solve(l, m) + solve(m + 1, r));
	}
	// 返回计算的f[l][r]给上层递归
	return f[l][r] = ans + s[r] - s[l - 1];
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i ++) {
		s[i] = s[i - 1] + a[i];
	}
	// 初始化f数组为-1,代表区间没被计算过
	memset(f, 255, sizeof f);
	cout << solve(1, n) << endl;
	return 0;
}