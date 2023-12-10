#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "DLL.h"
#include "inventory.h"
struct player{
    string name;
};
typedef struct elementPlayer *playerAddress;

struct elementPlayer{
    player info;
    playerAddress prev;
    playerAddress next;
    inventoryList inventory;

};

struct playerList{
    playerAddress first;
    playerAddress last;
};

void createPlayerList(playerList &L);
bool isPlayerEmpty(playerList L);
playerAddress createNewPlayerElement(player x);
void addPlayer(playerList &L,playerAddress p);
playerAddress findPlayer(playerList L, string name);
void showPlayer(playerList L);



#endif // PLAYER_H_INCLUDED
