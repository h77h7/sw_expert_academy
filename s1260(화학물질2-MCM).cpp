//'그래서 각 테스트 케이스에서 추출된 행렬들 사이의 곱셈에는 반드시 1개의 수행 가능한 행렬 곱셈 순서만 존재한다.'
//위 조건이 없으면 곱셈 순서를 찾기 위해 dfs필요

//카운트 기법 사용
//3x4 2x3 4x5
//1 2 3 4 5
//0 1 2 2 1
//--- 노 드 인 덱 스 ---
//
#include <iostream>

#define MIN_MUL(x,y) (x<y?x:y)

using namespace std;

const int MAX_N = 100;
const int MAX_SUBM = 20;
const int INFINITI = 9876543210;

int matrix[MAX_N][MAX_N] = { 0 };
int d[MAX_SUBM + 1] = { 0 };
int dp[MAX_SUBM + 1][MAX_SUBM + 1] = { 0 };

int main() {
	freopen("sample_input.txt", "r", stdin);
	int tc;
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {
		int n;
		scanf("%d", &n);

		int ms[MAX_SUBM][2] = { 0 };

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &matrix[i][j]);
			}
		}
		
		//ms배열에 매트릭스 row,column 수 넣기
		int msIdx = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j]) {
					int tempJ = j;
					int tempI = i;

					while (matrix[tempI][tempJ]) {
						while (matrix[tempI][tempJ]) {
							matrix[tempI][tempJ] = 0;
							tempJ++;
						}
						if (!ms[msIdx][1]) ms[msIdx][1] = tempJ - j;
						tempI++;
						tempJ = j;
					}
					ms[msIdx][0] = tempI - i;
					j += (ms[msIdx][1] - 1);
					msIdx++;
				}
			}
		}

		//d[0]에 들어갈 값 찾기
		int dIdx = 0;
		int curMsIdx = 0;
		for (int i = 0; i < msIdx; i++) {
			int startCandi = ms[i][0];
			bool flag = true;
			for (int j = 0; j < msIdx; j++) {
				if (ms[j][1] == startCandi) {
					flag = false;
					break;
				}
			}
			if (flag) {
				d[dIdx++] = startCandi;
				curMsIdx = i;
				break;
			}
		}

		//d 배열 채우기
		while (true) {
			d[dIdx++] = ms[curMsIdx][1];
			if (dIdx > msIdx) break;
			for (int i = 0; i < msIdx; i++) {
				if (ms[i][0] == ms[curMsIdx][1]) {
					curMsIdx = i;
					break;
				}
			}
		}

		//dp테이블 채우기
		for (int i = 1; i <= msIdx; i++) {
			dp[i][i] = 0;
		}

		for (int r = 1; r < msIdx; r++) {
			for (int i = 1; i <= msIdx - r; i++) {
				int j = i + r;
				dp[i][j] = INFINITI;
				for (int k = i; k < j; k++) {
					dp[i][j] = MIN_MUL(dp[i][j], dp[i][k] + dp[k + 1][j] + d[i - 1] * d[k] * d[j]);
				}
			}
		}
		printf("#%d %d\n", t, dp[1][msIdx]);
	}
	return 0;
}
