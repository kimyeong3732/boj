#include <iostream>
using namespace std;

int arr[10000];

void postorder(int start, int end) {
    if (start == end)
        return;

    if ((end - start) == 1) {
        cout << arr[start] << endl;
        return;
    }

    int i;

    for (i = start; i < end; i++)
        if (arr[start] < arr[i])
            break;

    postorder(start + 1, i);
    postorder(i, end);
    cout << arr[start] << endl;
}

int main() {
    int temp;
    int index = 0;

    while (cin >> temp) {
        arr[index] = temp;
        index++;
    }

    postorder(0, index);

    return 0;
}