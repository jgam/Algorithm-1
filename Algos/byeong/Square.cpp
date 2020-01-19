#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
 
class Pos
{
public:
    int x, y;
 
    bool operator<(Pos& temp)
    {
        if (this->x < temp.x)return true;
        return false;
    }
};
 
//x좌표와 y좌표를 바꾼다.
void change(vector<Pos>& pos)
{
    for (int i = 0; i < 4; ++i)
    {
        int temp;
        temp = pos[i].x;
        pos[i].x = pos[i].y;
        pos[i].y = temp;
    }
}
 
//두 점의 거리를 구한다.
int Minus(int a, int b)
{
    int result = a - b;
    return result*result;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int TestCase;
    cin >> TestCase;
 
    while (TestCase)
    {
        vector<Pos> pos(4);
        //0->윗면, 1->오른쪽 2->아랫면 3->왼쪽 4,5->대각선
        float check[6];
        for (int i = 0; i < 4; ++i){
            cin >> pos[i].x >> pos[i].y;
            pos[i].x += 100000;
            pos[i].y += 100000;
        }
 
        //x좌표 기준으로 오름차순 정렬
        sort(pos.begin(), pos.end());
 
        //x,y 좌표 교환
        change(pos);
 
        //x값 같은 점끼리 다시 정렬
        sort(pos.begin(), pos.begin() + 2);
        sort(pos.end() - 2, pos.end());
 
        //원래 좌표로 
        change(pos);
 
        //점들사이의 거리와 대각선 거리를 구한다.
        check[0] = sqrtf(Minus(pos[1].y, pos[0].y) + Minus(pos[1].x, pos[0].x));
        check[1] = sqrtf(Minus(pos[3].x, pos[1].x) + Minus(pos[3].y, pos[1].y));
        check[2] = sqrtf(Minus(pos[3].y, pos[2].y) + Minus(pos[3].x, pos[2].x));
        check[3] = sqrtf(Minus(pos[2].x, pos[0].x) + Minus(pos[2].y, pos[0].y));
        check[4] = sqrtf(Minus(pos[0].x, pos[3].x) + Minus(pos[0].y, pos[3].y));
        check[5] = sqrtf(Minus(pos[1].x, pos[2].x) + Minus(pos[1].y, pos[2].y));
 
        bool success = true;
 
        //점들이 같은 직선상에 있는지 검사 -> 마를모 모양 때문에 안된다.
        /*if (pos[0].y != pos[2].y || pos[1].y != pos[3].y || pos[0].x != pos[1].x || pos[2].x != pos[3].x)
            success = false;*/
 
        //네 변의 길이 확인
        for (int i = 1; i < 4; ++i)
        {
            if (check[i] != check[i - 1])
                success = false;
        }
        //대각선 길이 확인
        if (check[4] != check[5])
            success = false;
 
        if (success)cout << "1" << endl;
        else cout << "0" << endl;
 
        TestCase--;
    }
}
