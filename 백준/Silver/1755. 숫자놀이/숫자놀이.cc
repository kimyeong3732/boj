#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string ns[10] = {"zero", "one", "two", "three", "four",
                    "five", "six", "seven", "eight", "nine"};

bool cmp(int a, int b) {
    int at=a/10, ar=a%10;
    int bt=b/10, br=b%10;
    
    string as="", bs="";
    
    if(at > 0) {
        as += ns[at];
        as += " ";
    }
    
    as += ns[ar];
    
    if(bt > 0) {
        bs += ns[bt];
        bs += " ";
    }
    
    bs += ns[br];
    
    return as.compare(bs) < 0;
}

int main() {
    int n, m;
    vector<int> v;
    
    cin >> n >> m;
    
    for(int i=n; i<=m; i++)
        v.push_back(i);
    
    sort(v.begin(), v.end(), cmp);
    
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
        
        if(i%10 == 9)
            cout << "\n";
    }
    
    return 0;
}