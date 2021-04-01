#include <stdio.h>
#include <iostream>
//#include <string.h>

using namespace std;

int main() {

	//freopen("input.txt", "r", stdin);
	for (int i = 0; i < 10; i++) {
		int N = 0;
		char arr[101] = { 0, };
		char pwd[101] = { 0, };

		scanf("%d %s", &N, arr);

		int idx = 0;
		pwd[idx] = arr[0];
		for (int j = 1; j < N; j++) {
			if (pwd[idx] == arr[j]) {
				pwd[idx] = 0;
				idx--;
			}
			else pwd[++idx] = arr[j];
		}

		printf("#%d %s\n", i + 1, pwd);
	}


	return 0;
}
