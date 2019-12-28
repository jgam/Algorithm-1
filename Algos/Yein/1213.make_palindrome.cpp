#include<iostream>
using namespace std;
int main(){
	int alphabet[26]={0,};
	char input[51];
	int total=0,odd_idx=-1;
	
	cin>>input;
	for(int input_idx;input[input_idx]!='\0';input_idx++){
		alphabet[input[input_idx]-'A']++;
		//cout<<input[input_idx]-'A';
		total++;
	}
	
	/*for(int i=0;i<26;i++){
	cout<<alphabet[i]<<endl;
	}*/
	
	
	for(int i=0;i<26;i++){
		if(alphabet[i]%2==1){
			if(odd_idx!=-1){
				
				odd_idx=100;
				break;
			}
			else odd_idx=i;
		}
	}
	//cout<<odd_idx;
	if(odd_idx==100){
		cout<<"I'm Sorry Hansoo";
	}
	else{
		for(int i=0;i<26;i++){
			if(alphabet[i]>1){
				
				for(int j=0;j<alphabet[i]/2;j++){
					printf("%c",i+'A');
					//cout<<i<<" "<<alphabet[i]<<endl;
					//alphabet[i]--;
				}
			}
		}
		if(odd_idx!=-1){
			printf("%c",odd_idx+'A');
			alphabet[odd_idx]--;
		}
		
		for(int i=25;i>=0;i--){
			if(alphabet[i]>1){
				
				for(int j=0;j<alphabet[i]/2;j++){
					printf("%c",i+'A');
					
				}
			}
		}
		
	}
}
