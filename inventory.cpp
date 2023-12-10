#include "inventory.h"
void createInventoryList(inventoryList &L){
    first(L) = NULL;
    last(L) = NULL;
}
bool isInventoryEmpty(inventoryList L){
    return first(L) == NULL;
}
inventoryAddress createNewInventoryElement(objectAddress x){
    inventoryAddress p = new elementInventory;
    object(p) = x;
    next(p) = NULL;
    prev(p) = NULL;
    return p;
}
void insertLastInventory(inventoryList &L, inventoryAddress p){
    if (isInventoryEmpty(L)){
        first(L) = p;
        last(L) = p;
    }
    else{
        next(last(L)) = p;
        prev(p) = last(L);
        last(L) = p;
    }
}
inventoryAddress findObjectinInventory(inventoryList L,string name){
    inventoryAddress prec = first(L);
    while(prec != NULL){
        if(info(object(prec)).name == name){
            return prec;
        }
    }
    return NULL;
}
void showInventory(inventoryList L){
    inventoryAddress p = first(L);
    while(p != NULL){
        cout << info(object(p)).name << endl;
        p = next(p);
    }
    cout << endl;
}
