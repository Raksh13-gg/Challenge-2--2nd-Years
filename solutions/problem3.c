#include <stdio.h>

int simulate(long long x) {
    char state[10] = "START";

    while (1) {
        if (state[0] == 'S') {   // START
            if (x % 2 == 0) {
                x = x / 2;
                // state = EVEN
                state[0] = 'E';
            } else {
                x = 3 * x + 1;
                // state = ODD
                state[0] = 'O';
            }
        }
        else if (state[0] == 'E') {   // EVEN
            if (x == 1) {
                // DONE
                return 1;
            } else {
                x = x - 1;
                // stay in EVEN (same as python's: # ... other transitions)
            }
        }
        else if (state[0] == 'O') {   // ODD
            // python does not specify other transitions
            // but it loops back to START through simulate
            state[0] = 'S';
        }
    }
}

int main() {
    FILE *f = fopen("../inputs/states.txt", "r");
    if (!f) {
        printf("File error\n");
        return 1;
    }

    long long x;
    int count = 0;

    while (fscanf(f, "%lld", &x) == 1) {
        if (simulate(x)) {
            count++;
        }
    }

    fclose(f);

    printf("%d", count);
    return 0;
}





