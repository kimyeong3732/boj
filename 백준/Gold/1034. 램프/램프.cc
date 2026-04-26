#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, m;
    map<string, pair<int, int>> mm;
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++) {
        string s;
        
        cin >> s;
        
        int c = 0;
        
        for(int j=0; j<s.size(); j++)
            if(s[j] == '0')
                c++;
        
        if(mm.find(s) == mm.end())
            mm.insert({s, make_pair(c, 1)});
        
        else
            mm[s].second++;
    }
    
    int d;
    int result = 0;
    
    cin >> d;
    
    for(auto temp : mm) {
        int check = temp.second.first;
        
        if(check<=d && (check%2)==(d%2))
            result = max(result, temp.second.second);
    }
    
    cout << result;
    
    return 0;
}