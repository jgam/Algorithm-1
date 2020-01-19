#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void){
    int tc;
    cin>>tc;
    int x1, x2, y1, y2, r1, r2, ret;
    for(int i=0; i<tc; i++){
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        

        double dist = sqrt(pow(x2- x1, 2) + pow(y2 - y1, 2));
        
        int big = max(r1, r2);
        int small = min(r1, r2);

        if(dist == 0.0){
            if(big == small)
                ret = -1;//동일한 원인 경우 
            else
                ret = 0;//겹치지 않 음 (큰 원안에 작은 원이 들어 있음) 
        }else{
            if(big-small < dist && big+small > dist)//원의 두점이 겹치는 경 우 
                ret = 2;
            else if(big+small == dist || big-small == dist) //내접, 외접 
                ret = 1;
            else //멀리 떨어져 있어 겹치지 않는 경우 
                ret = 0;
        }
        cout<<ret<<endl;
    }
    return 0;
}
