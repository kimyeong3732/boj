#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int a, b, c;
vector<int> result;
bool visit[201][201][201];

void find() {
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(0, 0), c));
    
    while(!q.empty()) {
        int aa = q.front().first.first;
        int bb = q.front().first.second;
        int cc = q.front().second;
        q.pop();
        
        if(visit[aa][bb][cc])
            continue;
        
        visit[aa][bb][cc] = true;
        
        if(aa == 0)
            result.push_back(cc);
        
        if(aa+bb > a)
            q.push(make_pair(make_pair(a, aa+bb-a), cc));
        else
            q.push(make_pair(make_pair(aa+bb, 0), cc));
        
        if(aa+cc > a)
            q.push(make_pair(make_pair(a, bb), aa+cc-a));
        else
            q.push(make_pair(make_pair(aa+cc, bb), 0));
        
        
        if(aa+bb > b)
            q.push(make_pair(make_pair(aa+bb-b, b), cc));
        else
            q.push(make_pair(make_pair(0, aa+bb), cc));
        
        if(bb+cc > b)
            q.push(make_pair(make_pair(aa, b), bb+cc-b));
        else
            q.push(make_pair(make_pair(aa, bb+cc), 0));
        
        
        if(aa+cc > c)
            q.push(make_pair(make_pair(aa+cc-c, bb), c));
        else
            q.push(make_pair(make_pair(0, bb), aa+cc));
        
        if(bb+cc > c)
            q.push(make_pair(make_pair(aa, bb+cc-c), c));
        else
            q.push(make_pair(make_pair(aa, 0), bb+cc));
    }
}

int main() {
    cin >> a >> b >> c;
    
    find();
    
    sort(result.begin(), result.end());
    
    for(int i=0; i<result.size(); i++)
        cout << result[i] << " ";
    
    return 0;
}