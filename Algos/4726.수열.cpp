#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<int>v;
	int tc, n, days, max = -9999999;
	cin >> tc;
	cin >> days;
	for (int i = 0; i < tc; i++) {//일별 온도 입력
		cin >> n;
		v.push_back(n);
	}
	int sum;
	for (int i = 0; i <= tc - days; i++) {
		sum = 0;
		for (int j = i, cnt = 0; cnt < days; j++, cnt++) {//i번째~i+days의 날짜동안의 온도합 구하기
			sum += v[j];
		}
		if (sum > max)max = sum;
	}
	cout << max;

}