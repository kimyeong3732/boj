#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct opstore {
    int num;
    string op;
};

int main() {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        int num[10000] = { 0 };
        queue<opstore> q;
        opstore temp;

        cin >> a >> b;

        num[a] = 1;
        temp.num = a;
        temp.op = "";

        q.push(temp);

        while (!q.empty()) {
            temp.num = q.front().num * 2 % 10000;
            if (num[temp.num] == 0) {
                if (temp.num == b) {
                    cout << q.front().op << 'D' << endl;
                    break;
                }
                temp.op = q.front().op + "D";
                num[temp.num] = 1;
                q.push(temp);
            }

            temp.num = q.front().num - 1;
            if (temp.num < 0)
                temp.num = 9999;
            if (num[temp.num] == 0) {
                if (temp.num == b) {
                    cout << q.front().op << 'S' << endl;
                    break;
                }
                temp.op = q.front().op + "S";
                num[temp.num] = 1;
                q.push(temp);
            }

            temp.num = q.front().num % 1000 * 10 + q.front().num / 1000;
            if (num[temp.num] == 0) {
                if (temp.num == b) {
                    cout << q.front().op << 'L' << endl;
                    break;
                }
                temp.op = q.front().op + "L";
                num[temp.num] = 1;
                q.push(temp);
            }

            temp.num = q.front().num % 10 * 1000 + q.front().num / 10;
            if (num[temp.num] == 0) {
                if (temp.num == b) {
                    cout << q.front().op << 'R' << endl;
                    break;
                }
                temp.op = q.front().op + "R";
                num[temp.num] = 1;
                q.push(temp);
            }
            q.pop();
        }
    }

    return 0;
}