#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "DLL.h"
#include "enemy.h"
#include "skill.h"
struct menu{
    string name;
};

struct menuStack{
    int info[100];
    int top;
};


#include "main.h"
void createMenuStack(menuStack &S);
bool isMenuEmpty(menuStack S);
void pushMenu(menuStack &S, int x);
void popMenu(menuStack &S);




void splashScreen();
void introduction();

void explore();
void encounter(int id);
void stats();

void checkInventory();
void interactorTalk();
void shop();
void fight(enemyList enemies);
void run();
void moveAttack();


void moveDefence();

void checkMenu();
void showAllPlayer();
void showAllObject();
void showAllClass();

void findPlayerData();
void findItemData();
void findClassData();
void findSkillData();
void showAllPlayerInventory();
void showAllPlayerClass();
void showPlayerInventory();
void showPlayerClass();
void showPlayerInventory();
void showObjectByPlayer();
void showClassByPlayer();
void deletePlayerData();
void deleteObjectData();
void deleteClassData();
void deleteObjectByPlayer();
void deleteSkillByPlayer();
void showMostItem();
void showMostClass();
void showTopThree();
void changePlayerData();
void changeObjectData();
void changeClassData();
void changeSkillData();

void initiateTop();



#endif // MENU_H_INCLUDED
