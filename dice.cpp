#include "dice.h"

int roll(){
    srand(time(0));
    return rand() % 20;
}
float multiplier(int start, int end){
    srand(time(0));
    return (float)(start + (rand() % (end-start)))/100;
}
int flipcoin(){
    srand(time(0));
    return rand() % 2;
}
