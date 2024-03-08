#include <iostream>
#include <algorithm>

using namespace std;

struct app {
	int m, cost;

	bool operator< (app other) {
		return cost < other.cost;
	}
};

int main() {
	int n, m;
	int temp[100];
	app apps[100];

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> temp[i];
	}

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		apps[i] = { temp[i], num };
	}

	sort(apps, apps + n);

	int dp[10001][2];
	int state = 0;

	for (int i = 0; i <= n * 100; i++) {
		dp[i][1] = 0;
	}

	for (int i = 0; i < n; i++) {
		int other = (state + 1) % 2;

		for (int j = 0; j <= n * 100; j++) {
			if (j<apps[i].cost || dp[j][other]>=dp[j - apps[i].cost][other]+apps[i].m) {
				dp[j][state] = dp[j][other];
			}
			else {
				dp[j][state] = dp[j - apps[i].cost][other] + apps[i].m;
			}

			if (dp[j][state] >= m) {
				break;
			}
		}
		state = (state + 1) % 2;
	}
	state = (state + 1) % 2;

	for (int i = 0; i <= n * 100; i++) {
		if (dp[i][state] >= m) {
			cout << i << "\n";
			break;
		}
	}

	return 0;
}