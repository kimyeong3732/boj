#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int w=park[0].size(), h=park.size();
    
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(park[i][j] == 'S') {
                answer.push_back(i);
                answer.push_back(j);
                break;
            }
        }
    }
    
    for(int i=0; i<routes.size(); i++) {
        int x=answer[1], y=answer[0];
        int dx=0, dy=0;
        
        switch(routes[i][0]) {
            case 'N':
                dy = -1;
                break;
            case 'S':
                dy = 1;
                break;
            case 'W':
                dx = -1;
                break;
            case 'E':
                dx = 1;
                break;
            default:
                break;
        }
        
        int n = routes[i][2] - '0';
        bool state = true;
        
        for(int j=0; j<n; j++) {
            x += dx;
            y += dy;
            
            if(x<0 || x>=w || y<0 || y>=h || park[y][x]=='X') {
                state = false;
                break;
            }
        }
        
        if(state) {
            answer[1] = x;
            answer[0] = y;
        }
    }
    
    return answer;
}