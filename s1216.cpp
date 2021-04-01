#include <stdio.h>

int main() {
	//freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	for (int tc = 1; tc <= 10; tc++) {
		scanf("%*d");

		char arr[100][101] = { 0, };
		for (int i = 0; i < 100; i++) {
			scanf("%s", arr[i]);
		}

		int max = 0;

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				int k = 99;
				int count = 0;
				while (k > j) {
					if (arr[i][j + count] != arr[i][k]) {
						k += (count ? 1 : 0);
                        //k += count;
						count = 0;
					}
					else {
						count++;
					}
					k -= 1;
				}
				count++;
				if (count > max) max = count;
			}
		}

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				int k = 99;
				int count = 0;
				while (k > j) {
					if (arr[j + count][i] != arr[k][i]) {
						//k += count;
                        k += (count ? 1 : 0);
						count = 0;
					}
					else {
						count++;
					}
					k -= 1;
				}
				count++;
				if (count > max) max = count;
			}
		}

		printf("#%d %d\n", tc, max);
	}


	return 0;
}
