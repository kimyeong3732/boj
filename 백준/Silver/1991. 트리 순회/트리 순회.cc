#include <cstdio>
#include <vector>
using namespace std;

struct node {
    int left;
    int right;
};

vector<node> v;

void preorder(int node) {
    if (node < 0)
        return;

    printf("%c", node + 'A');
    preorder(v[node].left);
    preorder(v[node].right);
}

void inorder(int node) {
    if (node < 0)
        return;

    inorder(v[node].left);
    printf("%c", node + 'A');
    inorder(v[node].right);
}

void postorder(int node) {
    if (node < 0)
        return;

    postorder(v[node].left);
    postorder(v[node].right);
    printf("%c", node + 'A');
}

int main() {
    int n;
    v.resize(26);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char a[2], b[2], c[2];

        scanf("%s%s%s", a, b, c);

        v[a[0] - 'A'].left = b[0] - 'A';
        v[a[0] - 'A'].right = c[0] - 'A';
    }

    preorder(0);
    printf("\n");
    inorder(0);
    printf("\n");
    postorder(0);
    printf("\n");

    return 0;
}