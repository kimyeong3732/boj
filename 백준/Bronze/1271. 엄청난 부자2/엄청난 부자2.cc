#include <cstdio>
#include <cstring>

bool possible(char* a, char* b, int index) {
    for (int i = 0; i < index; i++)
        if(a[i] > '0')
            return true;
    
    for (int i = 0; i < strlen(b); i++) {
        if (a[index + i] > b[i])
            return true;
        if (a[index + i] < b[i])
            return false;
    }
    return true;
}

int main() {
    char a[1002], b[1002];
    char result[1002];
    int al, bl;
    int find = 0;

    scanf("%s%s", a, b);
    al = strlen(a);
    bl = strlen(b);

    for (int i = 0; i <= (al - bl); i++) {
        result[i] = '0';

        while (possible(a, b, i)) {
            for (int j = bl - 1; j >= 0; j--) {
                a[i + j] -= b[j];
                a[i + j] += '0';
                if (a[i + j] < '0') {
                    a[i + j] += 10;
                    a[i + j - 1]--;
                }
            }
            result[i]++;
        }
    }
    result[al - bl + 1] = 0;

    if (bl > al) {
        result[0] = '0';
        result[1] = 0;
        printf("%s", result);
    }
    
    for (int i = 0; i <= (al - bl); i++) {
        if (result[i] == '0') {
            if (find == 0) {
                if (result[i + 1] == 0)
                    printf("%c", result[i]);
                else
                    continue;
            }
            else
                printf("%c", result[i]);
        }
        else {
            find = 1;
            printf("%c", result[i]);
        }
    }
    printf("\n");

    find = 0;
    for (int i = 0; i < al; i++) {
        if (a[i] == '0') {
            if (find == 0) {
                if (a[i + 1] == 0)
                    printf("%c", a[i]);
                else
                    continue;
            }
            else
                printf("%c", a[i]);
        }
        else {
            find = 1;
            printf("%c", a[i]);
        }
    }
    printf("\n");

    return 0;
}