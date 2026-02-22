#include <iostream>
#include <vector>

using namespace std;

struct node {
    string c;
    int t;
};

int main() {
    int n;
    vector<node> v;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        string s;
        node input;
        
        cin >> s >> input.c >> input.t;
        
        v.push_back(input);
    }
    
    string result = "";
    
    int i = n-1;
    
    while(i >= 0) {
        node curr = v[i];
        
        if(curr.c[0]>='0' && curr.c[0]<='9') {
            int ct = curr.t - stoi(curr.c);
            
            while(i>=0 && v[i].t>=ct)
                i--;
        }
        
        else {
            result = curr.c + result;
            i--;
        }
    }
    
    cout << result;
    
    return 0;
}