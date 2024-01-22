#include <iostream>
using namespace std;

int arr1[5][5];
int arr2[5][5];

void mul(int n, int order) {
    if (order == 0) {
        int temp[5][5] = { 0 };

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    temp[j][k] += arr1[j][l] * arr1[l][k];

                    if (temp[j][k] >= 1000)
                        temp[j][k] %= 1000;
                }
            }
        }

        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                arr1[j][k] = temp[j][k];
    }

    else {
        int temp[5][5] = { 0 };

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    temp[j][k] += arr1[j][l] * arr2[l][k];

                    if (temp[j][k] >= 1000)
                        temp[j][k] %= 1000;
                }
            }
        }

        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                arr1[j][k] = temp[j][k];
    }
}

void mul_mul(int n, long long m) {
    if ((m == 0) || (m == 1))
        return;

    if ((m % 2) == 1) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                arr2[i][j] = arr1[i][j];

        mul_mul(n, m / 2);
        mul(n, 0);
        mul(n, 1);

        return;
    }

    mul_mul(n, m / 2);
    mul(n, 0);
}

int main() {
    int n;
    long long m;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;

            arr1[i][j] = temp;
        }
    }

    mul_mul(n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << arr1[i][j] % 1000 << ' ';
        cout << '\n';
    }

    return 0;
}