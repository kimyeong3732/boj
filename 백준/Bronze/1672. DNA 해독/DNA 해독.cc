#include <iostream>

using namespace std;

int num[26];

int main() {
    char map[4][5] = {"ACAG", "CGTA", "ATCG", "GAGT"};
    num['G'-'A'] = 1;
    num['C'-'A'] = 2;
    num['T'-'A'] = 3;
    
    int n;
    string s;
    char c;
    
    cin >> n >> s;
    
    c = s[n-1];
    
    for(int i=n-2; i>=0; i--)
        c = map[num[s[i]-'A']][num[c-'A']];
    
    cout << c;
    
    return 0;
}