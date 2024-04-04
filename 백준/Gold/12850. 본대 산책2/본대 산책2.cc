#include <iostream>

using namespace std;

long long edges[8][8] = {{0, 1, 1, 0, 0, 0, 0, 0},
                   {1, 0, 1, 1, 0, 0, 0, 0},
                   {1, 1, 0, 1, 1, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1, 0},
                   {0, 0, 0, 1, 1, 0, 0, 1},
                   {0, 0, 0, 0, 1, 0, 0, 1},
                   {0, 0, 0, 0, 0, 1, 1, 0}};

void my_copy(long long matrix[8][8], long long result[8][8]) {
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            result[i][j] = matrix[i][j];
        }
    }
}

void multiply(long long a[8][8], long long b[8][8], long long result[8][8]) {
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            long long sum = 0;
            for(int k=0; k<8; k++) {
                sum += (a[i][k] * b[k][j]) % 1000000007;
                sum %= 1000000007;
            }
            
            result[i][j] = sum;
        }
    }
}

void pow_matrix(long long matrix[8][8], int num, long long result[8][8]) {
    if(num == 1) {
        my_copy(matrix, result);
        return;
    }
    
    long long temp[8][8];
    
    if(num%2 == 0) {
        multiply(matrix, matrix, temp);
        pow_matrix(temp, num/2, result);
        return;
    }
    
    pow_matrix(matrix, num-1, temp);
    multiply(temp, matrix, result);
}

int main() {
    int num;
    
    cin >> num;
    
    long long result[8][8];
    pow_matrix(edges, num, result);
    
    cout << result[0][0];
    
    return 0;
}