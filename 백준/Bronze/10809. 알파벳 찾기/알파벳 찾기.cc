#include <cstdio>

int main() {
    char c[101];
    int array[26];
    
    scanf("%s", c);
    for(int i=0; i<26; i++) array[i] = -1;
    
    for(int i=0; c[i]; i++)
        if(array[c[i]-'a'] == -1)
            array[c[i]-'a'] = i;
    
    for(int i=0; i<26; i++) printf("%d ", array[i]);
    printf("\n");
    
    return 0;
}