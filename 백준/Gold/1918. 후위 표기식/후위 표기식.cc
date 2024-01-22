#include <cstdio>
#include <stack>
using namespace std;

int main() {
    char f[101];
    stack<char> s;

    scanf("%s", f);

    for (int i = 0; f[i]; i++) {
        if ((f[i] >= 'A') && (f[i] <= 'Z'))
            printf("%c", f[i]);

        else {
            if (f[i] == '(')
                s.push(f[i]);

            else if ((f[i] == '*') || (f[i] == '/')) {
                while (!s.empty() && ((s.top() == '*') || (s.top() == '/'))) {
                    printf("%c", s.top());
                    s.pop();
                }

                s.push(f[i]);
            }

            else if ((f[i] == '+') || (f[i] == '-')) {
                while (!s.empty() && (s.top() != '(')) {
                    printf("%c", s.top());
                    s.pop();
                }

                s.push(f[i]);
            }

            else {
                while (!s.empty() && (s.top() != '(')) {
                    printf("%c", s.top());
                    s.pop();
                }

                s.pop();
            }
        }
    }

    while (!s.empty()) {
        printf("%c", s.top());
        s.pop();
    }
    printf("\n");

    return 0;
}