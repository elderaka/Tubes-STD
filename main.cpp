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

    Player.name = "Raka";
    adrPlayer = createNewPlayerElement(Player);
    addPlayer(PL,adrPlayer);
    cout << "Nama2 Pemain:" << endl;
    showPlayer(PL);
    cout << "Object yang tersedia:" << endl;
    showObject(OL);
    cout << "Item pemain:" << endl;
    addObjectToPlayer(PL,OL,"Raka","Stone");
    addObjectToPlayer(PL,OL,"Raka","Stone");
    addObjectToPlayer(PL,OL,"Raka","Stone");
    showInventory(inventory(adrPlayer));

    return 0;
}
