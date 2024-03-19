#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}

	return gcd(b, a%b);
}

int main() {
	int n;
	priority_queue<int> input;
	priority_queue<int> gcds;
	vector<int> result;

	cin >> n;

	for (int i = 0; i < n*n; i++) {
		int temp;

		cin >> temp;
		input.push(temp);
	}

	while (result.size() < n) {
		while (!gcds.empty()) {
			if (input.top() != gcds.top()) {
				break;
			}

			input.pop();
			gcds.pop();
		}

		for (int i = 0; i < result.size(); i++) {
			gcds.push(gcd(result[i], input.top()));
			gcds.push(gcd(result[i], input.top()));
		}

		result.push_back(input.top());
		input.pop();
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}

	cout << '\n';

	return 0;
}