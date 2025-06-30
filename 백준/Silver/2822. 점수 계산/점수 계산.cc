#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

bool cmp1(pair<int, int> a, pair<int, int> b) {
    if(a.first > b.first)
        return true;
    
    return false;
}

bool cmp2(pair<int, int> a, pair<int, int> b) {
    if(a.second < b.second)
        return true;
    
    return false;
}

int main() {
    pair<int, int> scores[8];
    
    for(int i=0; i<8; i++) {
        int score;
        
        cin >> score;
        
        scores[i] = make_pair(score, i+1);
    }
    
    sort(scores, scores+8, cmp1);
    sort(scores, scores+5, cmp2);
    
    int result = 0;
    
    for(int i=0; i<5; i++)
        result += scores[i].first;
    
    cout << result << "\n";
    
    for(int i=0; i<5; i++)
        cout << scores[i].second << " ";
    
    return 0;
}