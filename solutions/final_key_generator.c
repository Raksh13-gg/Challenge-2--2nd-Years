#include <stdio.h>

int main() {
    int clue1 = 385;
    int clue2 = 4;
    int clue3 = 4;

    // Convert clue1 to hexadecimal
    char hex_clue1[20];
    sprintf(hex_clue1, "%x", clue1); // lowercase hex, like Python's hex()

    // Prepare clue2 repeated clue3 times
    char clue2_repeated[20];
    int k = 0;
    for (int i = 0; i < clue3; i++) {
        clue2_repeated[k++] = '0' + clue2; // convert int to char
    }
    clue2_repeated[k] = '\0';

    // Combine into final key
    char final_key[50];
    sprintf(final_key, "%s-%s", hex_clue1, clue2_repeated);

    // Write to final_key.txt
    FILE *fp = fopen("final_key.txt", "w");
    if (fp == NULL) {
        printf("Error: Could not create file.\n");
        return 1;
    }
    fprintf(fp, "%s", final_key);
    fclose(fp);

    printf("Final Key: %s\n", final_key); // Optional print
    return 0;
}

