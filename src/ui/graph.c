#include <stdio.h>

extern double* get_history(void);
extern int get_history_size(void);

void draw_graph() {
    double *h = get_history();
    int size = get_history_size();

    printf("\nCPU History:\n");

    for (int level = 9; level >= 0; level--) {
        printf("%2d%% | ", level * 10);

        for (int i = 0; i < size; i++) {
            if (h[i] >= level * 10)
                printf("█");
            else
                printf(" ");
        }

        printf("\n");
    }

    printf("     +------------------------------\n");
}
