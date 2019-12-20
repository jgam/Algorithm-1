#include<iostream>
using namespace std;
int main(){
	int pay,coin_cnt=0;
	int coins[6]={500,100,50,10,5,1};
	cin>>pay;
	pay=1000-pay;
	cout<<pay<<endl;
	while(pay>0){
		for(int i=0;i<6;i++){
			while(pay-coins[i]>=0){
				coin_cnt++;
				pay-=coins[i];
				cout<<"left coin :"<<coins[i]<<"-->"<<pay<<endl;
				if(pay==0)break;
			}
		}
	}
	cout<<coin_cnt<<endl;
}
