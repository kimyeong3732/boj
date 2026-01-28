#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long arr[3001];
    
    arr[0] = 0;
    
    cin >> n;
    
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        
        arr[i] += arr[i-1];
    }
    
    int mk = n / 2;
    long long result = -1;
    int rk = 1;
    
    for(int k=1; k<=n/2; k++) {
        vector<pair<long long, int>> v;
        
        for(int i=k; i<=n; i++) {
            long long temp = arr[i] - arr[i-k];
            
            v.push_back(make_pair(temp, i));
        }
        
        sort(v.begin(), v.end());
        
        for(int i=0; i<v.size()-1; i++) {
            for(int d=1; i+d<v.size(); d++) {
                if(v[i+d].second-v[i].second>=k || v[i].second-v[i+d].second>=k) {
                    long long diff = v[i+d].first - v[i].first;
                    
                    if(result<0 || result>=diff) {
                        result = diff;
                        rk = k;
                    }
                    
                    break;
                }
            }
        }
    }
    
    cout << rk << "\n";
    cout << result;
    
    return 0;
}