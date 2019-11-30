//2608 _ 동아리 회장선거
#include <cstdio>
#include <iostream>
#include <string>

int n;
char ans[7];

void dfs(int now)
{
	if (now == n)
	{
		printf("%s\n", ans);
		return;
	}
	ans[now] = 'O';
	dfs(now + 1);
	ans[now] = 'X';
	dfs(now + 1);

}

int main()
{
	scanf("%d", &n);
	dfs(0);
}
