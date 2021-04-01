#include <stdio.h>

int visit[10] = { 0, }; //방문 표시
int min = 10000;

void re(int N, int sum, int curx, int cury, int* cos_x, int* cos_y,int home_x, int home_y) {
	int flag = 1;
	for (int i = 0; i < N; i++) {
		if (visit[i] == 0) {
			flag = 0;
			visit[i] = 1;

			int x_dis = curx - cos_x[i];
			x_dis = x_dis > 0 ? x_dis : -x_dis;
			int y_dis = cury - cos_y[i];
			y_dis = y_dis > 0 ? y_dis : -y_dis;
			re(N, sum + x_dis + y_dis, cos_x[i], cos_y[i], cos_x, cos_y, home_x, home_y);
			visit[i] = 0;
		}
	}
	if (flag) {
		int x_dis = curx - home_x;
		x_dis = x_dis > 0 ? x_dis : -x_dis;
		int y_dis = cury - home_y;
		y_dis = y_dis > 0 ? y_dis : -y_dis;
		sum += x_dis + y_dis;
		if (sum < min) min = sum;
	}

}

int main() {
	//freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int tc = 0;
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {
		int N = 0;
		scanf(" %d", &N);

		int com_x = 0, com_y = 0;
		int home_x = 0, home_y = 0;
		int cos_x[10] = { 0, }, cos_y[10] = { 0, };
		scanf("%d %d %d %d", &com_x, &com_y, &home_x, &home_y);
		for (int i = 0; i < N; i++) {
			scanf(" %d %d", &cos_x[i], &cos_y[i]);
		}

		re(N, 0, com_x, com_y, cos_x, cos_y, home_x, home_y);

		printf("#%d %d\n", t, min);

		min = 10000;
	}
	


	return 0;
}
