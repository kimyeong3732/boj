#include <iostream>
#include <stack>
#include <set>

using namespace std;

int m, c, n;
int t;
int memory[100000];
char cmd[4096];
char input[4096];

void reset() {
	for (int i = 0; i < m; i++)
		memory[i] = 0;
}

void run() {
	int count = 0;
	int mi = 0;
	int ci = 0;
	int ii = 0;
	stack<int> s;
	set<int> ss;
	set<int> se;

	while (ci < c) {
		switch (cmd[ci]) {
		case '+':
			memory[mi] = (memory[mi] + 1) % 256;
			break;
		case '-':
			memory[mi] = (memory[mi] + 255) % 256;
			break;
		case '<':
			mi = (mi + m - 1) % m;
			break;
		case '>':
			mi = (mi + 1) % m;
			break;
		case '[':
			if (count >= 50000000)
				ss.insert(ci);
			else;
			if (memory[mi] == 0) {
				int cnt = 0;
				while (true) {
					ci++;

					if (cmd[ci] == '[') {
						if (count >= 50000000)
							ss.insert(ci);
						cnt++;
					}
					if (cmd[ci] == ']') {
						if (count >= 50000000)
							se.insert(ci);
						if (cnt == 0)
							break;
						cnt--;
					}
				}
			}
			else {
				s.push(ci);
			}
			break;
		case ']':
			if (count >= 50000000)
				se.insert(ci);
			else;
			if (memory[mi] != 0) {
				ci = s.top();
				if(count >= 50000000)
					ss.insert(ci);
			}
			else
				s.pop();
			break;
		case ',':
			if (ii < n)
				memory[mi] = input[ii++];
			else
				memory[mi] = 255;
			break;
		default:
			break;
		}
		count++;
		ci++;

		if (count == 100000000) {
			int lastend;
			s.push(0);
			/*
			cout << "ss : ";
			for (auto x : ss) {
				cout << x << " ";
			}
			cout << '\n';
			cout << "se : ";
			for (auto x : se) {
				cout << x << " ";
			}
			cout << '\n';
			cout << "ci : " << ci << '\n';
			*/
			while (!s.empty()) {
				if (ci == c) {
					cout << "Loops " << s.top() << ' ' << lastend << '\n';
					return;
				}

				if (cmd[ci] == ']') {
					//cout << "ci ] : " << ci << '\n';
					if (se.find(ci)==se.end() || s.size()==1) {
						cout << "Loops " << s.top() << ' ' << lastend << '\n';
						return;
					}
					s.pop();
					lastend = ci;
				}

				if (cmd[ci] == '[') {
					//cout << "ci [ : " << ci << '\n';
					if (ss.find(ci) == ss.end()) {
						cout << "Loops " << s.top() << ' ' << lastend << '\n';
						return;
					}
					s.push(ci);

				}

				ci++;
			}
		}
	}

	cout << "Terminates\n";
}

int main() {
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> m >> c >> n;
		cin >> cmd;
		cin >> input;

		reset();
		run();
	}

	return 0;
}