#include<iostream>
using namespace std;
int main(){
	int n,m,k,people,team=0;
	cin>>n>>m>>k;
	
	people=(n+m)-k;
	
	while(true){
		if(n-2>=0&&m>=1&&people-3>=0){
			team++;
			people-=3;
			n-=2;
			m-=1;
			
		}
		else break;
	}
	cout<<team<<endl;
}
