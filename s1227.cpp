#include <iostream>
//#include <stdio.h>

using namespace std;

const int MIRO_SIZE = 100;
char miro[MIRO_SIZE][MIRO_SIZE] = { 0, };

const int dx[4] = { 1,0,-1,0 }; //우하좌상
const int dy[4] = { 0,1,0,-1 };

bool visit[MIRO_SIZE][MIRO_SIZE] = { false, };

int dfs_recursive(int x, int y) {

	visit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int nxtx = x + dx[i];
		int nxty = y + dy[i];

		if (miro[nxty][nxtx] == '3') return 1;
		if (miro[nxty][nxtx] == '0' && !visit[nxty][nxtx]) {
			if (dfs_recursive(nxtx, nxty)) return 1;
		}
	}
	visit[y][x] = false;
	return 0;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	//freopen("input_1227.txt", "r", stdin);

	for (int tc = 0; tc < 10; tc++) {
		int t;
		cin >> t;
        
		int stx, sty;
		for (int i = 0; i < MIRO_SIZE; i++) {
			for (int j = 0; j < MIRO_SIZE; j++) {
				cin >> miro[i][j];
				if (miro[i][j] == '2') {
					stx = j;
					sty = i;
				}
			}
		}

		int result = dfs_recursive(stx, sty);
		cout << "#" << t << " " << result << endl;

		for (int i = 0; i < MIRO_SIZE; i++) {
			for (int j = 0; j < MIRO_SIZE; j++) {
				visit[i][j] = false;
			}
		}
	}
	return 0;
}
