#include <iostream>
#include <cstring>
using namespace std;

string arr[101][101];

string add(string a, string b) {
    string result = "";
    int size = a.size();
    int sum = 0;

    if (b.size() > size)
        size = b.size();

    for (int i = 0; i < size; i++) {
        if (a.size() > i)
            sum += a[i] - '0';
        if (b.size() > i)
            sum += b[i] - '0';

        result += sum % 10 + '0';
        sum /= 10;
    }

    if (sum > 0)
        result += sum + '0';

    return result;
}

string combination(int n, int m) {
    if (arr[n][m] != "")
        return arr[n][m];

    if ((m == 0) || (n == m))
        return "1";

    arr[n][m] = add(combination(n - 1, m - 1), combination(n - 1, m));

    return arr[n][m];
}

int main() {
    int n, m;

    cin >> n >> m;

    combination(n, m);

    for (int i = arr[n][m].size() - 1; i >= 0; i--)
        cout << arr[n][m][i];
    cout << '\n';

    return 0;
}