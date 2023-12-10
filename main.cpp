#include "main.h"

int main()
{
    playerList PL;
    objectList OL;
    player Player;
    object Object;
    playerAddress adrPlayer;
    objectAddress adrObject;
    createPlayerList(PL);

    initiateObjects(OL);


    cout << "Masukkan nama karakter anda:" << endl;
    cin >> Player.name;
    adrPlayer = createNewPlayerElement(Player);
    addPlayer(PL,adrPlayer);
    cout << "Berikut adalah item starter yang tersedia:" << endl;
    showObject(OL);
    cout << "Pilih salah satu" << endl;
    cin >> Object.name;
    while(findObject(OL,Object.name) == NULL){
        cout << "Item tidak tersedia, Pilih salah satu" << endl;
        cin >> Object.name;
    }
    addObjectToPlayer(PL,OL,Player.name,Object.name);
    cout << "Berikut adalah data karakter anda:" << endl;
    showPlayer(PL);
    cout << "Item Anda:" << endl;
    showInventory(inventory(adrPlayer));

    return 0;
}
