#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n, avg = 0, mid, many, range;
    int currentMany = 1, highMany = 1, arrmany[2], index = 0;
    int arr[500001];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
        avg += arr[i];
    }
    arr[n] = 4001;

    float temp = (float)avg / n - avg / n;
    if ((temp <= -0.5) || (temp >= 0.5)) {
        if (temp < 0)
            avg = avg / n - 1;
        else
            avg = avg / n + 1;
    }
    else
        avg = avg / n;

    sort(arr, arr + n);
    mid = arr[n / 2];

    for (int i = 1; i <= n; i++) {
        if (arr[i] == arr[i - 1])
            currentMany++;
        else {
            if (highMany < currentMany) {
                highMany = currentMany;
                index = 1;
                arrmany[0] = arr[i - 1];
            }
            else if ((highMany == currentMany) && (index < 2)) {
                arrmany[index] = arr[i - 1];
                index++;
            }
            currentMany = 1;
        }
    }

    many = arrmany[index - 1];

    range = arr[n - 1] - arr[0];

    printf("%d\n%d\n%d\n%d\n", avg, mid, many, range);
    
    return 0;
}