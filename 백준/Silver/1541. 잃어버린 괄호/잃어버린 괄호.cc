#include <cstdio>

int main() {
    char s[51];
    int num[25];
    char oper[25];
    int temp = 0, indexnum = 0, indexoper = 0;
    int result, findminus = 0;

    scanf("%s", s);

    for (int i = 0; s[i]; i++) {
        if ((s[i] == '+') || (s[i] == '-')) {
            num[indexnum] = temp;
            oper[indexoper] = s[i];
            indexnum++;
            indexoper++;
            temp = 0;
        }

        else {
            temp *= 10;
            temp += s[i] - '0';
        }

        if (s[i + 1] == 0) {
            num[indexnum] = temp;
            indexnum++;
        }
    }

    result = num[0];
    for (int i = 0; i < indexoper; i++) {
        if (oper[i] == '+') {
            if (findminus == 0)
                result += num[i + 1];
            else {
                result -= num[i + 1];
            }
        }
        else {
            result -= num[i + 1];
            findminus = 1;
        }
    }

    printf("%d\n", result);

    return 0;
}