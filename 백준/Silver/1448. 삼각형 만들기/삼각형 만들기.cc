#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n;
    
    cin >> n;
    
    vector<int> v;
    
    for(int i=0; i<n; i++) {
        int temp;
        
        cin >> temp;
        
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end(), cmp);
    int result = -1;
    
    for(int i=0; i<n-2; i++) {
        int max_num = v[i];
        result = 0;
        
        for(int j=1; j<3; j++) {
            result += v[i+j];
        }
        
        if(result <= max_num) {
            result = -1;
        }
        else {
            result += max_num;
            break;
        }
    }
    
    cout << result;
    
    return 0;
}