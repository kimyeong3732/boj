#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    vector<int> alpha;
    
    for(int i=0; i<26; i++)
        alpha.push_back(-1);
    
    for(int i=0; i<keymap.size(); i++) {
        for(int j=0; j<keymap[i].size(); j++) {
            int index = keymap[i][j] - 'A';
            
            if(alpha[index]<0 || j+1<alpha[index])
                alpha[index] = j + 1;
        }
    }
    
    for(int i=0; i<targets.size(); i++) {
        int temp = 0;
        
        for(int j=0; j<targets[i].size(); j++) {
            int index = targets[i][j] - 'A';
            
            if(alpha[index] < 0) {
                temp = -1;
                break;
            }
            
            temp += alpha[index];
        }
        
        answer.push_back(temp);
    }
    
    return answer;
}