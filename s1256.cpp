#include <iostream>
#include <stdio.h>

using namespace std;

#define SWAP(x,y) {x = x^y; y = y^x; x = x^y;}
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

void quicksort(int* a, int begin, int end) {
	if (begin < end) {
		int pivot = a[begin];
		int i = begin;
		int j = end;
		while (i <= j) {
			while (i <= end && str_cmp(a[i],pivot) <= 0) i++;
			while (j >= begin && str_cmp(a[j],pivot) > 0) j--;

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
	freopen("input_1256.txt", "r", stdin);

	cin.tie(NULL);
	//ios::sync_with_stdio(false);

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

		quicksort(A, 0, arrIdx-1);

		cout << "#" << t << " ";
		for (int i = A[K-1]; i < arrLen; i++) {
			cout << arr[i];
		}
		cout << endl;
	}
}
