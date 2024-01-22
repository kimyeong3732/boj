#include <iostream>
using namespace std;

int main() {
    int n, index = 0, index2 = 0, count = 0;
    int arr[100000], arr2[100000];
    char ans[200000];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++) {
        arr2[index] = i + 1;
        ans[count] = '+';
        count++;
        while ((index>=0) && (arr2[index]==arr[index2])) {
            ans[count] = '-';
            count++;
            index--;
            index2++;
        }
        index++;
    }

    if (index2 == n)
        for (int i = 0; i < count; i++)
            cout << ans[i] << '\n';

    else
        cout << "NO\n";
    
    return 0;
}