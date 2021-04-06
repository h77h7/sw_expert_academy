//K번째 접미어
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

//카운팅 정렬도 사용가능
//suffix array를 카운팅 정렬로 정렬

//K번째 까지만 찾으면 되니까 selection 
void selection(int* a, int K, int arrLen) {
	for (int i = 0; i < K; i++) {
		int minIdx = i;
		for (int j = i + 1; j < arrLen; j++) {
			if (str_cmp(a[minIdx], a[j]) > 0) {
				minIdx = j;
			}
		}
		int tmp = a[i];
		a[i] = a[minIdx];
		a[minIdx] = tmp;
	}
}

void quicksort(int* a, int begin, int end) {
	if (begin < end) {
		int pivot = a[begin];
		int i = begin+1;
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
	//freopen("input_1256.txt", "r", stdin);

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

		if (K < arrLen) {
			//quicksort(A, 0, arrIdx - 1);
			selection(A, K, arrLen);

			cout << "#" << t << " ";
			for (int i = A[K - 1]; i < arrLen; i++) {
				cout << arr[i];
			}
			cout << endl;
		}
		else {
			cout << "none\n";
		}
		
	}
}
