#include "cli_engine.h"

void cli_test() {
    printf("Hello World\n");
}

void plot(FUNC* f) {
    int maxF = findmax(f);
    int minF = findmin(f);

    printf("\n");

    // UpperArrow
    for(int i = f->lowerbound; i <= 0; i++) {
        if(i < 0) printf("  ");
        else printf("^"); // (i == 0)
    }
    printf("\n");

    // First bar | of y axis
    for(int i = f->lowerbound; i <= 0; i++) {
        if(i < 0) printf("  ");
        else printf("|"); // (i == 0)
    }
    printf("\n");

    // Plot stars
    for(int i = maxF; i >= minF - 1; i--) {
        if(i != 0) {
            for(int j = 0; j < f->n_values; j++) {
                if(f->values[j] == i) printf("* ");
                else if(j == -f->lowerbound) printf("| ");
                else printf("  ");
            }
            printf("  %d\n", i);
        }
        if(i == 0) {
            for(int j = 0; j < f->n_values; j++) {
                if(f->values[j] == i) printf("* ");
                else printf("- ");
            }
            printf(">\n");
        }
    }

}