#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    int day = startday;
    bool check[1000];
    vector<int> destiny;
    
    for(int i=0; i<schedules.size(); i++) {
        int temph = schedules[i] / 100;
        int tempm = schedules[i] % 100;
        
        tempm += 10;
        
        if(tempm >= 60) {
            tempm -= 60;
            temph++;
        }
        
        destiny.push_back(temph*100 + tempm);
        
        check[i] = true;
    }
    
    for(int i=0; i<7; i++) {
        if(day < 6)
            for(int j=0; j<destiny.size(); j++)
                if(timelogs[j][i] > destiny[j])
                    check[j] = false;
        
        day++;
        
        if(day == 8)
            day = 1;
    }
    
    for(int i=0; i<destiny.size(); i++)
        if(check[i])
            answer++;
    
    return answer;
}