#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);

	for (int tc = 1; tc < 11; tc++) {
		int dump = 0;
		int box[100] = { 0, };
		int result = 0;
		cin >> dump;
		for (int i = 0; i < 100; i++) {
			cin >> box[i];
		}
		
		
		for (int i = dump; i >= 0; i--) {
			sort(box, box + 100);
			result = box[99] - box[0];
			if (result <= 1) break;
			box[0]++;
			box[99]--;
		}
		cout << '#' << tc << " " << result << endl;
	}

	return 0;
}
