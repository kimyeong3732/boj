#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    vector<bool> alpha;
    
    for(int i=0; i<26; i++)
        alpha.push_back(false);
    
    for(int i=0; i<skip.size(); i++)
        alpha[skip[i]-'a'] = true;
    
    for(int i=0; i<s.size(); i++) {
        int temp = s[i] - 'a';
        
        for(int j=0; j<index; j++) {
            temp++;
            
            if(temp >= 26)
                temp -= 26;
            
            while(alpha[temp]) {
                temp++;
                
                if(temp >= 26)
                    temp -= 26;
            }
        }
        
        char input = temp + 'a';
        
        answer += input;
    }
    
    return answer;
}