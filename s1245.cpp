//#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int tc = 0;
	scanf(" %d", &tc);
	for (int c = 1; c <= tc; c++) {
		int N = 0;
		scanf(" %d", &N);

		double dis[10] = { 0, };
		double weight[10] = { 0, };

		for (int i = 0; i < N; i++)
			scanf(" %lf", &dis[i]);

		for (int i = 0; i < N; i++)
			scanf(" %lf", &weight[i]);

		printf("#%d ", c);

		for (int i = 0; i < N - 1; i++) {
			double start = dis[i];
			double end = dis[i + 1];
			double mid = 0;

			while ((end - start) >= 0.000000000001) {

				mid = (start + end) / 2;

				double F1 = 0, F2 = 0;

				for (int j = 0; j <= i; j++) {
					F1 += weight[j] / ((mid - dis[j])*(mid - dis[j]));
				}
				for (int j = i + 1; j < N; j++) {
					F2 += weight[j] / ((dis[j] - mid)*(dis[j] - mid));
				}

				if (F1 > F2)
					start = mid;
				else
					end = mid;
			}
			printf("%.10lf ", mid);
		}
		printf("\n");


	}

	return 0;
}
