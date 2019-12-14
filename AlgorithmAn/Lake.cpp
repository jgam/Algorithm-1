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



/*
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

#define endl "\n"
#define MAX 1500
using namespace std;

int R, C;
bool Find;
char MAP[MAX][MAX];
bool Visit[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

queue<pair<int, int>> Swan_Q, Swan_NQ, Q, NQ;
pair<int, int> Swan_Pos;

void Input()
{
	Find = false;
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> MAP[i][j];
			if (MAP[i][j] != 'X') Q.push(make_pair(i, j));
			if (MAP[i][j] == 'L')
			{
				Swan_Pos.first = i;
				Swan_Pos.second = j;
			}
		}
	}
}

void Swan_BFS()
{
	while (Swan_Q.empty() == 0 && Find == false)
	{
		int x = Swan_Q.front().first;
		int y = Swan_Q.front().second;
		Swan_Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < R && ny < C)
			{
				if (Visit[nx][ny] == false)
				{
					if (MAP[nx][ny] == '.')
					{
						Visit[nx][ny] = true;
						Swan_Q.push(make_pair(nx, ny));
					}
					else if (MAP[nx][ny] == 'L')
					{
						Visit[nx][ny] = true;
						Find = true;
						break;
					}
					else if (MAP[nx][ny] == 'X')
					{
						Visit[nx][ny] = true;
						Swan_NQ.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
}

void Water_BFS()
{
	while (Q.empty() == 0)
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < R && ny < C)
			{
				if (MAP[nx][ny] == 'X')
				{
					MAP[nx][ny] = '.';
					NQ.push(make_pair(nx, ny));
				}
			}
		}
	}
}

void Solution()
{
	int Day = 0;
	Swan_Q.push(make_pair(Swan_Pos.first, Swan_Pos.second));
	Visit[Swan_Pos.first][Swan_Pos.second] = true;

	while (Find == false)
	{
		Swan_BFS();

		if (Find == false)
		{
			Water_BFS();
			Q = NQ;
			Swan_Q = Swan_NQ;

			while (NQ.empty() == 0) NQ.pop();
			while (Swan_NQ.empty() == 0) Swan_NQ.pop();
			Day++;
		}
	}
	cout << Day << endl;
}

void Solve()
{
	Input();
	Solution();
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("Input.txt", "r", stdin);
	Solve();

	return 0;
}

