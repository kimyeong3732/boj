#include <iostream>
#include <vector>

using namespace std;

int t_l, p_l;
vector<int> v;
int pattern_idx[1000001];

void set_idx(string str) {
    int left = 0;
    pattern_idx[0] = 0;
    
    for(int right=1; right<p_l; right++) {
        while(left>0 && str[left]!=str[right]) {
            left = pattern_idx[left-1];
        }
        
        if(str[left] == str[right]) {
            left++;
            pattern_idx[right] = left;
        }
    }
}

void find(string a, string b) {
    int cursor = 0;
    
    for(int i=0; i<t_l; i++) {
        while(cursor>0 && a[i]!=b[cursor]) {
            cursor = pattern_idx[cursor-1];
        }
        
        if(a[i] == b[cursor]) {
            if(cursor == (p_l-1)) {
                v.push_back(i-cursor+1);
                cursor = pattern_idx[cursor];
            }
            else {
                cursor++;
            }
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    string t;
    string p;
    
    getline(cin, t);
    getline(cin, p);
    
    t_l = t.size();
    p_l = p.size();
    
    set_idx(p);
    
    find(t, p);
    
    cout << v.size() << "\n";
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    
    return 0;
}