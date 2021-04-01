#include <iostream>
//#include <stdio.h>

using namespace std;

const int dx[3] = { -1,0,1 };
const int dy[3] = { 0,1,0 };

int main() {
	//freopen("input.txt","r",stdin);

	for (int i = 0; i < 10; i++) {
		int minIdx = -1;
		int minCount = 100000;
		int ladder[101][102] = { 0, };
		int tc = 0;
		cin >> tc;

		for (int j = 0; j < 100; j++) {
			for (int k = 1; k < 101; k++) {
				cin >> ladder[j][k];
			}
		}

		for (int j = 1; j < 101; j++) {
			int curx = j;
			int cury = 0;
			if (ladder[cury][curx] != 1) continue;

			int count = 1;
			while (1) {
				if (ladder[cury][curx - 1] == 1) {
					while (ladder[cury][curx-1] == 1) {
						curx -= 1;
						count++;
					}
				}
				else if (ladder[cury][curx + 1] == 1) {
					while (ladder[cury][curx+1] == 1) {
						curx += 1;
						count++;
					}
				}

				if (ladder[cury + 1][curx] == 1) {
					cury += 1;
					count++;
				}
				else break;
			}
			if (count <= minCount) {
				minCount = count;
				minIdx = j;
			}
		}

		printf("#%d %d\n",tc,minIdx-1);
	}

	return 0;
}
