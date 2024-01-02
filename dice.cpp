#include "dice.h"
#include <cmath>
#include <string>
#include <iomanip>
#include <time.h>
int roll(){
    srand(time(0));
    return rand() % 20;
}
int rollHundred(){
    srand(time(0));
    return rand() % 100;
}
float multiplier(int start, int end){
    srand(time(0));
    return (float)(start + (rand() % (end-start)))/100;
}
int flipcoin(){
    srand(time(0));
    return rand() % 2;
}
