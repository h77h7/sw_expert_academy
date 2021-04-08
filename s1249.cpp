//보급로
//heap을 이용한 dijkstra
#include <iostream>
#include <stdio.h>

using namespace std;

const int dx[4] = { 1,0,-1,0 }; //우 하 좌 상
const int dy[4] = { 0,1,0,-1 };
const int MAX_VERTEX = 100;
int map[MAX_VERTEX][MAX_VERTEX] = { 0, };
int D[MAX_VERTEX][MAX_VERTEX] = { 0, };
bool U[MAX_VERTEX][MAX_VERTEX] = { false };
int N;

struct grid {
	int x;
	int y;
};

const int heapSize = MAX_VERTEX*MAX_VERTEX/2;
const int INFINITI = 987564321;
grid heap[heapSize] = { 0 };
int heapCount = 0;

void push(int x, int y) {
	heap[++heapCount].x = x;
	heap[heapCount].y = y;

	int child = heapCount;
	int parent = child >> 1;

	while (parent > 0 && D[heap[parent].y][heap[parent].x] > D[heap[child].y][heap[child].x]) {
		int tmpx = heap[parent].x;
		int tmpy = heap[parent].y;
		heap[parent].x = heap[child].x;
		heap[parent].y = heap[child].y;
		heap[child].x = tmpx;
		heap[child].y = tmpy;

		child = parent;
		parent = child >> 1;
	}
}


grid pop() {
	int parent = 1;
	grid ret = heap[parent];
	heap[parent].x = heap[heapCount].x;
	heap[parent].y = heap[heapCount].y;
	heapCount--;
	//heap[heapCount--] = 0;

	int child = parent << 1;
	if (child + 1 <= heapCount) {
		child = D[heap[child].y][heap[child].x] > D[heap[child + 1].y][heap[child + 1].x] ? child + 1 : child;
	}

	while (child <= heapCount && D[heap[parent].y][heap[parent].x] > D[heap[child].y][heap[child].x]) {
		int tmpx = heap[parent].x;
		int tmpy = heap[parent].y;
		heap[parent].x = heap[child].x;
		heap[parent].y = heap[child].y;
		heap[child].x = tmpx;
		heap[child].y = tmpy;

		parent = child;
		child = parent << 1;
		if (child + 1 <= heapCount) {
			child = D[heap[child].y][heap[child].x] > D[heap[child + 1].y][heap[child + 1].x] ? child + 1 : child;
		}
	}
	return ret;
}

int dijkstra() {
	D[0][0] = 0;
	push(0, 0);

	while (heapCount > 0) {
		grid w = pop();

		if (U[w.y][w.x] == false) {
			U[w.y][w.x] = true;

			for (int i = 0; i < 4; i++) {
				int nx = w.x + dx[i];
				int ny = w.y + dy[i];

				if (nx >= 0 && ny >= 0 && nx < N && ny < N && D[ny][nx] > D[w.y][w.x] + map[ny][nx]) {
					D[ny][nx] = D[w.y][w.x] + map[ny][nx];
					push(nx, ny);
				}
			}
		}
	}
	return D[N - 1][N - 1];
}
int main() {
	freopen("input_1249.txt", "r", stdin);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		//int N;
		cin >> N;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				//cin >> map[i][j];
				scanf("%1d", &map[i][j]);
				D[i][j] = INFINITI;
				U[i][j] = false;
			}
		}

		int result = dijkstra();

		cout << "#" << t << " " << result << endl;
	}
	return 0;
}
