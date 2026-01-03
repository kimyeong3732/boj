#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> p;
vector<long long> m;

int main() {
    int n;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        long long num;
        
        cin >> num;
        
        if(num <= 0)
            m.push_back(num);
        
        else
            p.push_back(num);
    }
    
    sort(p.begin(), p.end(), greater<long long>());
    sort(m.begin(), m.end());
    
    long long result = 0;
    
    for(int i=0; i<p.size(); i++) {
        if(i<p.size()-1 && p[i]+p[i+1] < p[i]*p[i+1]) {
            result += p[i] * p[i+1];
            i++;
        }
        
        else {
            result += p[i];
        }
    }
    
    for(int i=0; i<m.size(); i++) {
        if(i<m.size()-1 && m[i]+m[i+1] < m[i]*m[i+1]) {
            result += m[i] * m[i+1];
            i++;
        }
        
        else {
            result += m[i];
        }
    }
    
    cout << result;
    
    return 0;
}