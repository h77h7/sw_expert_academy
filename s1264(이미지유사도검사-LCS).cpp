//LCS(최장공통부분문자열)
#include <iostream>	

#define MAX_COMMON(x,y) (x>y?x:y)

using namespace std;

const int MAX_N = 502;

char a[MAX_N] = { 0 };
char b[MAX_N] = { 0 };
int dp[MAX_N][MAX_N] = { 0 };

int main() {
	//freopen("input.txt", "r", stdin);
	int tc;
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {

		int N;
		scanf("%d", &N);

		scanf(" %s %s", a + 1, b + 1);

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
				else {
					dp[i][j] = MAX_COMMON(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		printf("#%d %.2f\n", t, (float)dp[N][N] / N*100);
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= N; j++) {
				dp[i][j] = 0;
			}
		}
	}
	return 0;
}
