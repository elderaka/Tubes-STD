#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include "DLL.h"
struct enemy{
    string name;
    float health = 100; //100
    float currentHealth;
    int xp = 0; //Lv up mechanic w msih bingung, nnt escalate ato kg(?)
    int coin = 0;
    float defaultAttack = 10; // 25, buat multiplier ama skill
    float defaultDefence = 10; // 25, buat multiplier kuranging dmg dr musuh terima
    float speed = 10;
    string basicName;
    string skillName;
    bool skillDamaging;
    float skillMultiplier;
    int skillHeal;
    string skillStatus;
    float skillChance;
    string itemDrop;
    float dropChance;
};
typedef struct elementEnemy *enemyAddress;

struct elementEnemy{
    enemy info;
    enemyAddress prev;
    enemyAddress next;
};

struct enemyList{
    enemyAddress first;
    enemyAddress last;
};

void createEnemyList(enemyList &L);
bool isEnemyEmpty(enemyList L);
enemyAddress createNewEnemyElement(enemy x);
void addEnemy(enemyList &L,enemyAddress p);
void deleteEnemy(enemyList &L,string name);
enemyAddress findEnemy(enemyList L, string name);
void showEnemy(enemyList L);
void showEnemyInfo(enemy Enemy);


#endif // ENEMY_H_INCLUDED
