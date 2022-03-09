#ifndef _FUNC_H_
#define _FUNC_H_

    #include <stdlib.h>
    
    /*
    * - values contains FUNC(n)
    * - lowerbound is the lowest non 0 n 
    * - upperbound is the upper non 0 n
    * - n_values is calculated as upperbound - lowerbound + 1
    */

    typedef struct FUNCT_STRUCT {
        int* values;
        int lowerbound;
        int upperbound;
        int n_values;
    } FUNC;

    FUNC* func(int values[], int lowerbound, int upperbound);

    int findmax(FUNC* f);
    int findmin(FUNC* f);



#endif