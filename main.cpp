#include "main.h"

int main()
{
    initiateObjects(OL);
    initiateSkillAndClass(ST,CT);
    initiatePlayer(PL);
    initiateMenu();
    do{
        initiateTop();
    }while(!isMenuEmpty(Menu));
    cout << "\nTerima kasih telah bermain";
    return 0;
}
