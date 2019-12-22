#include<iostream>
#include<algorithm>
#include<string>
#include<set>
#include<vector>
using namespace std;

int main(){
	int n,m;
	string name;
	set<string> heard_list;
	vector<string> both_list;
	cin>>n>>m;
	
	for(int i=0;i<n;i++){//들어보지 못한 사람  
		cin>>name;
		heard_list.insert(name);
		
	}
	set<string>::iterator it;
	for(int i=0;i<m;i++){ //보지 못한 사람 
		cin>>name;
		it=heard_list.find(name);// 듣지 못한 사람 리스트에 있는지 확인  
		if(it!=heard_list.end()){ //만약 있으면 both_list에 추가해준다. 
			both_list.push_back(name);
		}
	}
	sort(both_list.begin(),both_list.end());//정렬 
	cout<<both_list.size()<<endl;
	
	for(int i=0;i<both_list.size();i++){
		cout<<both_list[i]<<endl;
	}
}
