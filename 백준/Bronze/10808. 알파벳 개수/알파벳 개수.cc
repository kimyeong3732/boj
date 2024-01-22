#include <cstdio>

int main() {
    char s[101];
    int result[26] = { 0 };
    
    scanf("%s", s);
    
    for(int i=0; s[i]; i++) {
        result[s[i]-'a']++;
    }
    
    for(int i=0; i<26; i++)
        printf("%d ", result[i]);
    printf("\n");
    
    return 0;
}