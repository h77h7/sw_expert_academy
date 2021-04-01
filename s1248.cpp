#include <iostream>
#include <stdio.h>

using namespace std;

const int TREE_SIZE = 10001;
int tree[3][TREE_SIZE];

int nodeCount(int node) {
	if (!tree[0][node]) return 1;
	else if (!tree[1][node]) return 1 + nodeCount(tree[0][node]);
	else return 1 + nodeCount(tree[0][node]) + nodeCount(tree[1][node]);
}

int main() {
	freopen("input_1248.txt", "r", stdin);

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	tc++;

	for (int t = 1; t < tc; t++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < TREE_SIZE; j++) {
				tree[i][j] = 0;
			}
		}

		int V, E, v1, v2;
		cin >> V >> E >> v1 >> v2;

		int parent, child;
		for (int i = 0; i < E; i++) {
			cin >> parent >> child;

			if (tree[0][parent]) tree[1][parent] = child;
			else tree[0][parent] = child;

			//child노드의 부모정보 저장
			tree[2][child] = parent;
		}

		//공통부모 구하기
		int v1Parents[200] = { 0, };
		int v2Parents[200] = { 0, };

		v1Parents[0] = tree[2][v1];
		v2Parents[0] = tree[2][v2];
		for (int i = 1; i < 200; i++) {
			if (!v1Parents[i - 1] && !v2Parents[i - 1]) break;
			v1Parents[i] = tree[2][v1Parents[i - 1]];
			v2Parents[i] = tree[2][v2Parents[i - 1]];
		}

		int commonP = 0;
		for (int i = 0; i < 200; i++) {
			for (int j = 0; j < 200; j++) {
				if (!v1Parents[i] || !v2Parents[j]) break;
				if (v1Parents[i] == v2Parents[j]) {
					commonP = v1Parents[i];
					break;
				}
			}
			if (commonP) break;
			if (!v1Parents[i]) break;
		}

		//서브트리 수 구하기
		int subNum = nodeCount(commonP);


		cout << "#" << t << " " << commonP << " " << subNum << endl;
	}
}