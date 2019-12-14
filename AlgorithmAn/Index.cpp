#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100000;
int N, M;
pair<int, int> arr[MAX + 1]; //value, idx

int Kth(int start, int end, int k)
{
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		//second가 인덱스이므로
		if (start <= arr[i].second && arr[i].second <= end)
			cnt++;

		//k 번째 숫자 반환
		if (cnt == k)
			return arr[i].first;
	}
	return -1;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); //cin 실행속도 향상
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].first;
		arr[i].second = i + 1;
	}

	//value 기준으로 오름차순 정렬
	sort(arr, arr + N);

	for (int i = 0; i < M; i++)
	{
		int start, end, k;
		cin >> start >> end >> k;

		cout << Kth(start, end, k) << "\n";
	}
	return 0;
}




/*
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
*/