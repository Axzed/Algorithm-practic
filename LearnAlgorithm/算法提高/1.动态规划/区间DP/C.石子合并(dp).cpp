#include <bits/stdc++.h>

using namespace std;

const int N = 510;
int n, a[N], s[N], dp[N][N];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i ++) {
		s[i] = s[i - 1] + a[i];
	} 
	// 初始化dp数组为INF
	memset(dp, 127, sizeof dp);
	// 只有一堆石子, 不需要代价
	for (int i = 1; i <= n; i ++) {
		dp[i][i] = 0;
	}
	// 第一维: 枚举区间长度 从小到大 保证最优子结构性质
	for (int i = 1; i < n; i ++) 
		// 第二维: 枚举区间 左端点 j : 右端点 j + i这样一个区间
		for (int j = 1; j + i <= n; j ++)
			// 第三维: 枚举分界线
			for (int k = j; k < j + i; k ++) {
				dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + s[j + i] - s[j - 1]);
			}
	cout << dp[1][n] << endl;
	return 0;
}