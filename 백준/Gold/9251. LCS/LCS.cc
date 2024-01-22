#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int arr[1000][1000];
    string a, b;

    cin >> a >> b;

    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            if (a[j] == b[i]) {
                if ((i == 0) || (j == 0))
                    arr[i][j] = 1;
                else
                    arr[i][j] = arr[i - 1][j - 1] + 1;
            }
            else {
                if ((i == 0) && (j == 0))
                    arr[i][j] = 0;
                else if (i == 0)
                    arr[i][j] = arr[i][j - 1];
                else if (j == 0)
                    arr[i][j] = arr[i - 1][j];
                else
                    arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
            }
        }
    }

    cout << arr[b.size() - 1][a.size() - 1] << endl;

    return 0;
}