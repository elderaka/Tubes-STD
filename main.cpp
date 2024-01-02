#include "main.h"

int main()
{
    initiateSkillAndClass(ST,CT);
    initiatePlayer(PL);
    initiateEnemy(EL);
    initiateObjects(OL);

    //enemy enemies[] = {info(first(EL)),info(next(first(EL))),info(last(EL))};
    //fight(enemies);
    initiateMenu();
    do{
        initiateTop();
    }while(!isMenuEmpty(Menu));
    cout << "\nTerima kasih telah bermain";
    return 0;
}
