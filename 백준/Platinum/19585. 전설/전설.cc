#include <iostream>
#include <cstring>
#include <map>
#include <unordered_set>

using namespace std;

string s;
unordered_set<string> name;

struct trie {
    bool finish = false;
    map<char, trie*> next;
    
    void put(int index) {
        if(index == s.length()) {
            finish = true;
        }
        else {
            if(next.find(s[index]) == next.end()) {
                next[s[index]] = new trie();
            }
            
            next[s[index]]->put(index+1);
        }
    }
    
    bool find(int index) {
        if(index==s.length() || next.find(s[index])==next.end()) {
            return false;
        }
        
        if(next[s[index]]->finish && name.find(s.substr(index+1))!=name.end()) {
            return true;
        }
        
        return next[s[index]]->find(index+1);
    }
};

int main() {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    trie color;
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++) {
        cin >> s;
        
        color.put(0);
    }
    
    for(int i=0; i<m; i++) {
        cin >> s;
        
        name.insert(s);
    }
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        cin >> s;
        
        if(color.find(0)) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
    
    return 0;
}