#include <iostream>
#include<cmath>
using namespace std;
int x, y, r1, x2, y2, r2;
int dist() {
	return (x - x2)*(x - x2) + (y - y2)*(y - y2);
}
int main() {
	int tc;
	cin >> tc;
	for(int i=0;i<tc;i++) {
		cin >> x >> y >> r1 >> x2 >> y2 >> r2;

		if (r1 == r2 && x == x2 && y == y2)
			cout << -1;
		else if (dist() > pow(r1 + r2,2))
			cout << 0;
		else if (dist() == pow(r1 + r2,2))
			cout << 1;
		else if (dist() < pow(r1 + r2,2)) {
			if (dist() > pow(r2 - r1,2))
				cout << 2;
			else if (dist() == pow(r2 - r1,2))
				cout << 1;
			else if (dist() < pow(r2 - r1,2))
				cout << 0;
		}
		cout << endl;
	}
}
