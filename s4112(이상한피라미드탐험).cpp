/***************
피라미드 각 행의 시작 숫자를 배열로 미리 생성
0. b가 a보다 작으면 a랑 b 바꿔주기(a를 더 작은애로...)
1. a와 b의 depth구하고
2. a를 꼭짓점으로 하는 정삼각형 안에 b가 포함되는지 판별하기
***************/
#include <iostream>

using namespace std;
int stad[150] = { 0 };

int main() {
	int tc;
	scanf("%d", &tc);

	stad[1] = 1;
	for (int i = 1; i < 150; i++) {
		stad[i + 1] = stad[i] + i;
	}

	for (int t = 1; t <= tc; t++) {
		int a, b;
		scanf("%d %d", &a, &b);

		if (a > b) {
			swap(a, b);
		}

		int da, db;
		int dep = 1;
		for (; dep < 150; dep++) {
			if (a >= stad[dep] && a < stad[dep + 1]) {
				da = dep;
				break;
			}
		}
		for (; dep < 150; dep++) {
			if (b >= stad[dep] && b < stad[dep + 1]) {
				db = dep;
				break;
			}
		}
		int ret = db - da;

    //b가 있는 행에서 b가 a를 꼭짓점으로 하는 정삼각형에 포함되려면 minr보다 크거나 같고 maxr보다 작거나 같아야함
		int minr = a, maxr = a;
		for (int i = da; i < db; i++) {
			minr = minr + i;
			maxr = maxr + i + 1;
		}

		if (b < minr) ret += minr - b;
		else if (b > maxr) ret += b - maxr;

		printf("#%d %d\n", t, ret);
	}

	return 0;
}
