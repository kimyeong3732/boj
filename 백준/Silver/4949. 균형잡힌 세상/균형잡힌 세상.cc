#include <iostream>
#include <string>
using namespace std;

int main() {
    string arr;
    char arr2[101] = { 0 };
    int index = 0;

    getline(cin, arr);
    while (arr[0] != '.') {
        int state = 1;
        for (int i = 0; arr[i]; i++) {
            if (arr[i] == '(') {
                arr2[index] = '(';
                index++;
            }
            if (arr[i] == '[') {
                arr2[index] = '[';
                index++;
            }
            if (arr[i] == ')') {
                if ((arr2[index - 1] == '(') && (index > 0)) {
                    arr2[index] = 0;
                    arr2[index - 1] = 0;
                    index--;
                }
                else
                    state = 0;
            }
            if (arr[i] == ']') {
                if ((arr2[index - 1] == '[') && (index > 0)) {
                    arr2[index] = 0;
                    arr2[index - 1] = 0;
                    index--;
                }
                else
                    state = 0;
            }
            if (arr[i] == '.') {
                if ((index == 0) && (state == 1))
                    cout << "yes\n";
                else
                    cout << "no\n";
            }
        }
        for (index; index >= 0; index--)
            arr2[index] = 0;
        index++;
        getline(cin, arr);
    }
    
    return 0;
}