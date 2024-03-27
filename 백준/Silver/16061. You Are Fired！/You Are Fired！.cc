#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

struct emp {
    string name;
    int cost;
};

struct cmp {
  bool operator()(emp a, emp b) {
    return a.cost < b.cost;
  }
};

int main()
{
    int n, d, k;
    priority_queue<emp, vector<emp>, cmp> q;
    
    cin >> n >> d >> k;
    
    for(int i=0; i<n; i++) {
        string s;
        int c;
        
        cin >> s >> c;
        
        q.push({s, c});
    }
    
    int i = 0;
    int nums = 0;
    string result = "";
    
    for(; i<k; i++) {
        if(nums >= d) {
            break;
        }
        
        emp e = q.top();
        q.pop();
        
        nums += e.cost;
        
        result += e.name + ", YOU ARE FIRED!\n";
    }
    
    result = to_string(i) + '\n' + result;
    
    if(nums < d) {
        result = "impossible\n";
    }
    
    cout << result;

    return 0;
}