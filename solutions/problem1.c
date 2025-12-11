#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_ROWS 200
#define MAX_COLS 1024

static void strip_crlf(char *s) {
    int n = strlen(s);
    while (n > 0 && (s[n-1] == '\n' || s[n-1] == '\r')) { s[--n] = '\0'; }
}
int main(void) {
    FILE *gf = fopen("..\\inputs\\grid.txt", "r");
    FILE *df = fopen("..\\inputs\\directions.txt", "r");
    if (!gf || !df) {
        fprintf(stderr, "Error: inputs/grid.txt or inputs/directions.txt not found\n");
        return 1;
    }
    char grid[MAX_ROWS][MAX_COLS];
    int rowlen[MAX_ROWS];
    int rows = 0;

    while (rows < MAX_ROWS && fgets(grid[rows], MAX_COLS, gf)) {
        strip_crlf(grid[rows]);
        if (grid[rows][0] == '\0') continue; 
        rowlen[rows] = (int)strlen(grid[rows]);
        rows++;
    }
    fclose(gf);
    char dirs[MAX_ROWS];
    int dcount = 0;
    int c;
    while ((c = fgetc(df)) != EOF && dcount < MAX_ROWS) {
        if (toupper(c) == 'L' || toupper(c) == 'R') {
            dirs[dcount++] = (char)toupper(c);
        }
    }
    fclose(df);
    for (int i = 0; i < rows; ++i) {
        int cols = rowlen[i];
        if (cols <= 1) continue;
        char d = (i < dcount) ? dirs[i] : '\0';
        if (d == 'R') {
            char last = grid[i][cols-1];
            for (int j = cols - 1; j > 0; --j) grid[i][j] = grid[i][j-1];
            grid[i][0] = last;
        } else if (d == 'L') {
            char first = grid[i][0];
            for (int j = 0; j < cols - 1; ++j) grid[i][j] = grid[i][j+1];
            grid[i][cols-1] = first;
        }
    }
    int middle = rows / 2; 
    int sum = 0;
    for (int j = 0; j < rowlen[middle]; ++j) {
        unsigned char ch = (unsigned char)grid[middle][j];
        sum += (int)ch;
    }
    printf("Clue 1 = %d\n", sum);
    return 0;
}
