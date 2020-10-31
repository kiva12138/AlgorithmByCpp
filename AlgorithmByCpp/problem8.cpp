#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main_fake8() {
	int n, m;
	while (cin >> n >> m) {
		int n, m;
		int tmp;
		while (cin >> n >> m) {
			vector<int> weight(n + 1);
			vector<int> value(n + 1);
			for (int i = 1; i <= n; i++) {
				cin >> weight[i];
				cin >> value[i];
			}
			vector<vector<int>> dp(n + 1);
			for (int i = 0; i <= n; i++) {
				dp[i].resize(m + 1, 0);
			}
			for (int i = 1; i <= n; i++)
			{
				for (int j = 0; j <= m; j++)
				{
					if (j < weight[i]) {
						dp[i][j] = dp[i - 1][j];
					}
					else {
						dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
					}
				}
			}
			int result = 0;
			for (int i = 0; i <= n; i++) {
				result = max(result, dp[i][m]);
			}
			cout << result << endl;
		}
		return 0;

	}
}