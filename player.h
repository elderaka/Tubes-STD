#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "DLL.h"
#include "inventory.h"
#include "skill.h"

struct player{
    string name;
    string buffs; //current applied buffs -1 tiap turn
    string Class; //display current class
    int health; //100
    int stamina; //50
    int xp; //Lv up mechanic w msih bingung, nnt escalate ato kg(?)
    int defaultAttack; // 25, buat multiplier ama skill
    int defaultDefence; // 25, buat multiplier kuranging dmg dr musuh terima
};
typedef struct elementPlayer *playerAddress;

struct elementPlayer{
    player info;
    playerAddress prev;
    playerAddress next;
    inventoryList inventory;
    skillTree skill;
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
