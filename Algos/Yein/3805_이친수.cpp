#include<iostream>
using namespace std;
int main() {
	int n;
	long long dp[91][2];
	cin >> n;
	for (int i = 1;i <= n;i++) {
		if (i ==1) {
			dp[i][1] = 1;
			dp[i][0] = 0;
		}
		else if (i == 2) {
			dp[i][1] = 0;
			dp[i][0] = 1;
		}
		else {
			dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
			dp[i][1] = dp[i - 1][0];
		}
		
	}
	cout << dp[n][0] + dp[n][1] << endl;
}
