#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED
#include "DLL.h"

struct object{
    string name;
    string desc;
    string type; //throwable ato equipable
    int jumlah; //self explanatory
    int dmg; //ke musuh semisal throwable ke enemy
    int heal; //semisal heal pot
    int buff; // semisal buff dmg ato def
    int duration; //semisal buff ato overtime healing

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
