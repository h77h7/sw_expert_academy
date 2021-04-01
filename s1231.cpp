#include <iostream>
#include <stdio.h>

using namespace std;

const int TREE_SIZE = 101;
char tree[TREE_SIZE] = { 0, };

void inorder(int node) {
	if (node < 1 || node >= TREE_SIZE) return;

	inorder(node << 1);
	if(tree[node]) cout << tree[node];
	inorder(node << 1 | 1);
}

int main() {
	freopen("input_1231.txt", "r", stdin);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for (int t = 1; t <= 10; t++) {
		int V;
		cin >> V;

		int v, child1, child2;
		char data;

		if (V & 1) { //V가 홀수일때는 V/2까지 입력이 4개씩 들어옴
			for (int i = 1; i <= (V >> 1); i++) {
				cin >> v >> data >> child1 >> child2;
				tree[v] = data;
			}
		}
		else {   //V가 짝수일때는 V/2-1까지 4개 입력, V/2일때는 3개
			for (int i = 1; i <= (V >> 1) - 1; i++) {
				cin >> v >> data >> child1 >> child2;
				tree[v] = data;
			}
			cin >> v >> data >> child1;
			tree[v] = data;
		}
		for (int i = (V >> 1) + 1; i <= V; i++) {
			cin >> v >> data;
			tree[v] = data;
		}

		cout << "#" << t << " ";
		inorder(1);
		cout << endl;

		for (int i = 0; i < TREE_SIZE; i++) {
			tree[i] = 0;
		}
	}
	return 0;
}

