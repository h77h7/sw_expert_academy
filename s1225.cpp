#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);

	for (int i = 1; i <= 10; i++) {
		queue<int> que;
		scanf("%*d");

		for (int j = 0; j < 8; j++) {
			int temp = 0;
			scanf("%d", &temp);
			que.push(temp);
		}

		int k = 1;
		while (1) {
			if (k == 6) k = 1;
			int temp = que.front();
			que.pop();
			temp -= k;
			if (temp <= 0) {
				que.push(0);
				break;
			}
			que.push(temp);
			k++;

		}
		printf("#%d ", i);
		for (int j = 0; j < 8; j++) {
			printf("%d ", que.front());
			que.pop();
		}
		printf("\n");

	}
	
	return 0;
}
