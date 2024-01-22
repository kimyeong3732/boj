#include <cstdio>

int main() {
    int max = 0, multi = 1, index;
    char c[1000001];
    int alp[26];
    
    for(int i=0; i<26; i++) alp[i] = 0;
    
    scanf("%s", c);
    
    for(int i=0; c[i]; i++) {
        if(c[i] < 'a') alp[c[i] - 'A'] += 1;
        else alp[c[i] - 'a'] += 1;
    }
    
    for(int i=0; i<26; i++) {
        if(max == alp[i]) multi = 1;
        else if(max < alp[i]) {
            max = alp[i];
            index = i;
            multi = 0;
        }
    }
    if(multi) printf("?\n");
    else printf("%c\n", index+'A');
    
    return 0;
}