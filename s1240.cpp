#include <stdio.h>

int main() {
	//freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	//const char nums[10][8] = { "0001101","0011001","0010011","0111101","0100011","0110001","0101111","0111011","0110111","0001011" };
	int nums[64] = { -1, };
	nums[13] = 0;
	nums[25] = 1;
	nums[19] = 2;
	nums[61] = 3;
	nums[35] = 4;
	nums[49] = 5;
	nums[47] = 6;
	nums[59] = 7;
	nums[55] = 8;
	nums[11] = 9;

	int tc = 0;
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {

		int n = 0, m = 0;
		scanf("%d %d", &n, &m);

		char input_arr[50][100] = { 0, };
		int pss_row = -1;
		int end_idx = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf(" %c", &input_arr[i][j]);
				if (input_arr[i][j] == '1') {
					pss_row = i;
					end_idx = j;
				}
			}
		}

		//암호가 있는 row의 반대쪽 끝부터 탐색하여 최초 1의 위치 찾기
		/*int start_idx = 100;
		int end_idx = -1;
		for (int i = m - 1; i >= 0; i--) {
			if (input_arr[pss_row][i] == '1') {
				end_idx = i;
				break;
			}
		}*/
		int start_idx = end_idx - 55;  //start_idx부터 end_idx에 암호 존재

		int num_pss[8] = { 0, };

		int idx = 0;
		for (int i = start_idx; i < start_idx + 56; i += 7) {
			int temp = 0;
			for (int j = 0; j < 7; j++) {
				if (input_arr[pss_row][i + j] == '1') {
					temp |= (1 << (6-j));
				}
			}
			num_pss[idx++] = nums[temp];
		}
		//int flag = 1;
		//for (int i = 0; i < 8; i++) {
		//	for (int j = 0; j < 11; j++) {
		//		flag = 1;
		//		for (int k = 0; k < 7; k++) {
		//			if (input_arr[pss_row][start_idx + 7 * i + k] != nums[j][k]) {
		//				flag = 0;
		//				break;
		//			}
		//		}
		//		if (flag) {  //암호가 j와 일치
		//			num_pss[i] = j;
		//			break;
		//		}
		//	}
		//}

		//암호검증
		int odd_sum = num_pss[0] + num_pss[2] + num_pss[4] + num_pss[6];
		int even_sum = num_pss[1] + num_pss[3] + num_pss[5];
		int result = (odd_sum * 3 + even_sum + num_pss[7]) % 10;

		printf("#%d %d\n", t, (result ? 0 : (odd_sum + even_sum + num_pss[7])));


	}
	return 0;
}
