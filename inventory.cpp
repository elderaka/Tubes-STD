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
void removeObject(inventoryList &IL,objectList &OL,string name){
    objectAddress P = findObject(OL,name);
    inventoryAddress Q = first(IL);
    while(Q != NULL && object(Q) != P){
        Q = next(Q);
    }
    if(Q != NULL){
        inventoryAddress prec = prev(Q);
        if(Q == first(IL)){
            first(IL) = next(Q);
        }else if (Q == last(IL)){
            last(IL) = prev(Q);
        }else{
            next(prec) = next(Q);
            if(next(prec) != NULL){
                prev(next(Q)) = prec;
            }
            next(Q) = NULL;
            prev(Q) = NULL;
        }
    }
}
void showInventory(inventoryList L){
    inventoryAddress p = first(L);
    while(p != NULL){
        cout << info(object(p)).name << endl;
        p = next(p);
    }
    cout << endl;
}
