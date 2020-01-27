#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 100 + 1;
const int INF = 100000 + 1;

int N, M;
int graph[MAX][MAX];

void floyd(void)
{

    // via번째 도시를 거쳐가는게 더 빠를 경우 update
    for (int via = 1; via <= N; via++)
    {
        for (int from = 1; from <= N; from++)
        {
            // from 부터 거쳐가는 다리까지의 경로가 없는 경우는 셀 필요도 없으므로
            if (graph[from][via] == 0)
                continue;

            for (int to = 1; to <= N; to++)
            {
                // 거쳐가는 다리부터 to까지의 경로가 없는 경우 or  
                // 출발지점과 도착지점이 같은 경우는 셀 필요가 없으므로 
                if (graph[via][to] == 0 || from == to)
                    continue;

                // graph[from][to] == 0 인 경우는 경로가 없다는 거니깐, 무조건 거쳐가는 경로를 넣어주어야 한다 
                if (graph[from][to] == 0 || graph[from][to] > graph[from][via] + graph[via][to])
                    graph[from][to] = graph[from][via] + graph[via][to];
            }
        }
    }
}

int main(void)
{
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;

        if (!graph[from][to])
            graph[from][to] = cost;

        else //이미 경로가 있는 경우 최소값 선택  - 문제에 보면 시작 도시와 도착 도시를 연결하는 노선은 하나 이상일 수 있다고 되어있음.
            graph[from][to] = min(graph[from][to], cost);
    }

    floyd();

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cout << graph[i][j] << " ";

        cout << "\n";
    }
    return 0;
}