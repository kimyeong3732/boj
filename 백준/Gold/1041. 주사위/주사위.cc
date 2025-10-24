#include <iostream>

using namespace std;

int main() {
    long long n;
    long long dice[6];
    int d2[12][2] = {{0, 1}, {0, 2}, {0, 3}, {0, 4},
                     {1, 2}, {1, 3}, {1, 5}, {2, 4},
                     {2, 5}, {3, 4}, {3, 5}, {4, 5}};
    
    int d3[8][3] = {{0, 1, 2}, {0, 1, 3}, {0, 2, 4}, {0, 3, 4},
                    {1, 2, 5}, {1, 3, 5}, {2, 4, 5}, {3, 4, 5}};
    
    cin >> n;
    
    for(int i=0; i<6; i++)
        cin >> dice[i];
    
    long long dm = 50;
    long long d2m = 100;
    long long d3m = 150;
    
    for(int i=0; i<6; i++)
        if(dm > dice[i])
            dm = dice[i];
    
    for(int i=0; i<12; i++) {
        long long temp = 0;
        
        for(int j=0; j<2; j++)
            temp += dice[d2[i][j]];
        
        if(d2m > temp)
            d2m = temp;
    }
    
    for(int i=0; i<8; i++) {
        long long temp = 0;
        
        for(int j=0; j<3; j++)
            temp += dice[d3[i][j]];
        
        if(d3m > temp)
            d3m = temp;
    }
    
    if(n == 1) {
        long long r = 0;
        long long tm = 0;
        
        for(int i=0; i<6; i++) {
            r += dice[i];
            
            if(tm < dice[i])
                tm = dice[i];
        }
        
        r -= tm;
        
        cout << r;
    }
    else {
        long long r = 0;
        
        r += dm * (n - 1) * (n - 2) * 4 + dm * (n - 2) * (n - 2);
        
        r += d2m * (n - 1) * 4 + d2m * (n - 2) * 4;
        
        r += d3m * 4;
        
        cout << r;
    }
    
    return 0;
}