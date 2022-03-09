#include "cli_engine.h"
#include "func.h"

int main() {
    cli_test();
    int val[10] = {1, 2, 3, 4, 5, 6, 5, 4, 3, 2};
    FUNC* f = func(val, -2, 7);
    plot(f);
    return 1;
}