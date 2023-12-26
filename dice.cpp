#include "dice.h"

int roll(){
    srand(time(0));
    return rand() % 20;
}
