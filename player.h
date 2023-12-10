#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "DLL.h"
#include "inventory.h"
#include "skill.h"

struct player{
    string name;
};
typedef struct elementPlayer *playerAddress;

struct elementPlayer{
    player info;
    playerAddress prev;
    playerAddress next;
    inventoryList inventory;
    skillList skill;
};

struct playerList{
    playerAddress first;
    playerAddress last;
};

void createPlayerList(playerList &L);
bool isPlayerEmpty(playerList L);
playerAddress createNewPlayerElement(player x);
void addPlayer(playerList &L,playerAddress p);
void deletePlayer(playerList &L,string name);
playerAddress findPlayer(playerList L, string name);
void showPlayer(playerList L);



#endif // PLAYER_H_INCLUDED
