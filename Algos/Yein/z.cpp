#include <iostream>
#include<cmath>
using namespace std;

int n, r, c;

int cnt;

void Z(int size, int y, int x)
{
        if (size == 2)

        {
                 
                 for(int i=0;i<2;i++){
                 	for(int j=0;j<2;j++){
                 		if (y + i == r && x + j == c){
                 			cout<<cnt;
						 	return;
						 }
                 		cnt++;
					 }
				 }

				
					
                 return; 

        }
        Z(size / 2, y, x);

        Z(size / 2, y, x + size / 2);

        Z(size / 2, y + size / 2, x);

        Z(size / 2, y + size / 2, x + size / 2);

}

 

int main()
{

        cin >> n >> r >> c;
 
        Z(pow(2,n), 0, 0);

        return 0;

}

 
