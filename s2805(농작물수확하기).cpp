/******************
숫자 읽으면서 규칙에 맞게 더해주기
******************/
#include <iostream>

using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);

	int line[49] = { 0 };

	for (int t = 1; t <= tc; t++) {
		int N;
		scanf("%d", &N);

		int ret = 0;

		int half = N / 2;
		for (int i = 0; i <= half; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%1d", &line[j]);
			}
			ret += line[half];
			for (int j = 1; j <= i; j++) {
				ret += line[half - j];
				ret += line[half + j];
			}
		}

		for (int i = half - 1; i >= 0; i--) {
			for (int j = 0; j < N; j++) {
				scanf("%1d", &line[j]);
			}
			ret += line[half];
			for (int j = 1; j <= i; j++) {
				ret += line[half - j];
				ret += line[half + j];
			}
		}

		printf("#%d %d\n", t, ret);
	}

	return 0;
}
