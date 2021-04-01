#include <stdio.h>
#include <iostream>

using namespace std;

int road1[100] = { 0, };
int road2[100] = { 0, };
bool move(int cur) {
	if (cur == 99) return true;
	int res = false;
	if (road1[cur]) {
		res = move(road1[cur]);
		if (res) return res;
	}
	if (road2[cur]) {
		res = move(road2[cur]);
		if (res) return res;
	}
	return false;
}

int main() {
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	for (int t = 1; t <= 10; t++)
	{
		int tc = 0, N = 0;
		scanf(" %d %d" , &tc, &N);

		//int road1[100] = { 0, };
		//int road2[100] = { 0, };

		for (int i = 0; i < N; i++) {
			int a = 0, b = 0;
			scanf(" %d %d" , &a, &b);
			if (road1[a] > 0) road2[a] = b;
			else road1[a] = b;
		}

		bool result = move(0);
		printf(" #%d %d\n" , t, (result ? 1 : 0));
	}
	return 0;
}
