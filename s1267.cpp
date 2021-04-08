//위상정렬 알고리즘
#include <iostream>

using namespace std;

const int MAX_VERTEX = 1001;
short graph[MAX_VERTEX][MAX_VERTEX] = { 0, };
short result[MAX_VERTEX] = { 0, };

int main() {
	freopen("input_1267.txt", "r", stdin);

	for (int t = 1; t < 11; t++) {
		int V, E;
		cin >> V >> E;

		for (int i = 0; i < E; i++) {
			int from, to;
			cin >> from >> to;

			graph[from][to] = 1;
			graph[to][0]++;
		}

		int remainV = V;
		while (remainV > 0) {
			int temp = 0;
			for (int i = 1; i <= V; i++) {
				if (graph[i][0] == 0) {
					temp = i;
					graph[i][0] = -1;
					break;
				}
			}
			result[V - remainV] = temp;
			for (int i = 1; i <= V; i++) {
				if (graph[temp][i]) {
					graph[i][0]--;
				}
			}
			remainV--;
		}
		cout << "#" << t << " ";
		for (int i = 0; i < V; i++) {
			cout << result[i] << " ";
		}
		cout << endl;

		for (int i = 0; i < MAX_VERTEX; i++) {
			for (int j = 0; j < MAX_VERTEX; j++) {
				graph[i][j] = 0;
			}
		}
	}
	return 0;
}
