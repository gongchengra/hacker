#include <stdlib.h>
#include <time.h>
#include "num.h"
Number randNum() {
    srand(time(NULL));
    return rand();
}
