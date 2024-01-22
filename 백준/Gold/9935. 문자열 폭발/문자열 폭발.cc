#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string a, b;
    int size = 0;
    char end;
    char result[1000001];

    cin >> a >> b;

    end = b[b.size() - 1];

    for (int i = 0; i < a.size(); i++) {
        if (a[i] == end) {
            int state = 0;
            int index = size - 1;

            for (int j = b.size() - 2; j >= 0; j--) {
                if ((index < 0) || (result[index] != b[j])) {
                    state = 1;
                    break;
                }

                index--;
            }

            if (state == 0)
                size = index + 1;
            
            else {
                result[size] = a[i];
                size++;
            }
        }

        else {
            result[size] = a[i];
            size++;
        }
    }

    if (size == 0)
        cout << "FRULA\n";
    
    else {
        for (int i = 0; i < size; i++)
            cout << result[i];

        cout << endl;
    }

    return 0;
}