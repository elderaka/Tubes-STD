#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "DLL.h"
#include "enemy.h"
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
void fight(enemy enemies[]);
void run();
void moveAttack();

void moveDefence();
void initiateTop();


#endif // MENU_H_INCLUDED
