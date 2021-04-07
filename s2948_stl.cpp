//문자열 교집합
//STL (unordered_set) 사용

#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<string> s;
int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n, m;
		scanf("%d %d", &n, &m);

		s.clear();
		for (int i = 0; i < n; i++) {
			char temp[51] = { 0, };
			scanf(" %s", temp);
			s.emplace(string(temp));
		}
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			char temp[51] = { 0, };
			scanf(" %s", temp);
			s.find(string(temp)) == s.end() ? 0 : cnt++;
		}

		cout << "#" << t << " " << cnt << endl;
	}
}
