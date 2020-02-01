#include<iostream>
#include <cstring> //memset
using namespace std;
int width, height;
int map[50][50], visited[50][50];
int dy[8] = { -1,-1,-1,0,0,1,1,1 }, dx[8] = { -1,0,1,-1,1,-1,0,1 };
void dfs(int row, int col) {
	int newR = row, newC = col;
	
	visited[row][col] = 1;
	for (int i = 0; i < 8; i++) {
		
		newR = row + dy[i];
		newC = col + dx[i];
		if (newR < height && newR >= 0 && newC < width && newC >= 0) {
			if (map[newR][newC] == 1 && visited[newR][newC] == 0) {
				dfs(newR, newC);
			}
		}

	}
	return;

}
int main() {

	int n, cnt = 0;
	while (true) {
		cnt = 0;
		memset(visited, 0, sizeof(visited));
		cin >> width >> height;
		if (width == 0 && height == 0)break;

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				cin >> n;
				map[i][j] = n;
			}
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (map[i][j] == 1 && visited[i][j] == 0) {

					cnt++;
					
					dfs(i, j);

				}
			}
		}

		cout <<"cnt:" <<cnt<<endl;
	}



}