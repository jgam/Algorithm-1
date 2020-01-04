#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(string a, string b) {
	if (a.length() == b.length())return a < b;
	return a.length() < b.length();
}
int main() {
	int tc;
	cin >> tc;
	vector<string>words;
	string word;

	for (int i = 0; i < tc; i++) {
		cin >> word;
		words.push_back(word);
	}
	cout << endl;
	sort(words.begin(),words.end(),cmp);

	//sort(words.begin(), words.end());
	vector<string>result;
	for (int i = 0; i < words.size(); i++) {
		if (i!=0&& result.back() != words[i]) {
			result.push_back(words[i]);
		}
		if (i == 0)result.push_back(words[i]);
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i]<<endl;
	}

	
}