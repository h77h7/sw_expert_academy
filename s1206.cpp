#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

	int len = 0;

	for (int i = 0; i < 10; i++) {
		int arr[1001] = { 0, };

		cin >> len;

		for (int i = 0; i < len; i++) {
			cin >> arr[i];
		}

		int sum = 0;
		for (int i = 2; i < len - 2; i++) {
			int max = 0;
			for (int j = 1; j < 3; j++) {
				if (arr[i - j] >= arr[i + j] && arr[i - j] >= max) max = arr[i - j];
				else if (arr[i - j] < arr[i + j] && arr[i + j] > max) max = arr[i + j];
			}
			if (arr[i] > max) sum += arr[i] - max;

		}
		printf("#%d %d\n", i + 1, sum);
	}

	return 0;
}
