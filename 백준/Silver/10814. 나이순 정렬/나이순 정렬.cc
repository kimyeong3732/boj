#include <cstdio>
#include <algorithm>
using namespace std;

struct person {
    int index;
    int age;
    char name[101];
};

bool cmp(person a, person b) {
    if (a.age == b.age)
        return a.index < b.index;
    return a.age < b.age;
}

int main() {
    int n;
    person p[100000];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%s", &p[i].age, p[i].name);
        p[i].index = i;
    }

    sort(p, p + n, cmp);

    for (int i = 0; i < n; i++)
        printf("%d %s\n", p[i].age, p[i].name);
    
    return 0;
}