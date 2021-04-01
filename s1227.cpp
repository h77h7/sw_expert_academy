#include <iostream>

using namespace std;

const int MIRO_SIZE = 100;
const int QUEUE_SIZE = 8000;

const int dx[4] = { 1,0,-1,0 }; //우하좌상
const int dy[4] = { 0,1,0,-1 };

char miro[MIRO_SIZE][MIRO_SIZE] = { 0, };

enum {
	WALL = '1',
	ROAD = '0',
	GOAL = '3',
	START = '2'
};

int bfs_loop(int x, int y) {
	int* q = (int *)malloc(sizeof(int)*QUEUE_SIZE);

	int front = 0, rear = 0;

	q[++rear] = x;
	q[++rear] = y;

	while (front != rear) {
		int x = q[(++front) % QUEUE_SIZE];
		int y = q[(++front) % QUEUE_SIZE];

		if (miro[y][x] == GOAL) return 1;
		if (miro[y][x] != WALL) {
			miro[y][x] = WALL;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (miro[ny][nx] != WALL) {
					q[(++rear) % QUEUE_SIZE] = nx;
					q[(++rear) % QUEUE_SIZE] = ny;
				}
			}
		}

	}
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

		int result = bfs_loop(stx, sty);
		cout << "#" << t << " " << result << endl;

	}
	return 0;
}
