#include<iostream>
using namespace std;
int nums[1000001] = { 0, };
int main() {
	int min, max;
	
	cin >> min >> max;
	
	nums[1] = 1;
	for (int i = 2; i*i < max + 1; i++) {
		if (nums[i] == 0) {
			for (int j = i*i;j<=max ;j+=i) {
				
				nums[j] = 1;
			}
		}
		
	}
	for (int i = min; i < max + 1; i++) {
		if (nums[i] == 0)cout << i<< '\n';
	}

}