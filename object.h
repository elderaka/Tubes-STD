#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED
#include "DLL.h"

struct object{
    string name;
    string desc;
    bool isConsumable;
    bool isEquipable;
    string armor;
    bool isHealing;
    bool isBuff;
    int dmg; //ke musuh semisal throwable ke enemy
    int heal; //semisal heal pot
    string buffStat;
    int buff; // semisal buff dmg ato def
};
typedef struct elementObject *objectAddress;

struct elementObject{
    object info;
    objectAddress prev;
    objectAddress next;
};

struct objectList{
    objectAddress first;
    objectAddress last;
};

void createObjectList(objectList &L);
bool isObjectEmpty(objectList L);
objectAddress createNewObjectElement(object x);
void addObject(objectList &L,objectAddress p);
objectAddress findObject(objectList L, string name);
void showObject(objectList L);

#endif // OBJECT_H_INCLUDED
