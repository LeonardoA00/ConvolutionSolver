#include "cli_engine.h"
#include "func.h"

int main() {
    int x[5] = {1, 1, 1, 1, 1};
    int h[2] = {1, -1};
    FUNC* fx = func(x, 0, 4);
    FUNC* fh = func(h, 0, 1);
    plot(fx);
    plot(fh);
    FUNC* fc = conv(fx, fh);
    plot(fc);

    debug(fx);
    debug(fh);
    debug(fc);
    return 0;
}