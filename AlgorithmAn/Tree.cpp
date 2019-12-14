#include<iostream>
#include<vector>

using namespace std;

//adj[i]는 i와 연결된 노드를 담는다.
vector<int> adj[100001];
int cache[100001][19];
const int INF  = 100000007;

int Min(int a, int b) {
	return a  < b  ? a  : b;
}

int dp(int here, int beforeNode, int color) {
	//메모이제이션을 활용하자.
	int& ret  = cache[here][color];
	//기저 사례 : 이미 색칠이 된 경우 바로 리턴
	if (ret  != 0)
		return ret;
	int colorSum  = 0;
	for (int i  = 0; i  < adj[here].size(); i++) {
		int there  = adj[here][i];
		int min  = INF;
		//이전 노드를 방문하지 않도록 한다.
		if (there  != beforeNode) {
			for (int nextColor  = 1; nextColor  <= 18; nextColor++)
				//다음 노드의 색은 이번 노드의 색과 겹치지 않게 한다.
				if (color  != nextColor)
				min  = Min(min, dp(there, here, nextColor));
			colorSum  += min;
		}

	}
	return ret  = colorSum  + color;
}

int main() {
	int N, a, b;
	cin  >> N;
	for (int i  = 1; i  < N; i++) {
		cin  >> a  >> b;
		//인접 노드를 양쪽 모두에 담는다.(방향을 확정시킬 수 없기 때문이다.)
		//만일 위에서 부터 쫘쫘작 주어진다면, 사실 한쪽만 담아도 상관 없다.
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int min  = INF;
	for (int i  = 1; i  <= 18; i++) {
		min  = Min(min, dp(1, 0, i));
	}

	cout  << min;

	return 0;
}
