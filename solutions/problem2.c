#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isVowel(char c) {
    c = tolower(c);
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

int main() {
   FILE *f = fopen("../inputs/input2.txt", "r");

    if (!f) { printf("File error\n"); return 1; }

    char s[500], rev[500], filtered[500];
    fgets(s, sizeof(s), f);
    fclose(f);

    int n = strlen(s);
    if (s[n-1]=='\n') s[n-1]='\0';

    n = strlen(s);

    // reverse
    for (int i = 0; i < n; i++)
        rev[i] = s[n - 1 - i];
    rev[n] = '\0';

    // remove every 3rd char
    int k = 0;
    for (int i = 0; i < n; i++)
        if ((i + 1) % 3 != 0)  // keep
            filtered[k++] = rev[i];

    filtered[k] = '\0';

    // shift ASCII +2
    for (int i = 0; i < k; i++)
        filtered[i] += 2;

    // count vowels
    int countV = 0;
    for (int i = 0; i < k; i++)
        if (isVowel(filtered[i]))
            countV++;

    printf("%d", countV);
    return 0;
}



