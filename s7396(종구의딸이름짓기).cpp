/******************
bfs사용
visit배열 사용 안하면 time over됨
더 작은 알파벳 나왔을 때 queue에서 이미 넣어둔 다음 애들 지우기 위해서 deque사용
******************/
#include <iostream>
#include <deque>

using namespace std;


char input[2000][2000] = { 0 };
bool visit[2000][2000] = { false };
char res[4000] = { 0 };
deque<int> q;

int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {
		int n, m;
		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf(" %c", &input[i][j]);
			}
		}

		for (int i = 0; i < 4000; i++) {
			res[i] = 'z';
		}

		int len = n + m - 1;
		q.push_front(0);
		q.push_front(0);
		q.push_front(0);
		while (!q.empty()) {
			int x = q.back();	q.pop_back();
			int y = q.back();	q.pop_back();
			int d = q.back();	q.pop_back();

			if (!visit[y][x]) {
				visit[y][x] = true;
				if (res[d] > input[y][x]) {
					while (!q.empty()) {
						int nd = q.front();   //queue에 이미 들어있는 애가 다음 자리에 관한 것일 때 없애버림
						if (nd <= d) break;
						q.pop_front();
						q.pop_front();
						q.pop_front();
					}
					res[d] = input[y][x];
					if (x + 1 < m) {
						q.push_front(x + 1);
						q.push_front(y);
						q.push_front(d + 1);
					}
					if (y + 1 < n) {
						q.push_front(x);
						q.push_front(y + 1);
						q.push_front(d + 1);
					}

				}
				else if (res[d] == input[y][x]) {
					if (x + 1 < m) {
						q.push_front(x + 1);
						q.push_front(y);
						q.push_front(d + 1);
					}
					if (y + 1 < n) {
						q.push_front(x);
						q.push_front(y + 1);
						q.push_front(d + 1);
					}
				}
			}
		}
		printf("#%d ", t);
		for (int i = 0; i < len; i++) {
			printf("%c", res[i]);
		}
		printf("\n");

		for (int i = 0; i < 2000; i++) {
			for (int j = 0; j < 2000; j++) {
				visit[i][j] = false;
			}
		}
	}
	return 0;
}
