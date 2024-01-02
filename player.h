#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "DLL.h"
#include "inventory.h"
#include "skill.h"
#include "Class.h"
struct player{
    string name;
    string buffs; //current applied buffs -1 tiap turn
    string Class; //display current class
    bool pickArtifact = false;
    int artifact;
    bool isDead = false;
    string weapon;
    string helmet;
    string chestplate;
    string legplate;
    string charm;
    bool isFinished = false;
    //int position[2] = [0,0];
    float health = 100; //100
    float currentHealth;
    int coin = 100;
    int stamina = 50; //50
    int currentStamina;
    int exp = 0; //Lv up mechanic w msih bingung, nnt escalate ato kg(?)
    int level = 1;
    int nextLevel = 10;
    float defaultAttack = 10; // 25, buat multiplier ama skill
    float defaultDefence = 10; // 25, buat multiplier kuranging dmg dr musuh terima
    float speed = 10;
    int critChance = 2;
};
typedef struct elementPlayer *playerAddress;

struct elementPlayer{
    player info;
    playerAddress prev;
    playerAddress next;
    inventoryList inventory;
    skillList offensive;
    skillList defensive;
    classAddress Class;
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
void showPlayerInfo(player Player);
int nextLevel(player Player);
void tierUp(player Player);

#endif // PLAYER_H_INCLUDED
