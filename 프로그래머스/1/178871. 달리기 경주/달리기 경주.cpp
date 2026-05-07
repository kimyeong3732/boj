#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    for(int i=0; i<players.size(); i++)
        answer.push_back(players[i]);
    
    map<string, int> pm;
    
    for(int i=0; i<players.size(); i++)
        pm.insert({players[i], i});
    
    for(int i=0; i<callings.size(); i++) {
        string st = callings[i];
        int it = pm[st];
        
        pm[answer[it-1]] = it;
        pm[st] = it - 1;
        
        answer[it] = answer[it-1];
        answer[it-1] = st;
    }
    
    return answer;
}