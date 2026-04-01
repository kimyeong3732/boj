#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m, n, ll;
    vector<int> hunter;
    vector<pair<int, int>> animal;
    
    cin >> m >> n >> ll;
    
    for(int i=0; i<m; i++) {
        int temp;
        
        cin >> temp;
        
        hunter.push_back(temp);
    }
    
    sort(hunter.begin(), hunter.end());
    
    for(int i=0; i<n; i++) {
        int x, y;
        
        cin >> x >> y;
        
        animal.push_back(make_pair(x, y));
    }
    
    int result = 0;
    
    for(int i=0; i<n; i++) {
        int l=0, r=m-1;
        
        while(l <= r) {
            int mid = (l + r) / 2;
            bool state = false;
            
            int dist = animal[i].first - hunter[mid];
            
            if(dist < 0) {
                state = true;
                dist *= -1;
            }
            
            dist += animal[i].second;
            
            if(dist <= ll) {
                result++;
                break;
            }
            
            if(state)
                r = mid - 1;
            
            else
                l = mid + 1;
        }
    }
    
    cout << result;
    
    return 0;
}