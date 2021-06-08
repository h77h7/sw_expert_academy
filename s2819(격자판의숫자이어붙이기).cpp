/*****************
16개의 숫자에 대해 완전탐색해도 2^16이면 해결가능
set이용해서 중복 제거
*****************/
#include <iostream>
#include <set>

using namespace std;

const int dx[4] = { 1,0,-1,0 };	//오아왼위
const int dy[4] = { 0,1,0,-1 };
set<int> s;
int input[6][6] = { 0 };

void dfs(int y, int x, int cnt, int num) {
	if (cnt == 6) {
		num *= 10;
		num += input[y][x];
		s.insert(num);
		return;
	}

	num *= 10;
	num += input[y][x];
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(input[ny][nx]>=0)
			dfs(ny, nx, cnt + 1, num);
	}
}


int main() {
	int tc;
	scanf("%d", &tc);

	for (int i = 0; i < 6; i++) {
		input[0][i] = -1;
		input[5][i] = -1;
		input[i][0] = -1;
		input[i][5] = -1;
	}

	for (int t = 1; t <= tc; t++) {
		for (int i = 1; i < 5; i++) {
			for (int j = 1; j < 5; j++) {
				scanf("%d", &input[i][j]);
			}
		}

		for (int i = 1; i < 5; i++) {
			for (int j = 1; j < 5; j++) {
				dfs(i,j, 0, 0);
			}
		}
		printf("#%d %d\n", t, s.size());
		s.clear();
	}

	return 0;
}
