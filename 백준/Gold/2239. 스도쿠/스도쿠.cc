#include <iostream>

using namespace std;

int map[9][9];
bool state = false;

bool check(int x, int y, int num) {
	for (int i = 0; i < 9; i++) {
		if (map[i][x] == num || map[y][i] == num) {
			return false;
		}
	}

	int nx = x / 3 * 3;
	int ny = y / 3 * 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (map[ny + i][nx + j] == num) {
				return false;
			}
		}
	}

	return true;
}

void find() {
	int x = -1;
	int y = -1;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (map[i][j] == 0) {
				x = j;
				y = i;
				break;
			}
		}

		if (x >= 0 && y >= 0) {
			break;
		}
	}

	if (x < 0 && y < 0) {
		state = true;

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[i][j];
			}
			cout << "\n";
		}

		return;
	}

	for (int i = 1; i <= 9; i++) {
		if (check(x, y, i)) {
			map[y][x] = i;
			find();
			map[y][x] = 0;
		}
		if (state) {
			return;
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		char temp[10];
		cin >> temp;

		for (int j = 0; j < 9; j++) {
			map[i][j] = temp[j] - '0';
		}
	}

	find();

	return 0;
}