#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <map>

using namespace std;

int main() {
	map<char, char> m;
	m['('] = ')';
	m['['] = ']';
	m['{'] = '}';
	m['<'] = '>';

	//freopen("input.txt", "r", stdin);
	for (int i = 0; i < 10; i++) {
		stack<char, vector<char>> st;
		int answer = 0;

		int N = 0;
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			char c = 0;
			scanf(" %c", &c);
			if (st.empty()) st.push(c);
			else {
				if (m[st.top()] == c) st.pop();
				else st.push(c);
			}
		}

		if (st.empty()) answer = 1;
		printf("#%d %d\n", i + 1, answer);

	}
	return 0;
}
