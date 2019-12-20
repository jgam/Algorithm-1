#include<iostream>
using namespace std;
int main(){
	char name[101];
	cin>>name;
	
	for(int i=0;name[i]!='\0';i++){
		if(i==0)cout<<name[i];
		else if(name[i-1]=='-')cout<<name[i];
	}
}
