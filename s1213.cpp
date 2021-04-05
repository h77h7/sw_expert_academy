#include <iostream>
#include <stdio.h>

using namespace std;
int strLen(char* arr) {
	int idx = 0;
	while (*(arr + idx)) idx++;
	return idx;
}

int main() {
	freopen("test_input.txt", "r", stdin);
	
	for (int t = 1; t < 11; t++) {
		int tc;
		cin >> tc;

		char p[11] = { 0, };
		char a[1001] = { 0, };
		int pSkip[128] = { 0, };
		int cnt = 0;

		scanf(" %s", p);
		scanf(" %s", a);

		int pLen = strLen(p);
		int aLen = strLen(a);
		for (int i = 0; i < 128; i++) {
			pSkip[i] = pLen;
		}

		for (int i = 0; i < pLen; i++) {
			pSkip[p[i]] = pLen - 1 - i;
		}

		pSkip[p[pLen - 1]] = pLen;

		int i = 0;
		while (i <= (aLen - pLen)) {
			int j = pLen - 1;
			int k = i + pLen - 1;
			while (j >= 0 && p[j] == a[k]) {
				j--; k--;
			}
			if (j < 0) {
				cnt++;
			}
			if (a[i + pLen - 1] < 0) i += pLen;
			else i += pSkip[a[i + pLen - 1]];
		}
		cout << "#" << t << " " << cnt << endl;
	}
}
