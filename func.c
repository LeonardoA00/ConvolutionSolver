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
