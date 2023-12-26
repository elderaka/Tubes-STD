#ifndef INVENTORY_H_INCLUDED
#define INVENTORY_H_INCLUDED
#include "DLL.h"
#include "object.h"

typedef struct elementInventory *inventoryAddress;

struct elementInventory{
    objectAddress object;
    inventoryAddress next;
    inventoryAddress prev;
};

struct inventoryList{
    inventoryAddress first;
    inventoryAddress last;
};

void createInventoryList(inventoryList &L);
bool isInventoryEmpty(inventoryList L);
inventoryAddress createNewInventoryElement(objectAddress x);
void insertLastInventory(inventoryList &L, inventoryAddress p);
void removeObject(inventoryList &IL,objectList &OL,string name);
void showInventory(inventoryList L);
#endif // INVENTORY_H_INCLUDED
