#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

long long int build[1000001];
long long int tot, last; //ewe

bool cmp(int a, int b)
{
	if (a > b)
	{
		return true;
	}
	return false;
}

int main(void)
{
	int i, n;
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		long long int h;
		scanf("%d", &h);
		last = (int)(lower_bound(build, build + last + 1, h, cmp) - build);
		tot += last;
		build[last] = h;
	}

	printf("%lld\n", tot);
	return 0;
}
