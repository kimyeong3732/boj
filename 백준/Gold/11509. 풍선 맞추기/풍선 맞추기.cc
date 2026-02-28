#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    int nm = 0;
    vector<int> v;
    vector<int> arrow;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int num;
        
        cin >> num;
        
        v.push_back(num);
        nm = max(nm, num);
    }
    
    for(int i=0; i<=nm; i++)
        arrow.push_back(0);
    
    int result = 0;
    
    for(int i=0; i<n; i++) {
        if(arrow[v[i]] > 0)
            arrow[v[i]]--;
        
        else
            result++;
        
        arrow[v[i]-1]++;
    }
    
    cout << result;
    
    return 0;
}