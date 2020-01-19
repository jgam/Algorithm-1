#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<cstring>
 
#define endl "\n"
using namespace std;
 
string Inp; // 종이조각 문자열
bool Select[7]; // 각 종이조각 선택했는지 안했는지에 대한 t/f 값 (최대 7)
int Len, Answer; // 종이조각 문자열 길이
 
vector<char> V;
set<int> Visit;

// 2. 초기화
void Initialize()
{
    Inp.clear();
    Visit.clear();
    memset(Select, false, sizeof(Select)); // false로 전부 초기화
    Answer = 0;
    Len = 0;
    V.clear();
}

// 3. 하나의 테스트 케이스에 대한 문자열 입력 받음
void Input()
{
    cin >> Inp;
    Len = Inp.length(); // 변수 Len에 문자열 길이 저장
}

// 소수인지 판단하는 함수 
bool Calculate(int Data)    
{
    if (Data < 2) return false;
    // 16의 경우 약수는 1 2 4 8 16 
    // => 어짜피 2x8 = 8x2니깐 시간복잡도 줄이기 위해서 i*i로 계산하여 검사
    for (int i = 2; i * i <= Data; i++)
    {
        if (Data % i == 0) return false;
    }
    return true;
}

// 5. vector에 담긴 char 문자들을 합쳐서 숫자로 반환
int SumOf_Vector()
{
    int Sum = 0;
    for (int i = 0; i < V.size(); i++)
    {
        Sum = Sum + (V[i] - '0');
        if (i != V.size() - 1) 
        	Sum = Sum * 10;
    }
    return Sum;
}

// 4. DFS 
void DFS(int Cnt)
{
	// 문자열의 길이보다 크면 반환
    if (Cnt > Len) return;
    if (V.size() != 0)
    {
        int Value = SumOf_Vector();
        // 111, 111 -> 순열 dfs를 했을 때, 이렇게 두 개에 대해서 다 검사할 필요 없으므로
        // 중복 체크하기 위해 set에 담음
        
        // int 형으로 반환된 Value값을 가지고, set에 해당 Value값이 없으면 소수검사
        if (Visit.find(Value) == Visit.end())
        {
            Visit.insert(Value);
            // 6. Value가 소수인지 검사를 통해 소수 갯수를 ++ 해준다.
            if (Calculate(Value) == true) 
            		Answer++;
        }
    }
 	
    // 7. 순열 DFS 
    for (int i = 0; i < Len; i++)
    {
        if (Select[i] == true) continue;
        Select[i] = true;
        // 선택한 것이니깐 vector에 집어넣는다.
        V.push_back(Inp[i]);
        DFS(Cnt + 1);
        Select[i] = false;
        V.pop_back();
    }
}
 
void Solution()
{
    DFS(0);
    cout << Answer << endl;
}

// 1. 테스트 케이스 입력받는다.
void Solve()
{
    int Tc;
    cin >> Tc;
    for (int T = 1; T <= Tc; T++)
    {
        Initialize();
        Input();
        Solution();
 
    }
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