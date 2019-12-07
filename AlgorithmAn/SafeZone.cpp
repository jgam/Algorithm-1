#include<iostream>
#include<cstring>
#include<queue>

#define endl "\n"
#define MAX 100
using namespace std;			

int N, Max_Height_Area, Answer, Num_Area;
int MAP[MAX][MAX], C_MAP[MAX][MAX];
bool Visit[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

vector<pair<int, int>> V;

int Bigger(int A, int B) { if (A > B) return A; return B; }

void Input()
{
	Max_Height_Area = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
			if (MAP[i][j] > Max_Height_Area) Max_Height_Area = MAP[i][j];
		}
	}
}

void Copy_MAP()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			C_MAP[i][j] = MAP[i][j];
		}
	}
}

void Make_MAP(int H)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (C_MAP[i][j] <= H) C_MAP[i][j] = 0;
			else V.push_back(make_pair(i, j));
		}
	}
}

void BFS(int a, int b)
{
	queue<pair<int, int>> Q;
	Q.push(make_pair(a, b));
	Visit[a][b] = true;

	while (Q.empty() == 0)
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < N)
			{
				if (Visit[nx][ny] == false && C_MAP[nx][ny] != 0)
				{
					Visit[nx][ny] = true;
					Q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

void Solution()
{
	for (int H = 0; ; H++)
	{
		Num_Area = 0;
		V.clear();
		memset(Visit, false, sizeof(Visit));
		if (H > Max_Height_Area) break;
		Copy_MAP();
		Make_MAP(H);

		for (int i = 0; i < V.size(); i++)
		{
			int x = V[i].first;
			int y = V[i].second;

			if (Visit[x][y] == false)
			{
				Num_Area++;
				BFS(x, y);
			}
		}
		Answer = Bigger(Answer, Num_Area);
	}
}

void Solve()
{
	Input();
	Solution();
	cout << Answer << endl;
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
