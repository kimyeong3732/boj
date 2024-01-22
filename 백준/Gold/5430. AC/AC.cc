#include <cstdio>

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int m;
        int left, right, R = 0, error = 0;
        int arr[100000];
        char cmd[100001];
        char c[400001];
        int temp = 0, index = 0;
        scanf("%s%d", cmd, &m);

        scanf("%s", c);

        for (int j = 0; c[j]; j++) {
            if ((c[j] >= '0') && (c[j] <= '9')) {
                temp *= 10;
                temp += c[j] - '0';
            }
            else if ((c[j] == ',') || (c[j] == ']')) {
                arr[index] = temp;
                temp = 0;
                index++;
            }
        }

        left = 0;
        right = m - 1;

        for (int j = 0; cmd[j]; j++) {
            if (cmd[j] == 'R')
                R = (R + 1) % 2;
            else {
                if (left <= right) {
                    if (R == 0)
                        left++;
                    else
                        right--;
                }
                else {
                    printf("error\n");
                    error = 1;
                    break;
                }
            }
        }
        
        if (error == 1)
            continue;

        printf("[");
        if(R == 0)
            for (int j = left; j <= right; j++) {
                printf("%d", arr[j]);
                if (j < right)
                    printf(",");
            }
        else
            for (int j = right; j >= left; j--) {
                printf("%d", arr[j]);
                if (j > left)
                    printf(",");
            }
        printf("]\n");
    }

    return 0;
}