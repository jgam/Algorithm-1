#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int dp[101][101] = { 0, }, map[101][101] = { 0, };
	int n, m;
	cin >> n >> m;
	for (int i=1; i <= n; i++) {//위치별 사탕 개수 입력
		for (int j = 1; j <=m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i=1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = map[i][j]+max(dp [i - 1][j], dp[i][j - 1]);//좌, 위의 dp값중 큰값에 현재위치의 사탕개수를 더함
		}
	}
	cout << dp[n][m] << endl;

}