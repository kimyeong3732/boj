#include <iostream>
#include <queue>

using namespace std;

string d;
bool nprime[10000];
bool visit[10000];

void find(string s) {
    queue<pair<string, int>> q;
    
    visit[stoi(s)] = true;
    q.push(make_pair(s, 0));
    
    while(!q.empty()) {
        string node = q.front().first;
        int c = q.front().second;
        q.pop();
        
        if(node == d) {
            cout << c << "\n";
            return;
        }
        
        for(int i=0; i<4; i++) {
            for(int j=0; j<10; j++) {
                string temp = node;
                
                temp[i] = j + '0';
                
                if(nprime[stoi(temp)] || visit[stoi(temp)] || stoi(temp)<1000)
                    continue;
                
                visit[stoi(temp)] = true;
                q.push(make_pair(temp, c+1));
            }
        }
    }
    
    
    cout << "Impossible\n";
}

int main() {
    for(int i=2; i<10000; i++)
        if(!nprime[i])
            for(int j=i*2; j<10000; j+=i)
                nprime[j] = true;
    
    int t;
    
    cin >> t;
    
    for(int i=0; i<t; i++) {
        string s;
        
        cin >> s >> d;
        
        for(int j=1000; j<10000; j++)
            visit[j] = false;
        
        find(s);
    }
    
    return 0;
}