#include <cstdio>
using namespace std;

int inorder[100000];
int postorder[100000];

void find(int a, int b, int order) {
    if (a > b)
        return;

    if (a == b) {
        printf("%d ", postorder[a] + 1);

        return;
    }

    printf("%d ", postorder[b] + 1);

    int middle = inorder[postorder[b]];

    middle -= order;

    find(a, middle - 1, order);
    find(middle, b - 1, order + 1);
}

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int temp;

        scanf("%d", &temp);

        inorder[temp - 1] = i;
    }

    for (int i = 0; i < n; i++) {
        int temp;

        scanf("%d", &temp);

        postorder[i] = temp - 1;
    }

    find(0, n - 1, 0);
    printf("\n");

    return 0;
}