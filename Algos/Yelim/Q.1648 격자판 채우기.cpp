#include <iostream>
#include <cstring>

using namespace std; 

const int MAX = 14;
const int MOD = 9901;

int N, M;
int D[MAX*MAX][1 << MAX];
//  D[i][bit] : i-1 번 타일까지 채워져있고, i번으로부터 M개의 타일의 상태가 bit인 경우의 수 
// ex. D[7][5] : 7번째 칸부터 M개의 칸이 상태가 5이다. ( 5 = 0 0 0 1 0 1 (2) ) 

int tiling(int i, int bit) {

        //전부 채워졌다면 결과에 1을 더해준다.
        if (i == N * M && bit == 0)
                 return 1;

        //마지막 칸까지 갔는데 다 채워지지 않은 경우 실패니깐 0을 반환
        if (i >= N * M)
                 return 0;       
		
        // D[i][bit] : i-1 번 타일까지 채워져있고,
        // i번부터 M개의 타일의 상태가 bit인 경우의 수 
        int &result = D[i][bit];		
        if (result != -1)
                 return result;
                 
        result = 0;

        // i번째가 이미 채워져 있어서 칸을 채울 수 없는 경우
        // 다음 칸을 채워야 함
        // bit를 오른쪽으로 한비트 쉬프트
        if (bit & 1)
            	  result = tiling(i + 1, (bit >> 1));
        //해당 칸이 칠해져있지 않다면 채워야함
        else {
        		//해당 칸은 현재 위치에서 항상 좌상단이라고 가정하고 푼다
                 //2 * 1           
                 result = tiling(i + 1, (bit >> 1) | (1 << (M - 1)));

                 //1 * 2
                 //M - 1번째 타일에 위치하지 않았고 (이럴 경우 1 * 2를 놓을 수 없으니깐) 
                 //다음칸도 비어있을 경우
                 if ((i % M) != (M - 1) && (bit & 2) == 0)
                         result += tiling(i + 2, bit >> 2);
        }
        return result %= MOD;
} 

int main(void)
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        cin >> N >> M; // N x M 칸

        memset(D, -1, sizeof(D));
        cout << tiling(0, 0) << "\n";

        return 0;
}