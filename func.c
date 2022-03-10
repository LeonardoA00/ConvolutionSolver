#include "func.h"

FUNC* func(int values[], int lowerbound, int upperbound) {
    FUNC* fpointer = (FUNC*)malloc(sizeof(FUNC));
    fpointer->upperbound = upperbound;
    fpointer->lowerbound = lowerbound;
    fpointer->n_values = upperbound - lowerbound + 1;
    int* vpointer = (int*)malloc(sizeof(int) * fpointer->n_values);
    fpointer->values = vpointer;

    for(int i = 0; i < fpointer->n_values; i++)
        vpointer[i] = values[i];
    
    return fpointer;
}


int findmax(FUNC* f) {
    int max = *f->values;
    for(int i = 1; i < f->n_values; i++)
        if(f->values[i] > max)
            max = f->values[i];
    return max;
}

int findmin(FUNC* f) {
    int min = *f->values;
    for(int i = 1; i < f->n_values; i++)
        if(f->values[i] < min)
            min = f->values[i];
    return min;
}

FUNC* conv(FUNC* x, FUNC* h) {
    int r[x->n_values + h->n_values - 1];
    
    int negh_lowerbound = -(h->upperbound);
    int negh_upperbound = -(h->lowerbound);

    int htox_dist = x->lowerbound - negh_upperbound;
    for(int i = 0; i < x->n_values + h->n_values - 1; i++) {
        r[i] = 0;
        for(int m = 0; m <= i; m++) {
            r[i] += (m < x->n_values && (i-m) < h->n_values) ? h->values[i - m] * x->values[m] : 0;
        }
    }

    return func(r, htox_dist, htox_dist + x->n_values + h->n_values - 2);
}

void debug(FUNC* f) {
    printf("[%d %d] : %d\n", f->lowerbound, f->upperbound, f->n_values);
    for(int i = 0; i < f->n_values; i++) printf("%d ", f->values[i]);
    printf("\n");
}