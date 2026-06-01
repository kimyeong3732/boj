#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int mn = arr[0];
    for(int i=1; i<arr.size(); i++)
        mn = min(mn, arr[i]);
    
    if(arr.size() == 1)
        answer.push_back(-1);
    
    else {
        bool state = true;
        
        for(int i=0; i<arr.size(); i++) {
            if(state && arr[i]==mn) {
                state = false;
                continue;
            }
            
            answer.push_back(arr[i]);
        }
    }
    
    return answer;
}