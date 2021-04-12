//knapsack 문제
//DP

#include <iostream>

#define MAX_VALUE(x,y) (x>y?x:y)

using namespace std;

const int MAX_N = 101;
const int MAX_K = 1001;
int things[MAX_N][2] = { 0 };
int k[MAX_N][MAX_K] = { 0 };

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int N, K;
		cin >> N >> K;

		for (int i = 1; i <= N; i++) {
			cin >> things[i][0] >> things[i][1];
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= K; j++) {
				if (things[i][0] > j) k[i][j] = k[i - 1][j];
				else {
					k[i][j] = MAX_VALUE(k[i - 1][j - things[i][0]] + things[i][1], k[i - 1][j]);
				}
			}
		}

		cout << "#" << t << " " << k[N][K] << endl;

		for (int i = 0; i < MAX_K; i++) {
			k[0][i] = 0;
		}
		for (int i = 0; i < MAX_N; i++) {
			k[i][0] = 0;
		}
	}

	return 0;
}
