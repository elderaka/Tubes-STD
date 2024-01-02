#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED
#include "DLL.h"

struct object{
    string name;
    string desc;
    bool isArtefact;
    bool isConsumable;
    bool isEquipable;
    bool isHealing;
    bool isBuff;
    string armorType;
    int duration;
    string bonusStat[4];
    int bonus[4];
    int heal;
    string buffStat;
    int buff;
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
