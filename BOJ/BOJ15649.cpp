//boj 15649

#include <iostream>
#include <vector>

using namespace std;

void permutate(int n, int m, int num, int depth, vector<int> v) {
	if (depth == m) { 
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		int flag = 0;
		for (int j = 0; j < v.size(); j++) {
			if (v[j] == i) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			v.push_back(i);
			permutate(n, m, i, depth + 1, v);
			v.pop_back();
		}
	}
}

int main(void) {
	int n, m;
	vector<int> v;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		v.push_back(i);
		permutate(n, m, i, 1, v);
		v.pop_back();
	}
}