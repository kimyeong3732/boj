#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    
    int i1=0, i2=0;
    
    for(int i=0; i<goal.size(); i++) {
        if(i1<cards1.size() && cards1[i1]==goal[i]) {
            i1++;
        }
        
        else if(i2<cards2.size() && cards2[i2]==goal[i]) {
            i2++;
        }
        
        else {
            answer = "No";
            break;
        }
    }
    
    return answer;
}