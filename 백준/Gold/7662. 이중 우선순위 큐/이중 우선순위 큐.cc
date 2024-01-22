#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {
    int n, k;

    cin >> n;

    for (int i = 0; i < n; i++) {
        priority_queue<int> max;
        priority_queue<int, vector<int>, greater<int>> min;
        map<int, int> m;

        cin >> k;

        for (int j = 0; j < k; j++) {
            char c;
            int num;
            cin >> c >> num;

            if (c == 'I') {
                max.push(num);
                min.push(num);
                if (m.count(num) == 0)
                    m[num] = 1;
                else
                    m[num]++;
            }
            else {
                if (num == 1) {
                    while ((!max.empty()) && (m[max.top()] == 0))
                        max.pop();

                    if (!max.empty()) {
                        m[max.top()]--;
                        max.pop();
                    }
                }

                if (num == -1) {
                    while ((!min.empty()) && (m[min.top()] == 0))
                        min.pop();

                    if (!min.empty()) {
                        m[min.top()]--;
                        min.pop();
                    }
                }
            }
        }

        while ((!max.empty()) && (m[max.top()] == 0))
            max.pop();

        while ((!min.empty()) && (m[min.top()] == 0))
            min.pop();

        if (max.empty())
            cout << "EMPTY\n";
        else {
            cout << max.top() << ' ' << min.top() << endl;
        }
    }

    return 0;
}