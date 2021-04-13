//floyd 사용
//모든쌍 최단거리
#include <iostream>

using namespace std;

#define MIN_DIS(x,y) (x<y?x:y)

const int MAX_PP = 1001;
const int INFINITI = 2000;
int g[MAX_PP][MAX_PP] = { 0 };

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

		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (i != k && i != j && j != k) {
						g[i][j] = MIN_DIS(g[i][j], g[i][k] + g[k][j]);
					}
				}
			}
		}
		int minCC = INFINITI;
		for (int i = 1; i <= N; i++) {
			g[i][0] = 0;
			for (int j = 1; j <= N; j++) {
				g[i][0] += g[i][j];
			}
			if (g[i][0] < minCC) minCC = g[i][0];
		}
		printf("#%d %d\n", t, minCC);
	}
	return 0;
}
