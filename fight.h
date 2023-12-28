#ifndef FIGHT_H_INCLUDED
#define FIGHT_H_INCLUDED
#include "DLL.h"
#include "enemy.h"
#include "player.h"

struct entity{
    bool isPlayer = false;
    int no;
    player Player;
    enemy Enemy;
    int actionValue;
};
typedef struct elementEntity *entityAddress;

struct elementEntity{
    entity info;
    entityAddress prev;
    entityAddress next;
};

struct entityList{
    entityAddress first;
    entityAddress last;
};

typedef struct ElmFQueue *Faddress;

struct ElmFQueue{
    entity info;
    Faddress next;
};
struct FQueue{
    Faddress head;
    Faddress tail;
    int     Size;
};

extern FQueue fqueue;
#include "main.h"
void createFQueue(FQueue &S);
void clearFQueue(FQueue &S);
Faddress createFElm(entity x);
bool isFEmpty(FQueue S);
void EnFQueue(FQueue &S, entity x);
entity DeFQueue(FQueue &S);
void showFQueue(FQueue &S);
entity reFQueue(FQueue &S, entityList eL);
void removeEntityFromQueue(FQueue &S, entity P);
void createEntityList(entityList &L);
bool isEntityEmpty(entityList L);
entityAddress createNewEntityElement(entity x);
void addEntity(entityList &L,entityAddress p);
void removeEntity(entityList &L, entityAddress p);
entityAddress findEntity(entityList L, int no);
void showEntity(entityList L);

void initiateFight(FQueue &S,entityList &eL,enemyList enemies);

#endif // FIGHT_H_INCLUDED
