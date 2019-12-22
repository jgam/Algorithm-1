#include<iostream>
#include<algorithm>
using namespace std;
int count(char dna[1000][51],int ind1,int ind2, int index) {
	int result = 0;
	for (int i = 0; i < index; i++) {
		if (dna[ind1][i] != dna[ind2][i])result++;
	}
	return result;
}
int main() {
	char dna[1000][51];
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)cin >> dna[i][j];
	}
	
	int hd = 0;
	for (int i = 0; i < m; i++) {
		int a = 0, t = 0, g = 0, c = 0;
		for (int j = 0; j < n; j++) {
			switch (dna[j][i]) {
			case 'A':a++; break;
			case 'C':c++; break;
			case 'G':g++; break;
			case 'T':t++; break;
			}
		}
		int maxnum = max(max(a,c),max(g,t));
		hd += (n - maxnum);
		if (maxnum == a)cout << 'A';
		else if (maxnum == c)cout << 'C';
		else if (maxnum == g)cout << 'G';
		else cout << 'T';
	}
	

	
	
	cout << endl << hd;
}
