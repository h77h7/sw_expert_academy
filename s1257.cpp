//K번째 문자열
#include <iostream>
#include <stdio.h>

using namespace std;

const int MAX = 400;
int arrLen = 0;
char arr[MAX] = { 0, };

int str_cmp(int idx1, int idx2) {
	while (idx1 < arrLen && idx2 < arrLen && arr[idx1] == arr[idx2]) {
		idx1++;
		idx2++;
	}
	return (arr[idx1] - arr[idx2]);
}

int str_cmp_(int idx1, int idx2) {	//공통 접두어 길이 찾기
	int cnt = 0;
	while (idx1 < arrLen && idx2 < arrLen && arr[idx1] == arr[idx2]) {
		cnt++;
		idx1++;
		idx2++;
	}
	return cnt;
}

void quicksort(int* a, int begin, int end) {
	if (begin < end) {
		int pivot = a[begin];
		int i = begin;
		int j = end;
		while (i <= j) {
			while (i <= end && str_cmp(a[i], pivot) <= 0) i++;
			while (j >= begin && str_cmp(a[j], pivot) > 0) j--;

			if (i < j) {
				swap(a[i], a[j]);
			}
		}
		swap(a[begin], a[j]);

		quicksort(a, begin, j - 1);
		quicksort(a, j + 1, end);
	}
}

int main() {
	cin.tie(NULL);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int K;
		cin >> K;

		scanf(" %s", arr);
		int A[400] = { 0, };
		int arrIdx = 0;

		while (arr[arrIdx]) {
			A[arrIdx] = arrIdx;
			arrIdx++;
		}
		arrLen = arrIdx;

		quicksort(A, 0, arrIdx - 1);

		int LCP[MAX] = { 0, };
		for (int i = 1; i < arrLen; i++) {
			LCP[i] = str_cmp_(A[i - 1], A[i]);
		}

		cout << "#" << t << " ";
		int cnt = 0;
		int start_idx = -1;
		int end_idx = -1;
		for (int i = 0; i < arrLen; i++) {
			int curCnt = 0;
			curCnt += (arrLen - A[i] - LCP[i]);
			if (K > cnt && K <= cnt + curCnt) {
				start_idx = A[i];
				end_idx = A[i] + K - cnt + LCP[i];
				break;
			}
			cnt += curCnt;
		}
		if (start_idx < 0) {
			cout << "none\n";
		}
		else {
			for (int i = start_idx; i < end_idx; i++) {
				cout << arr[i];
			}
			cout << endl;
		}
	}
}
