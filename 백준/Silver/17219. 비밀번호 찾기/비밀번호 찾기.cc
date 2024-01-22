#include <iostream>
#include <cstring>
#include <map>
using namespace std;

int main() {
    int n, m;
    map<string, string> map;

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string site, password;
        cin >> site >> password;

        map.insert({ site, password });
    }

    for (int i = 0; i < m; i++) {
        string find;
        cin >> find;

        cout << map[find] << '\n';
    }

    return 0;
}