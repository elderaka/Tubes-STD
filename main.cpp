#include "main.h"

int main()
{
    initiateObjects(OL);
    initiateSkillAndClass(ST,CT);
    initiatePlayer(PL);
    initiateEnemy(EL);
    enemy enemies[] = {info(first(EL)),info(next(first(EL))),info(last(EL))};
    fight(enemies);
    //for(int i = 0; i < 10;i++){
    //    reFQueue(fqueue,eL);
    //}
    initiateMenu();
    do{
        initiateTop();
    }while(!isMenuEmpty(Menu));
    cout << "\nTerima kasih telah bermain";
    return 0;
}
