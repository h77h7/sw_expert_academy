#include <stdio.h>
#include <iostream>

using namespace std;

bool move(int cur,int* road1,int* road2) {
	if (cur == 99) return true;
	
	//다음 위치 찾고 길 없애기
	int a = road1[cur];
	int b = road2[cur];
	road1[cur] = -1;
	road2[cur] = -1;

	if (a <= 0 && b <= 0) return false;
	else if (a > 0 && b > 0) return move(a, road1, road2) | move(b, road1, road2);
	else if (a > 0) return move(a, road1, road2);
	else if (b > 0) return move(b, road1, road2);

}

int main() {
	//freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	for (int t = 1; t <= 10; t++)
	{
		int tc = 0, N = 0;
		scanf("%d %d", &tc, &N);

		int road1[100] = { 0, };
		int road2[100] = { 0, };

		for (int i = 0; i < N; i++) {
			int a = 0, b = 0;
			scanf(" %d %d", &a, &b);
			if (road1[a] > 0) road2[a] = b;
			else road1[a] = b;
		}

		bool result = move(0, road1, road2);
		printf("#%d %d\n", t, (result ? 1 : 0));
	}
	return 0;
}
