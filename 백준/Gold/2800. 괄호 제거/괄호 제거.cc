#include <iostream>
#include <stack>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

string s;
int index;
int v[200];
bool check[10];
set<string> sst;

void print(int c) {
    if(c == index) {
        string result = "";
        
        for(int i=0; i<s.size(); i++) {
            if(v[i]>=0 && check[v[i]])
                continue;
            
            result += s[i];
        }
        
        if(sst.find(result) == sst.end())
            sst.insert(result);
        
        return;
    }
    
    check[c] = false;
    print(c+1);
    
    check[c] = true;
    print(c+1);
}

int main() {
    stack<int> st;
    
    cin >> s;
    
    for(int i=0; i<s.size(); i++)
        v[i] = -1;
    
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '(') {
            st.push(index);
            v[i] = index++;
        }
        if(s[i] == ')') {
            int temp = st.top();
            st.pop();
            
            v[i] = temp;
        }
    }
    
    sst.insert(s);
    
    print(0);
    
    sst.erase(sst.find(s));
    
    for_each(sst.begin(), sst.end(), [](string n) {
        cout << n << "\n";
    });
    
    return 0;
}