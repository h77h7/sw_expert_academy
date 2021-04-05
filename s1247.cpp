#include <stdio.h>

int cus_num;
int cus_x[11] = { 0, };
int cus_y[11] = { 0, };
//bool visit[11] = { false, };
unsigned short visit = 0;
int distances[11][11] = { 0, };
int finalDis[11] = { 0, };
int com_x, com_y;
int min = 100000;

void move(int idx, int count) {
	bool flag = false;

	int cur_x = cus_x[idx];
	int cur_y = cus_y[idx];

	for (int i = 0; i <= cus_num; i++) {
        if(!((1<<i) & visit)){
            flag = true;
            
            if (!distances[idx][i]) {
				int dis_x = cur_x > cus_x[i] ? cur_x - cus_x[i] : cus_x[i] - cur_x;
				int dis_y = cur_y > cus_y[i] ? cur_y - cus_y[i] : cus_y[i] - cur_y;

				distances[idx][i] = dis_x + dis_y;
				distances[i][idx] = distances[idx][i];
			}

			int nxt_count = count + distances[idx][i];
			if (nxt_count < min) {
				visit |= (1<<i);
				move(i, nxt_count);
				visit &= ~(1<<i);
			}
        }
	}
	if (!flag) {	//모두 방문
		if (!finalDis[idx]) {
			int final_xdis = com_x > cur_x ? com_x - cur_x : cur_x - com_x;
			int final_ydis = com_y > cur_y ? com_y - cur_y : cur_y - com_y;
			finalDis[idx] = final_xdis + final_ydis;
		}
		count = count + finalDis[idx];
		if (count < min) min = count;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int tc;
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {
		int minDis = 10000;
		int minIdx = 1;

		scanf("%d", &cus_num);
		scanf("%d %d %d %d", &cus_x[0], &cus_y[0], &com_x, &com_y);		//cus_x[0]과 cus_y[0]에는 집 저장
		for (int i = 1; i <= cus_num; i++) {	//인덱스 1부터 손님 저장
			scanf("%d %d", &cus_x[i], &cus_y[i]);
		}

		move(0, 0);

		printf("#%d %d\n", t, min);
		min = 100000;
        visit = 0;
		for (int i = 0; i < 11; i++) {
			finalDis[i] = 0;  cus_x[i] = 0; cus_y[i] = 0;
            for(int j=0; j<11; j++){
                distances[i][j] = 0;
            }
		}
	}
	return 0;
}
