#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> alpha[26];
int nums[26];

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int n, m;
    
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        string temp;
        cin >> temp;
        alpha[temp[0]-'a'].push_back(temp);
    }
    
    for(int i=0; i<26; i++)
        sort(alpha[i].begin(), alpha[i].end());
        
    for(int i=0; i<m; i++) {
        string c;
        cin >> c;
        int index = c[0] - 'a';
        cout << alpha[index][nums[index]++%alpha[index].size()] << '\n';
    }
    
    return 0;
}