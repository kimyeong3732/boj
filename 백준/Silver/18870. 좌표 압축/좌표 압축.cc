#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    vector<int> a, b;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);

        a.push_back(temp);
        b.push_back(temp);
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    for (int i = 0; i < n; i++)
        printf("%d ", lower_bound(a.begin(), a.end(), b[i]) - a.begin());

    printf("\n");

    return 0;
}