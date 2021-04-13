//dijkstra 사용
//swea 제한시간 
#include <iostream>

using namespace std;

const int MAX_PP = 1002;
const int INFINITI = 2000;
int g[MAX_PP][MAX_PP] = { 0 };
int d[MAX_PP];
bool U[MAX_PP];
int heap[MAX_PP] = { 0 };
int heapCount = 0;

int pop() {
	int parent = 1;
	int ret = heap[parent];
	heap[parent] = heap[heapCount--];

	int child = parent << 1;
	if (child + 1 <= heapCount) {
		child = (d[heap[child]] < d[heap[child + 1]]) ? child : child + 1;
	}
	while (child <= heapCount && d[heap[parent]] > d[heap[child]]) {
		int temp = heap[parent];
		heap[parent] = heap[child];
		heap[child] = temp;

		parent = child;
		int child = parent << 1;
		if (child + 1 <= heapCount) {
			child = (d[heap[child]] < d[heap[child + 1]]) ? child : child + 1;
		}
	}
	return ret;
}

void push(int v) {
	heap[++heapCount] = v;
	int child = heapCount;
	int parent = child >> 1;

	while (parent > 0 && d[heap[parent]] > d[heap[child]]) {
		int temp = heap[parent];
		heap[parent] = heap[child];
		heap[child] = temp;

		child = parent;
		parent = child >> 1;
	}
}

int dijkstra(int s, int N) {
	d[s] = 0;
	push(s);

	while (heapCount > 0) {
		int w = pop();
		if (!U[w]) {
			U[w] = true;

			for (int i = 1; i <= N; i++) {
				if (g[w][i] != INFINITI && d[i] > d[w] + g[w][i]) {
					d[i] = d[w] + g[w][i];
					push(i);
				}
			}
		}
	}
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		ret += d[i];
	}
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	int tc;
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {
		int N;
		scanf("%d", &N);

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				scanf("%d", &g[i][j]);
				if (i != j && g[i][j] == 0) {
					g[i][j] = INFINITI;
				}
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				d[j] = INFINITI;
				U[j] = false;
			}
			g[i][0] = dijkstra(i, N);
		}

		int minCC = INFINITI;
		for (int i = 1; i <= N; i++) {
			if (minCC > g[i][0]) minCC = g[i][0];
		}

		printf("#%d %d\n", t, minCC);
	}
}
